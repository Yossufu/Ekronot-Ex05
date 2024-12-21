#include "Point.h"
Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point Point::operator+(Point other)
{
    return Point(this->x + other.x, this->y + other.y);
}

Point& Point::operator+=(Point other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

double Point::distance(const Point& other) const
{
    double dx = x - other.getX();
    double dy = y - other.getY();
    return std::sqrt(dx * dx + dy * dy);
}