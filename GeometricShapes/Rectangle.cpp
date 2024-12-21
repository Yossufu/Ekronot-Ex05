#include "Rectangle.h"
#include "Canvas.h"
#include <cmath>
#include <iostream>
namespace myShapes
{
    Rectangle::Rectangle(Point a, double length, double width, std::string type, std::string name) : Polygon(type, name)
    {
        this->_points.push_back(a); // Top left corner
        this->_points.push_back(Point(a.getX() + length, a.getY())); // Top right corner
        this->_points.push_back(Point(a.getX() + length, a.getY() + width)); // Bottom right corner
        this->_points.push_back(Point(a.getX(), a.getY() + width)); // Bottom left corner
    }

    Rectangle::~Rectangle() {}

    void Rectangle::draw(const Canvas& canvas)
    {
        canvas.draw_rectangle(this->_points[0], this->_points[2]);
    }

    void Rectangle::clearDraw(const Canvas& canvas)
    {
        canvas.clear_rectangle(this->_points[0], this->_points[2]);
    }

    double Rectangle::getArea() const
    {
        double length = this->_points[1].getX() - this->_points[0].getX();
        double width = this->_points[3].getY() - this->_points[0].getY();
        return length * width;
    }

    double Rectangle::getPerimeter() const
    {
        double length = this->_points[1].getX() - this->_points[0].getX();
        double width = this->_points[3].getY() - this->_points[0].getY();
        return 2 * (length + width);
    }

    void Rectangle::printDetails()
    {
        std::cout << "Name: " << this->getName() << "\n";
        std::cout << "Type: " << this->getType() << "\n";
        std::cout << "Vertices:\n";
        std::cout << "  Top Left: [X = " << _points[0].getX() << ", Y = " << _points[0].getY() << "]\n";
        std::cout << "  Top Right: [X = " << _points[1].getX() << ", Y = " << _points[1].getY() << "]\n";
        std::cout << "  Bottom Right: [X = " << _points[2].getX() << ", Y = " << _points[2].getY() << "]\n";
        std::cout << "  Bottom Left: [X = " << _points[3].getX() << ", Y = " << _points[3].getY() << "]\n";
        std::cout << "Perimeter: " << this->getPerimeter() << "\n";
        std::cout << "Area: " << this->getArea() << "\n";
    }
}