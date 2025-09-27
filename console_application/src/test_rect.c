#include "components.h"
#include <windows.h>

HANDLE HORIGINAL;

void test_rect(HANDLE parentBuffer)
{
    Instance rectInstance = createRectInstance(parentBuffer, 10, 10, 10, 5);
    rectInstance.draw(rectInstance);
}

void test_custom_rect(HANDLE parentBuffer)
{
    COORD bottomLeft      = {20, 20};
    COORD bottomRight     = {30, 20};
    COORD topRight        = {30, 10};
    COORD topBottom       = {20, 10};
    Instance rectInstance = createCustomRectInstance(
        parentBuffer, bottomLeft, bottomRight, topRight, topBottom);
    rectInstance.draw(rectInstance);
}

;
int main()
{
    HORIGINAL = GetStdHandle(STD_OUTPUT_HANDLE);
    test_rect(HORIGINAL);
    test_custom_rect(HORIGINAL);
    return 0;
}
