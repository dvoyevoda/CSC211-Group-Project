#include "linetype.h"
using namespace std;

lineType::lineType(double a, double b, double c) : a(a), b(b), c(c) {}

double lineType::findSlope() {
    if (b != 0) {
        return -a/b;
    } else {
        return 0;
    }
}
bool lineType::isEqual(lineType line) {
    if (a == line.a && b == line.b && c == line.c)
        return true;
    return false;
}
bool lineType::isParallel(lineType line) {
    if (findSlope() == line.findSlope())
        return true;
    return false;
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
    cout << "y = " << findSlope() << "x + " << c << endl;
}
void lineType::printStandardForm() {
    cout << a << "x + " << b << "y = " << c << endl;
}