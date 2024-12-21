#include "Shape.h"
#include <iostream>

Shape::Shape(const std::string& name, const std::string& type): _name(name), _type(type) {}

Shape::~Shape() {}

std::string Shape::getType() const
{
	return this->_type;
}

std::string Shape::getName() const
{
	return this->_name;
}