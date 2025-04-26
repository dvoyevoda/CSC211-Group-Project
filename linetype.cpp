#include "linetype.h"
#include "point.h" 
#include <iostream>
#include <cmath>
using namespace std;

lineType::lineType(double a, double b, double c) : a(a), b(b), c(c) {
    if (a == 0 && b == 0) {
        throw invalid_argument("Invalid input for line. only a OR b can be 0, not both.");
        
    }
}
double lineType::findSlope() {
    if (b == 0) {
        return NAN;
    }
    return -a / b;
}
bool lineType::isEqual(lineType line) {
    return a == line.a && b == line.b && c == line.c;
}
bool lineType::isParallel(lineType line) {
    return findSlope() == line.findSlope();
}
bool lineType::isPerpendicular(lineType line) {
    return findSlope() * line.findSlope() == -1;
}
void lineType::findIntersection(lineType line, Point& intersection) {  
    if (b == 0 && line.b == 0) {

        intersection.x = NAN;
        intersection.y = NAN;
    } else if (b == 0) {

        double x = -c / a;
        double y = (-line.a * x - line.c) / line.b;
        intersection.x = x;
        intersection.y = y;
    } else if (line.b == 0) {

        double x = -line.c / line.a;
        double y = (-a * x - c) / b;
        intersection.x = x;
        intersection.y = y;
    } else {
        double slope1 = findSlope(), slope2 = line.findSlope();
        if (slope1 == slope2) {

            intersection.x = NAN;
            intersection.y = NAN;
        } else {
            double x = (line.c - c) / (slope1 - slope2);
            double y = slope1 * x + c / b;
            intersection.x = x;
            intersection.y = y;
        }
    }
}


void lineType::printSlopeForm() {
    double slope = findSlope();
    double intercept = c / b;

    if (fabs(slope) < 1e-9) slope = 0;       
    if (fabs(intercept) < 1e-9) intercept = 0; 

    if (isnan(slope)) {
        if (isnan(intercept)) {
            cout << "y = undefined" << endl;
            return;
        }
        cout << "y = " << intercept << endl;
        return;
    } else if (isnan(intercept)) {
        cout << "y = " << slope << endl;
        return;
    }

    cout << "y = " << slope << "x + " << intercept << endl;
}
void lineType::printStandardForm() {
    double A = a, B = b, C = c;
    if (fabs(A) < 1e-9) A = 0; // Handle -0
    if (fabs(B) < 1e-9) B = 0; // Handle -0
    if (fabs(C) < 1e-9) C = 0; // Handle -0
    cout << A << "x + " << B << "y = " << C << endl;
}