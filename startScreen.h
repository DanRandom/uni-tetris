#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include "raylib.h"
#include "Screen.h"

class StartScreen : public Screen
{
private:
    
public:
    StartScreen();
    ~StartScreen();

    void display() override;
};
#endif
