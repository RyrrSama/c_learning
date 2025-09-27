#include "components.h"
#include <windows.h>

HANDLE HORIGINAL;

void test_button(HANDLE parentBuffer)
{

    Button button = createButton(parentBuffer, "Hello", 10, 10, 10, 5);
    button.drawButton(button);
}

int main()
{
    HORIGINAL = GetStdHandle(STD_OUTPUT_HANDLE);
    // test_rect(HORIGINAL);
    test_button(HORIGINAL);
    return 0;
}