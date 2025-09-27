#include "console.h"
#include <stdio.h>
#include <windows.h>

// **************************Static functions
static int getConsoleBufferInfo(HANDLE consoleBuffer, DWORD noOfWritten)
{
    BOOL status = GetConsoleScreenBufferInfo(consoleBuffer, &noOfWritten);
    if (!status)
    {
        // INFO:Caller function should handle the error
        return -1;
    }
    return 0;
}

static int HANDLE createNewConsoleBuffer()
{
    return CreateConsoleScreenBuffer(
        GENERIC_READ | GENERIC_WRITE, // Access flags
        0,                            // No sharing
        NULL,                         // Default security attributes
        CONSOLE_TEXTMODE_BUFFER,      // Buffer type
        NULL                          // Reserved
    );
    return 0;
}
// ! Static function *************************
// ************* ConsoleWindow supportive function
int clearConsoleBuffer(struct CONSOLEWINDOW consoleWindow)
{

    FillConsoleOutputCharacter(
        consoleWindow.hActiveConsoleBuffer, ' ', consoleWindow.consoleSize,
        consoleWindow.consoleTopLeft, &consoleWindow.noOfCharsWritten);
    return 0;
}

int updateConsoleBufferInfo(struct CONSOLEWINDOW consoleWindow)
{
    GetConsoleScreenBufferInfo(consoleWindow.hActiveConsoleBuffer,
                               &consoleWindow.consoleBufferInfo);
    consoleWindow.consoleTopLeft.X =
        consoleWindow.consoleBufferInfo.srWindow.Left;
    consoleWindow.consoleTopLeft.Y =
        consoleWindow.consoleBufferInfo.srWindow.Top;

    consoleWindow.consoleBottomLeft.Y =
        consoleWindow.consoleBufferInfo.srWindow.Bottom;
    consoleWindow.consoleBottomLeft.X =
        consoleWindow.consoleBufferInfo.srWindow.Left;

    consoleWindow.consoleBottomRight.Y =
        consoleWindow.consoleBufferInfo.srWindow.Bottom;
    consoleWindow.consoleBottomRight.X =
        consoleWindow.consoleBufferInfo.srWindow.Right;

    consoleWindow.consoleTopRight.X =
        consoleWindow.consoleBufferInfo.srWindow.Right;
    consoleWindow.consoleTopRight.Y =
        consoleWindow.consoleBufferInfo.srWindow.Top;

    consoleWindow.consoleCenter.X =
        (consoleWindow.consoleBufferInfo.srWindow.Right / 2);
    consoleWindow.consoleCenter.Y =
        (consoleWindow.consoleBufferInfo.srWindow.Bottom / 2);

    consoleWindow.consoleSize = consoleWindow.consoleBufferInfo.dwSize.X *
                                consoleWindow.consoleBufferInfo.dwSize.Y;
}

int resetConsoleHandles(struct CONSOLEWINDOW consoleWindow)
{
    SetConsoleActiveScreenBuffer(consoleWindow.hActiveConsoleBuffer);
    CloseHandle(consoleWindow.hCacheConsoleBuffer01);
    CloseHandle(consoleWindow.hCacheConsoleBuffer02);
}

int switchActiveBuffer(struct CONSOLEWINDOW consoleWindow)
{
    consoleWindow.hActiveConsoleBuffer =
        (consoleWindow.hActiveConsoleBuffer ==
         consoleWindow.hCacheConsoleBuffer01)
            ? consoleWindow.hCacheConsoleBuffer02
            : consoleWindow.hCacheConsoleBuffer01;
    return 0;
}

HANDLE getBufferConsoleHandle(struct CONSOLEWINDOW consoleWindow)
{
    return (consoleWindow.hActiveConsoleBuffer ==
            consoleWindow.hCacheConsoleBuffer01)
               ? consoleWindow.hCacheConsoleBuffer02
               : consoleWindow.hCacheConsoleBuffer01;
}

int setUpDoubleBuffer(struct CONSOLEWINDOW consoleWindow)
{
    consoleWindow.hCacheConsoleBuffer01 = createNewConsoleBuffer();
    consoleWindow.hCacheConsoleBuffer02 = createNewConsoleBuffer();
    if (consoleWindow.hCacheConsoleBuffer01 == INVALID_HANDLE_VALUE ||
        consoleWindow.hCacheConsoleBuffer02 == INVALID_HANDLE_VALUE)
        // TODO: Decide to handle error or leave it to caller function
        return -1;
    consoleWindow.hActiveConsoleBuffer = consoleWindow.hCacheConsoleBuffer01;
    // Update ConsoleBufferInfo
    updateConsoleBufferInfo(consoleWindow);
    return 0;
}
// ! ConsoleWindow supportive function Ended **************

ConsoleWindow createConsoleWindow()
{
    ConsoleWindow consoleWindow;
    // Get default console buffer
    consoleWindow.hDefaultConsoleBuffer = GetStdHandle(STD_OUTPUT_HANDLE);
    consoleWindow.hActiveConsoleBuffer  = consoleWindow.hDefaultConsoleBuffer;
    consoleWindow.hCacheConsoleBuffer01 = NULL;
    consoleWindow.hCacheConsoleBuffer02 = NULL;
    updateConsoleBufferInfo(consoleWindow);
    consoleWindow.updateConsoleBufferInfo = updateConsoleBufferInfo;
    consoleWindow.clearConsoleBuffer      = clearConsoleBuffer;
    consoleWindow.resetConsoleHandles     = resetConsoleHandles;
    consoleWindow.switchActiveBuffer      = switchActiveBuffer;
    consoleWindow.setUpDoubleBuffer       = setUpDoubleBuffer;
    return consoleWindow;
}