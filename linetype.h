#pragma once
#include <string>

class lineType {
public:
    lineType(double a = 1, double b = 0, double c = 0);
    double findSlope();
    bool isEqual(lineType line);
    bool isParallel(lineType line);
    bool isPerpendicular(lineType line);
    void findIntersection(lineType line);

    void printSlopeForm();
    void printStandardForm();
private:
    double a,b,c;
};