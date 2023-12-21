#include "raylib.h"
#include "ShapeFactory.h"
#include <random>

ShapeFactory::ShapeFactory() {

}

ShapeFactory::~ShapeFactory() {

}

Shape ShapeFactory::createRandomShape() {
    Color colors[] = {RED, BLUE, GREEN, YELLOW, PURPLE, ORANGE, PINK};
    return Shape(rand() % 7, colors[rand() % 7]);
}