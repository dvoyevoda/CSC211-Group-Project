#include<fstream>
#include<iostream>

#include "linetype.cpp"
using namespace std;

int main () {
    lineType Line1(3,0,1);
    lineType Line2(1,0,2);

    cout << Line1.findSlope() << endl;
    cout << Line2.findSlope() << endl << endl;
    Line1.findIntersection(Line2);
}