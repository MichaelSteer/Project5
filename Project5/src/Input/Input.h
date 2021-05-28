#pragma once
#include "Keyboard.h"
#include "Mouse.h"
class Input {
    public:
        Input();
        ~Input();

        static Keyboard getKeyboard();
        static Mouse getMouse();

        bool isKeyPressed(Key key);


    private:
};