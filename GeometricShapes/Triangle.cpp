#include "Triangle.h"
#include "Canvas.h"
#include <cmath>
#include <iostream>

Triangle::Triangle(Point a, Point b, Point c, std::string type, std::string name) : Polygon(type, name)
{
    // Defining the three points of the triangle
    this->_points.push_back(a);
    this->_points.push_back(b);
    this->_points.push_back(c);
}

Triangle::~Triangle() {}

void Triangle::draw(const Canvas& canvas)
{
    canvas.draw_triangle(this->_points[0], this->_points[1], this->_points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
    canvas.clear_triangle(this->_points[0], this->_points[1], this->_points[2]);
}

double Triangle::getArea() const
{
    double x1 = this->_points[0].getX(), y1 = this->_points[0].getY();
    double x2 = this->_points[1].getX(), y2 = this->_points[1].getY();
    double x3 = this->_points[2].getX(), y3 = this->_points[2].getY();
    return 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

double Triangle::getPerimeter() const
{
    double side1 = this->_points[0].distance(this->_points[1]);
    double side2 = this->_points[1].distance(this->_points[2]);
    double side3 = this->_points[2].distance(this->_points[0]);
    return side1 + side2 + side3;
}

void Triangle::printDetails()
{
    std::cout << "Name: " << this->getName() << "\n";
    std::cout << "Type: " << this->getType() << "\n";
    std::cout << "Vertices:\n";
    std::cout << "  Point 1: [X = " << _points[0].getX() << ", Y = " << _points[0].getY() << "]\n";
    std::cout << "  Point 2: [X = " << _points[1].getX() << ", Y = " << _points[1].getY() << "]\n";
    std::cout << "  Point 3: [X = " << _points[2].getX() << ", Y = " << _points[2].getY() << "]\n";
    std::cout << "Perimeter: " << this->getPerimeter() << "\n";
    std::cout << "Area: " << this->getArea() << "\n";
}