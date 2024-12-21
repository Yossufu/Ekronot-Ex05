#include "Circle.h"

Circle::Circle(Point center, double radius, const std::string& type, const std::string& name) : Shape(name, type), _center(center), _radius(radius)
{
    if (radius <= 0)
    {
        std::cout << "Warning: Circle radius cannot be zero or negative" << std::endl;
        exit(1);
    }
}

Circle::~Circle() {}

Point Circle::getCenter() const
{
    return this->_center;
}

double Circle::getRadius() const
{
    return this->_radius;
}

double Circle::getArea() const
{
    return PI * this->_radius * this->_radius;
}

double Circle::getPerimeter() const
{
    return 2 * PI * this->_radius;
}

void Circle::move(Point other)
{
    this->_center = this->_center + other;
}

void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(getCenter(), getRadius());
}

void Circle::printDetails()
{
    std::cout << "Name: " << this->getName() << "\n";
    std::cout << "Type: " << this->getType() << "\n";
    std::cout << "Center: [X = " << _center.getX() << ", Y = " << _center.getY() << "]\n";
    std::cout << "Radius: " << _radius << "\n";
    std::cout << "Circumference: " << this->getPerimeter() << "\n";
    std::cout << "Area: " << this->getArea() << "\n";
}