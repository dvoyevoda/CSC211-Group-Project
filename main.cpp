#include<fstream>
#include<iostream>

#include "linetype.cpp"
using namespace std;

int main () {
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
}