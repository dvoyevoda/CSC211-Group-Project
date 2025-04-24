#pragma once
#include "linetype.h"
#include <string>

class shapeType {
    public:
        shapeType();
        shapeType(lineType a, lineType b, lineType c, lineType d);

        void shapeType::setShapeName(string name);
        void setLineType(int x, lineType y);
        lineType getLineType(int x);
    private:
        std::string shapeName = "N/A";
        lineType a, b, c, d;
}; 