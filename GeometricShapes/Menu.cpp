#include "Menu.h"
#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Arrow.h"
#include "Triangle.h"

Menu::Menu() {}

Menu::~Menu()
{
    this->clearAllShapes();
}

void Menu::addShapeMenu()
{
    std::cout << "Enter 0 to add a circle.\n"
        << "Enter 1 to add an arrow.\n"
        << "Enter 2 to add a triangle.\n"
        << "Enter 3 to add a rectangle.\n";
    int choice = 0;
    std::cin >> choice;
    std::string name = "";
    std::cout << "Enter the name of the shape: ";
    std::cin >> name;

    switch (choice)
    {
    case 0:// Circle
    {
        double x, y, radius;
        std::cout << "Please enter X: ";
        std::cin >> x;
        std::cout << "Please enter Y: ";
        std::cin >> y;
        std::cout << "Please enter radius: ";
        std::cin >> radius;

        Shape* circle = new Circle(Point(x, y), radius, "circle", name);
        circle->draw(this->_canvas);
        this->_shapes.push_back(circle);
        break;
    }
    case 1: // Arrow
    {
        double x1, y1, x2, y2;
        std::cout << "Enter the X of point number 1: ";
        std::cin >> x1;
        std::cout << "Enter the Y of point number 1: ";
        std::cin >> y1;
        std::cout << "Enter the X of point number 2: ";
        std::cin >> x2;
        std::cout << "Enter the Y of point number 2: ";
        std::cin >> y2;

        Shape* arrow = new Arrow(Point(x1, y1), Point(x2, y2), "arrow", name);
        arrow->draw(this->_canvas);
        this->_shapes.push_back(arrow);
        break;
    }
    case 2: // Triangle
    {
        double x1, y1, x2, y2, x3, y3;
        std::cout << "Enter the X of point number 1: ";
        std::cin >> x1;
        std::cout << "Enter the Y of point number 1: ";
        std::cin >> y1;
        std::cout << "Enter the X of point number 2: ";
        std::cin >> x2;
        std::cout << "Enter the Y of point number 2: ";
        std::cin >> y2;
        std::cout << "Enter the X of point number 3: ";
        std::cin >> x3;
        std::cout << "Enter the Y of point number 3: ";
        std::cin >> y3;

        Shape* triangle = new Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3), "triangle", name);
        triangle->draw(this->_canvas);
        this->_shapes.push_back(triangle);
        break;
    }
    case 3:// Rectangle
    {
        double x, y, length, width;
        std::cout << "Enter the X of the top left corner: ";
        std::cin >> x;
        std::cout << "Enter the Y of the top left corner: ";
        std::cin >> y;
        std::cout << "Please enter the length: ";
        std::cin >> length;
        std::cout << "Please enter the width: ";
        std::cin >> width;
        
        Shape* rectangle = new myShapes::Rectangle(Point(x, y), length, width, "rectangle", name);
        rectangle->draw(this->_canvas);
        this->_shapes.push_back(rectangle);
        break;
    }
    default:
        break;
    }
}

void Menu::modifyShapeMenu()
{
    std::cout << "Enter the number of the shape you want to modify:\n";
    for (int i = 0; i < this->_shapes.size(); ++i)
    {
        std::cout << i << ". " << this->_shapes[i]->getName() << " (" << this->_shapes[i]->getType() << ")\n";
    }
    int shapeChoice = 0;
    std::cin >> shapeChoice;
    if (shapeChoice < 0 || shapeChoice >= this->_shapes.size())
    {
        return;
    }
    Shape* selectedShape = this->_shapes[shapeChoice];
    std::cout << "Enter 0 to move the shape\n"
        << "Enter 1 to get its details\n"
        << "Enter 2 to remove the shape\n";
    int actionChoice = 0;
    std::cin >> actionChoice;
    switch (actionChoice)
    {
    case 0:
    {
        this->moveShape(selectedShape);
        break;
    }
    case 1:
    {
        selectedShape->printDetails();
        break;
    }
    case 2:
    {
        this->deleteShape(selectedShape);
        this->drawAllShapes();
        break;
    }
    default:
        break;
    }
}

void Menu::moveShape(Shape* shape)
{
    shape->clearDraw(this->_canvas);
    double xScale = 0, yScale = 0;
    std::cout << "Please enter the X moving scale: ";
    std::cin >> xScale;
    std::cout << "Please enter the Y moving scale: ";
    std::cin >> yScale;
    Point moveBy = Point(xScale, yScale);
    shape->move(moveBy);
    shape->draw(this->_canvas);
}

void Menu::drawAllShapes()
{
    for (int i = 0; i < this->_shapes.size(); ++i)
    {
        this->_shapes[i]->draw(this->_canvas);
    }
}

void Menu::deleteShape(Shape* shape)
{
    for (int i = 0; i < this->_shapes.size(); ++i)
    {
        if (this->_shapes[i] == shape)
        {
            this->_shapes[i]->clearDraw(this->_canvas);
            delete this->_shapes[i];
            this->_shapes.erase(this->_shapes.begin() + i);
            return;
        }
    }
}

void Menu::clearAllShapes()
{
    this->_canvas.clear_rectangle(Point(0, 0), Point(1000, 1000));
    for (int i = 0; i < this->_shapes.size(); i++)
    {
        delete this->_shapes[i];
        return;
    }
    this->_shapes.clear();
}

void Menu::showMainMenu()
{
    int option = 0;
    do {
        std::cout << "Enter 0 to add a new shape.\n"
            << "Enter 1 to modify or get information from a current shape.\n"
            << "Enter 2 to delete all of the shapes.\n"
            << "Enter 3 to exit.\n";
        std::cin >> option;
        switch (option)
        {
        case 0:
            this->addShapeMenu();
            break;
        case 1:
            this->modifyShapeMenu();
            break;
        case 2:
            this->clearAllShapes();
            break;
        case 3:
            exit(1);
            break;
        default:
            break;
        }
    } while (option != 3);
}