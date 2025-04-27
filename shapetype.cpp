#include "shapetype.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Constructors
shapeType::shapeType() = default;
shapeType::shapeType(lineType a, lineType b, lineType c, lineType d) : a(a), b(b), c(c), d(d) {}

// Uses well known point-distance formula
double shapeType::findDistance(pair<double, double> pA, pair<double, double> pB) {
    return sqrt(pow((pB.first - pA.first), 2.0) + pow((pB.second - pA.second), 2.0));
}

void shapeType::setShapeName(string name) {shapeName = name;}
void shapeType::setLineType(int x, lineType y) {
    switch (x) {
        case 1: a = y; break;
        case 2: b = y; break;
        case 3: c = y; break;
        case 4: d = y; break;
        default: throw invalid_argument("Invalid line index. Must be 1, 2, 3, or 4.");
    }
}
lineType shapeType::getLineType(int x) {
    switch (x) {
        case 1: return a;
        case 2: return b;
        case 3: return c;
        case 4: return d;
        default: throw invalid_argument("Invalid line index. Must be 1, 2, 3, or 4.");
    }   
}
string shapeType::getShapeName() {
    return shapeName;
}

