#include "Polygon.h"

Polygon::Polygon(const std::string& type, const std::string& name) : Shape(name, type) {}

Polygon::~Polygon() {}

std::vector<Point> Polygon::getPoints() const
{
    return this->_points;
}

void Polygon::move(Point other)
{
    for (int i = 0; i < this->_points.size(); ++i)
    {
        this->_points[i] = this->_points[i] + other;
    }
}
