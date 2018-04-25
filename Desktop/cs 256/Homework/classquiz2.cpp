
#include "stdafx.h"
#include "Circle.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
	double cir;
	cout << "Enter the radius of a circle " << endl;
	cin >> cir;
	Circle circle(cir);
	cout << "Circle radius:" << circle.getRadius() << endl;
	cout << "Circle area:" << circle.getArea() << endl;
	cout << "Circle circumference:" << circle.getCircumference() << endl;
	cout << "Circle diameter:" << circle.getDiameter() << endl;
    return 0;
}

