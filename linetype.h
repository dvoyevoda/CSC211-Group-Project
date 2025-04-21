#pragma once

class lineType {
public:
    lineType(double a = 0, double b = 0, double c = 0);
    double findSlope();
    bool isEqual(lineType line);
    bool isParallel(lineType line);
    bool isPerpendicular(lineType line);
private:
    double a,b,c;
};