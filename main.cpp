#include<fstream>
#include<iostream>
#include <vector>

#include "linetype.cpp"
#include "shapetype.cpp"
using namespace std;

int main () {

    // [---------------------- PART 1: ----------------------]

    lineType Line1(3,-3,1);
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
    if ( Line1.isEqual(Line2)) {
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
    cout << endl;

    // [---------------------- PART 2: ----------------------]

    ifstream inFile("data.txt");
    if (!inFile) {
        cout << "Error opening data.txt. Try again.";
        return 1;
    }

    vector<shapeType> Shapes;
    double x, y, z;

    // Reading in four lines from file to each shape while storing each shape in vector.
    while (true) {
        shapeType Shape;
        bool validShape = true;

        for (int i = 1; i <= 4; ++i) {
            if (!(inFile >> x >> y >> z)) {
                validShape = false;
                break;
            }

            lineType Line(x, y, z);
            Shape.setLineType(i, Line);
        }

        if (!validShape) break;
        Shapes.push_back(Shape);
    }

    

    /*  Print lines of each shape

    for (shapeType& shape : Shapes) {
        for (int i = 1; i <= 4; i++) {
            shape.getLineType(i).printStandardForm();
        }
        cout << endl;
    }

    */
    return 0;
}