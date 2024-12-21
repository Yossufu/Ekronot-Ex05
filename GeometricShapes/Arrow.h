#pragma once
#include "Shape.h"
#include <string>
#include <iostream>

class Arrow : public Shape
{
public:
    // Constructor
    Arrow(Point a, Point b, const std::string& type, const std::string& name);

    // Destructor (default one is fine unless you have specific cleanup)
    ~Arrow() = default;

    // Getters
    Point getSource() const;
    Point getDestination() const;

    // Methods
    void draw(const Canvas& canvas) override;
    void clearDraw(const Canvas& canvas) override;

    // Override virtual methods from Shape
    double getArea() const override;
    double getPerimeter() const override;
    void move(Point other) override;
    void printDetails() override;

private:
    Point _source;
    Point _destination;
};
