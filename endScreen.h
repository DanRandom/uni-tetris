#ifndef DEATHSCREEN_H
#define DEATHSCREEN_H
#include "raylib.h"
#include "Screen.h"

class EndScreen  : public Screen
{
private:
    
public:
    EndScreen();
    ~EndScreen();

    void display();
};
#endif
