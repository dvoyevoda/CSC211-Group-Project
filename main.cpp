#include<fstream>
#include<iostream>
#include <vector>

#include "linetype.cpp"
#include "shapetype.cpp"
using namespace std;

int main () {

    cout << "[---------------------- PART 1: ----------------------]\n\n"
        << "Sample lines: \n\n1, 0, 0\n1, 5, 2\n";

    // Example Lines
    lineType Line1(1,0,0);
    lineType Line2(1,5,2);

    // Extra: Print lines in slope & standard form
    cout << "\nLines in Slope Form: \n"; 
    Line1.printSlopeForm(); 
    Line2.printSlopeForm();
    cout << endl;

    cout << "Lines in Standard Form: \n"; 
    Line1.printStandardForm();
    Line2.printStandardForm();
    cout << endl;

    // A: Determinte Slope
    cout << "Line 1 Slope: " << Line1.findSlope() << endl;
    cout << "Line 2 Slope: " << Line2.findSlope() << "\n\n";

    // B: Determinte if two lines are equal
    if ( Line1 == Line2) {
        cout << "Line 1 and Line 2 are equal.\n";
    } else {
        cout << "Line 1 and Line 2 are NOT equal.\n";
    }
    
    // C: Determine if two lines are parallel
    if (Line1.isParallel(Line2)) {
        cout << "Line 1 and Line 2 are parallel.\n";
    } else {
        cout << "Line 1 and Line 2 are NOT parallel.\n";
    }

    // D: Determine if two lines are perpendicular
    if (Line1.isPerpendicular(Line2)) {
        cout << "Line 1 and Line 2 are perpendicular.\n";
    } else {
        cout << "Line 1 and Line 2 are NOT perpendicular.\n";
    }

    // E: If two lines are not parallel, find intersection
    if (!Line1.isParallel(Line2)) {
        Line1.findIntersection(Line2);
    }

    cout << "\n[---------------------- PART 2: ----------------------]\n\n";

    ifstream inFile("Lines.txt");
    if (!inFile) {
        cout << "Error opening data.txt. Try again.";
        return 1;
    }

    vector<shapeType> Shapes;
    double x=1, y=1, z=1;

    // Reading in four lines from file to each shape while storing each shape in vector.
    while (true) {
        shapeType Shape;
        bool validShape = true;

        for (int i = 1; i <= 4; ++i) {
            if (!(inFile >> x >> y >> z)) {
                validShape = false;
                break;
            }
            if (x == 0 && y == 0) {
                cout << "Invalid line in file: a and b cannot both be 0." << endl;
                validShape = false;
                break;
            }
            lineType Line(x, y, z);
            Shape.setLineType(i, Line);
        }
        if (!validShape) break;
        Shapes.push_back(Shape);
    }

    // Loop through array of shapes, determine the shape and set that as shape name.
    for (shapeType& shape : Shapes) {
        lineType line1 = shape.getLineType(1), line2 = shape.getLineType(2), line3 = shape.getLineType(3), line4 = shape.getLineType(4);

        // Edge case if all lines are the same
        if (line1 == line2 && line2 == line3 && line3 == line4) {
            shape.setShapeName("No shape exists.");
            continue;
        }

        // Corners of shape
        pair<double, double> c1 = line1.findIntersection(line3);
        pair<double, double> c2 = line3.findIntersection(line2); 
        pair<double, double> c3 = line2.findIntersection(line4);  
        pair<double, double> c4 = line4.findIntersection(line1); 

        // Find side lengths
        double length1 = shape.findDistance(c1, c2);
        double length2 = shape.findDistance(c2, c3);
        double length3 = shape.findDistance(c3, c4);
        double length4 = shape.findDistance(c4, c1);

        // Check if parallelogram
        if (line1.isParallel(line2) && line3.isParallel(line4)) {

            // Check if approximately equal due to potential floating point error
            if (abs(length1 - length2) < 0.001 && abs(length2 - length3) < 0.001 && abs(length3 - length4) < 0.001) {

                if (line1.isPerpendicular(line3) && line2.isPerpendicular(line4)) {
                    shape.setShapeName("Square");
                } else {
                    shape.setShapeName("Rhombus");
                }
            } else {
                if (line1.isPerpendicular(line3) && line2.isPerpendicular(line4)) {
                    shape.setShapeName("Rectangle");
                } else {
                    shape.setShapeName("Parallelogram");
                }
            }
        
        // Only ONE pair of sides parallel; Trapezoid
        } else if (line1.isParallel(line2) || line3.isParallel(line4)) {

            shape.setShapeName("Trapezoid");
        } else {
            shape.setShapeName("No shape exists.");
        }
    }

    // Print shape types
    int shapeNumber = 1;
    for (shapeType& shape : Shapes) {
        cout << "Shape " << shapeNumber << " is a: " << shape.getShapeName() << endl;
        shapeNumber++;
    }

    cout << endl;

    /* Optional: Print lines from txt
    
    cout << "Lines provided, converted into Slope-Intercept form: \n\n";

    for (shapeType& shape : Shapes) {
        for (int i = 1; i <= 4; i++) {
            shape.getLineType(i).printSlopeForm();
        }
        cout << endl;
    }
    */
    
    return 0;
}