#include "Arrow.h"
#include <iostream>
#include <cmath> // For sqrt function

Arrow::Arrow(Point a, Point b, const std::string& type, const std::string& name)
    : Shape(name, type), _source(a), _destination(b)
{
    // Check if the points are the same
    if (a.getX() == b.getX() && a.getY() == b.getY())
    {
        std::cout << "Warning: Points can't be the same" << std::endl;
        exit(1);
    }
}

Point Arrow::getSource() const
{
    return this->_source;
}

Point Arrow::getDestination() const
{
    return this->_destination;
}

void Arrow::draw(const Canvas& canvas)
{
    canvas.draw_arrow(_source, _destination);
}

void Arrow::clearDraw(const Canvas& canvas)
{
    canvas.clear_arrow(_source, _destination);
}

double Arrow::getArea() const
{
    return 0.0;
}

double Arrow::getPerimeter() const
{
    return _source.distance(_destination);
}

void Arrow::move(Point other)
{
    _source = _source + other;
    _destination = _destination + other;
}

void Arrow::printDetails()
{
    std::cout << "Name: " << this->getName() << "\n";
    std::cout << "Type: " << this->getType() << "\n";
    std::cout << "Source: [X = " << _source.getX() << ", Y = " << _source.getY() << "]\n";
    std::cout << "Destination: [X = " << _destination.getX() << ", Y = " << _destination.getY() << "]\n";
    std::cout << "Length: " << this->getPerimeter() << "\n";
    std::cout << "Area: 0\n";
}
