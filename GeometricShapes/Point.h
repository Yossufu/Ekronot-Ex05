#pragma once

#include <cmath>

class Point
{
private:
	double x;
	double y;
public:

	// Constructors
	Point(); // initialize values to 0
	Point(double x, double y);

	// Destructor
	//~Point();
	
	// Operators
	Point operator+(Point other);
	Point& operator+=(Point other);

	// Getters
	double getX() const;
	double getY() const;

	// Methods
	double distance(const Point& other) const;
};