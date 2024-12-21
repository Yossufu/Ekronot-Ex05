#pragma once

#include "Shape.h"
#include "Point.h"
#include <iostream>

#define PI 3.14

class Circle : public Shape
{
public:

	// Constructor
	Circle(Point center, double radius, const std::string& type, const std::string& name);

	// Destructor
	~Circle();

	// Getters
	Point getCenter() const;
	double getRadius() const;

	// Methods
	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;

	double getArea() const override;
	double getPerimeter() const override;
	void move(Point other) override;
	void printDetails() override;
	// add fields
	// override functions if need (virtual + pure virtual)
private:
	Point _center;
	double _radius;
};