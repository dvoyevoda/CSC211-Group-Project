#pragma once
#include "linetype.h"
#include <string>
#include <utility>

class shapeType {
    public:
        shapeType();
        shapeType(lineType a, lineType b, lineType c, lineType d);

        double findDistance(std::pair<double, double> pA, std::pair<double, double> pB);

        void setShapeName(string name);
        void setLineType(int x, lineType y);
        lineType getLineType(int x);
        string getShapeName();
    private:
        std::string shapeName = "N/A";
        lineType a, b, c, d;
}; 