#pragma once

class lineType {
public:
    lineType();
    double findSlope();
    bool isEqual();
    bool isParallel();
    bool isPerpendicular();
private:
    double a,b,c;
};