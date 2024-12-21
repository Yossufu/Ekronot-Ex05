#pragma once
#include "Shape.h"
#include "Point.h"
#include <vector>

class Polygon : public Shape
{
public:
    // Constructor
    Polygon(const std::string& type, const std::string& name);

    // Destructor
    ~Polygon();

    // Methods
    std::vector<Point> getPoints() const;

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void move(Point other) override;
protected:
    std::vector<Point> _points;
};
