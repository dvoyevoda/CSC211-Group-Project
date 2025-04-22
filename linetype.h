#pragma once
#include <string>

class lineType {
public:
    lineType(double a = 0, double b = 0, double c = 0);
    double findSlope();
    std::string isEqual(lineType line);
    std::string isParallel(lineType line);
    bool isPerpendicular(lineType line);
    void findIntersection(lineType line);
private:
    double a,b,c;
};