#include "stdafx.h"
#include "Circle.h"

#include <string>
using namespace std;

//Default Constructor
Circle::Circle() {
	radius = 0.0;
}
Circle::Circle(double rd) {
	radius = rd;
}


void Circle::setRadius(double rd) {
	radius = rd;
}


double Circle::getRadius() {
	return radius;
}

double Circle::getArea() {
	double area;
	area = pi * radius *radius;
	return area;
}

double Circle::getDiameter() {
	double diameter;
	diameter = radius * 2;
	return diameter;
}

double Circle::getCircumference() {
	double circumference;
	circumference = 2 * pi * radius;
	return circumference;
}