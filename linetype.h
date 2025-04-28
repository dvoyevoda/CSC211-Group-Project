#pragma once
#include <string>
#include <utility>

class lineType {
public:
    lineType(double a = 1, double b = 0, double c = 0);

    double findSlope();
    bool isParallel(lineType& other);
    bool isPerpendicular(lineType& other);
    std::pair<double, double> findIntersection(lineType& other);

    void printSlopeForm();
    void printStandardForm();

    // Overload == operator to compare two lines.
    bool operator==(const lineType& other) const {
    return a == other.a && b == other.b && c == other.c;
}
private:
    double a,b,c;
};