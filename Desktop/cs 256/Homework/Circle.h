#pragma once

#include <string>
using namespace std;

class Circle {
private:
	double radius;
	double pi=3.14159;

public:
	//constructors
	Circle(double radius);
	Circle();

	//Setters and getters
	void setRadius(double radius);

	double getRadius();
	double getArea();
	double getDiameter();
	double getCircumference();
};