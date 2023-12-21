#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "raylib.h"
#include "shape.h"

class ShapeFactory
{
public:
    ShapeFactory();
    ~ShapeFactory();
    static Shape createRandomShape();

};
#endif