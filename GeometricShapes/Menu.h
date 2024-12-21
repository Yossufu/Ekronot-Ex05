#pragma once
#include "Shape.h"
#include "Canvas.h"
#include <vector>

class Menu
{
public:
    Menu();
    ~Menu();
    void showMainMenu();
    void drawAllShapes();
    void addShapeMenu();
    void modifyShapeMenu();
    void clearAllShapes();
    void moveShape(Shape* shape);
    void deleteShape(Shape* shape);
private:
    Canvas _canvas;
    std::vector<Shape*> _shapes;
};
