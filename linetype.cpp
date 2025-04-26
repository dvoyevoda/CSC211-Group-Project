#include "linetype.h"
#include <iostream>
#include <cmath>
using namespace std;

lineType::lineType(double a, double b, double c) : a(a), b(b), c(c) {}

double lineType::findSlope() {
    return b != 0 ? -a / b : NAN;
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
void lineType::findIntersection(lineType line) {
    double slope1 = findSlope(), 
    slope2 = line.findSlope();

    double x = (line.c-c)/(slope1-slope2), 
    y = slope1*x + c;

    cout << "Intersection between both lines: (" << x << ", " << y << ")" << endl;
}

void lineType::printSlopeForm() {
    cout << "y = " << findSlope() << "x + " << c/b << endl;
}
void lineType::printStandardForm() {
    cout << a << "x + " << b << "y = " << c << endl;
}