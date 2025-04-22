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
string lineType::isEqual(lineType line) {
    if (a == line.a && b == line.b && c == line.c)
        return "Both lines are equal.";
    return "The lines are not equal.";
}
string lineType::isParallel(lineType line) {
    if (findSlope() == line.findSlope())
        return "Both lines are parallel.";
    return "The lines are not parallel.";
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

