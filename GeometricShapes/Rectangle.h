#pragma once
#include "Polygon.h"
#include "Point.h"
#include <string>
namespace myShapes
{
    class Rectangle : public Polygon
    {
    public:
        // Constructor: takes the top-left corner, length, and width
        Rectangle(Point a, double length, double width, std::string type, std::string name);

        // Destructor
        ~Rectangle();

        // Methods
        void draw(const Canvas& canvas) override;
        void clearDraw(const Canvas& canvas) override;

        // Override functions
        double getArea() const override;
        double getPerimeter() const override;
        void printDetails() override;
    };
}
