#include "linetype.h"
#include <iostream>
#include <cmath>
using namespace std;

lineType::lineType(double a, double b, double c) : a(a), b(b), c(c) {
    if (a == 0 && b == 0) {
        throw invalid_argument("Invalid input for line. only a OR b can be 0, not both.");
    }
}
double lineType::findSlope() {
    if (b == 0) {
        return NAN;
    }
    return -a / b;
}
bool lineType::isParallel(lineType& other) {
    if (b == 0 && other.b == 0) return true;
    if (b != 0 && other.b != 0) {
        return fabs(findSlope() - other.findSlope()) < 1e-9;
    }
    return false;
}
bool lineType::isPerpendicular(lineType& other) {
    // Vertical ⟂ horizontal
    if ((b == 0 && other.a == 0) || (a == 0 && other.b == 0)) return true;
    double m1 = findSlope(), m2 = other.findSlope();
    return fabs(m1 * m2 + 1) < 1e-9;
}

// Returns a pair (x,y)
pair<double, double> lineType::findIntersection(lineType& other) {
    if (b == 0 && other.b == 0) {
        return {NAN, NAN};
    } else if (b == 0) {
        double x = -c / a;
        double y = (-other.a * x - other.c) / other.b;
        if (fabs(x) < 1e-9) x = 0;  // (fabs(x) < 1e-9) to turn -0 to 0;
        if (fabs(y) < 1e-9) y = 0;
        return {x, y};
    } else if (other.b == 0) {
        double x = -other.c / other.a;
        double y = (-a * x - c) / b;
        if (fabs(x) < 1e-9) x = 0;
        if (fabs(y) < 1e-9) y = 0;
        return {x, y};
    } else {
        double slope1 = findSlope(), slope2 = other.findSlope();
        if (fabs(slope1 - slope2) < 1e-9) {
            return {NAN, NAN};
        }
        double intercept1 = c / b;
        double intercept2 = other.c / other.b;
        double x = (intercept2 - intercept1) / (slope1 - slope2);
        double y = slope1 * x + intercept1;
        if (fabs(x) < 1e-9) x = 0;
        if (fabs(y) < 1e-9) y = 0;
        return {x, y};
    }
}

void lineType::printSlopeForm() {
    // Vertical line: x = -c/a
    if (b == 0) {
        double x0 = -c / a;
        if (fabs(x0) < 1e-9) x0 = 0;
        cout << "x = " << x0 << endl;
        return;
    }

    double slope = findSlope();
    double intercept = c / b;

    // Horizontal line: y = intercept
    if (a == 0) {
        if (fabs(intercept) < 1e-9) intercept = 0;
        cout << "y = " << intercept << endl;
        return;
    }

    // Clean up near-zero values
    if (fabs(slope) < 1e-9) slope = 0;
    if (fabs(intercept) < 1e-9) intercept = 0;

    // Format as y = mx [±] b
    cout << "y = " << slope << "x";
    if (intercept < 0) {
        cout << " - " << fabs(intercept);
    } else {
        cout << " + " << intercept;
    }
    cout << endl;
}
void lineType::printStandardForm() {
    double A = a, B = b, C = c;
    if (fabs(A) < 1e-9) A = 0; // Handle -0
    if (fabs(B) < 1e-9) B = 0; // Handle -0
    if (fabs(C) < 1e-9) C = 0; // Handle -0

    // Handle vertical lines and if remove coefficients of 1 for cleaner look.
    if (A > 0) {
        if (A == 1) {
            cout << "x";
        } else {
            cout << A << "x";
        }
    }
    if (B > 0) {
        if (B == 1) {
            cout << " + y";
        } else {
            cout << " + " << B << "y";
        }
    }
    cout << " = " << C << endl;
}