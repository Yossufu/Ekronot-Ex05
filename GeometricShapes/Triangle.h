#pragma once
#include "Polygon.h"
#include "Point.h"
#include <string>

class Triangle : public Polygon
{
public:
    // Constructor: takes three points
    Triangle(Point a, Point b, Point c, std::string type, std::string name);

    // Destructor
    ~Triangle();

    // Methods
    void draw(const Canvas& canvas) override;
    void clearDraw(const Canvas& canvas) override;

    // Override functions
    double getArea() const override;
    double getPerimeter() const override;
    void printDetails() override;
};
