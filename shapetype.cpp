#include <cmath>
#include <iostream>
#include <string>
#include "point.h"
#include "linetype.h"
using namespace std;



class shapeType {
public:
    shapeType();  // Default constructor
    shapeType(lineType a, lineType b, lineType c, lineType d);  // Parameterized constructor
    void setShapeName(string name);
    void setLineType(int x, lineType y); 
    lineType getLineType(int x);
    string classifyShape();  // Function to classify the shape
    
private:
    string shapeName = "N/A";
    lineType a, b, c, d;
    
    Point getIntersection(lineType l1, lineType l2);
    double distance(Point p1, Point p2);
};

shapeType::shapeType() = default;

shapeType::shapeType(lineType a, lineType b, lineType c, lineType d) : a(a), b(b), c(c), d(d) {}

void shapeType::setShapeName(string name) {
    shapeName = name;
}

void shapeType::setLineType(int x, lineType y) {
    switch (x) {
        case 1: a = y; break;
        case 2: b = y; break;
        case 3: c = y; break;
        case 4: d = y; break;
        default: throw invalid_argument("Invalid line index. Must be 1, 2, 3, or 4.");
    }
}

lineType shapeType::getLineType(int x) {
    switch (x) {
        case 1: return a;
        case 2: return b;
        case 3: return c;
        case 4: return d;
        default: throw invalid_argument("Invalid line index. Must be 1, 2, 3, or 4.");
    }
    
}

// Function to get the intersection point of two lines
Point shapeType::getIntersection(lineType l1, lineType l2) {
    Point p;
    l1.findIntersection(l2, p);
    return p;
}

// Function to calculate distance between two points
double shapeType::distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Function to classify the shape
string shapeType::classifyShape() {
    // Get intersection points of the lines
    Point p1 = getIntersection(a, b);
    Point p2 = getIntersection(b, c);
    Point p3 = getIntersection(c, d);
    Point p4 = getIntersection(d, a);

    // Check for invalid shape (if any of the intersection points is NaN)
    if (isnan(p1.x) || isnan(p2.x) || isnan(p3.x) || isnan(p4.x)) {
        return "Invalid Shape (no closed shape)";
    }

    // Calculate side lengths (distances between the points)
    double side1 = distance(p1, p2);
    double side2 = distance(p2, p3);
    double side3 = distance(p3, p4);
    double side4 = distance(p4, p1);

    // Tolerance for comparing floating-point values
    const double EPS = 0.001;

    bool allSidesEqual = 
        fabs(side1 - side2) < EPS &&
        fabs(side2 - side3) < EPS &&
        fabs(side3 - side4) < EPS;

    bool oppSidesEqual =
        fabs(side1 - side3) < EPS &&
        fabs(side2 - side4) < EPS;

    bool oppSidesParallel = a.isParallel(c) && b.isParallel(d);

    bool allRightAngles =
        a.isPerpendicular(b) &&
        b.isPerpendicular(c) &&
        c.isPerpendicular(d) &&
        d.isPerpendicular(a);

    // Classify shape based on properties
    if (allSidesEqual && allRightAngles) return "Square";
    if (oppSidesEqual && allRightAngles) return "Rectangle";
    if (allSidesEqual && !allRightAngles) return "Rhombus";
    if (oppSidesParallel) return "Parallelogram";
    if (a.isParallel(c) || b.isParallel(d)) return "Trapezoid";

    return "Other Quadrilateral";
}