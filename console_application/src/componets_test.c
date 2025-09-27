#include "components.h"
#include <windows.h>

int main()
{
    HANDLE hOriginal  = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bottomLeft  = {0, 5};
    COORD bottomRight = {5, 5};
    COORD topRight    = {5, 0};
    COORD topLeft     = {0, 0};
    BUTTON button     = createButton(hOriginal, "Hello", 10, 10, 20, 5);
    button.drawButton(button);
    // SHAPE customRect = createCustomRectShape(hOriginal, bottomLeft,
    // bottomRight,
    //                                          topRight, topLeft);
    // customRect.draw(customRect);
    // SHAPE rect       = createRectShape(hOriginal, 10, 10, 10, 10);
    // rect.draw(rect);
    return 0;
}