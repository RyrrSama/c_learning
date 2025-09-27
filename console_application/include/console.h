#ifndef CONSOLE_H
#define CONSOLE_H

//  Imports
#include <stdio.h>
#include <windows.h>

typedef struct CONSOLEWINDOW
{
    HANDLE hActiveConsoleBuffer;
    HANDLE hDefaultConsoleBuffer, hCacheConsoleBuffer01, hCacheConsoleBuffer02;
    CONSOLE_SCREEN_BUFFER_INFO consoleBufferInfo, cacheBufferInfo;
    CONSOLE_CURSOR_INFO consoleCursorInfo;
    DWORD noOfCharsWritten;
    COORD consoleTopLeft, consoleTopRight, consoleBottomLeft,
        consoleBottomRight, consoleCenter;
    DWORD consoleSize;
    int (*updateConsoleBufferInfo)(struct CONSOLEWINDOW consoleWindow);
    int (*clearConsoleBuffer)(struct CONSOLEWINDOW consoleWindow);
    int (*resetConsoleHandles)(struct CONSOLEWINDOW consoleWindow);
    int (*switchActiveBuffer)(struct CONSOLEWINDOW consoleWindow);
    int (*setUpDoubleBuffer)(struct CONSOLEWINDOW consoleWindow);
} ConsoleWindow;

// ************* static function
int getConsoleBufferInfo(HANDLE consoleBuffer, DWORD noOfWritten);
HANDLE createNewConsoleBuffer(void);
// ! static function Ended *******************************

// ************* ConsoleWindow supportive function
int clearConsoleBuffer(struct CONSOLEWINDOW consoleWindow);
int updateConsoleBufferInfo(struct CONSOLEWINDOW consoleWindow);
int resetConsoleHandles(struct CONSOLEWINDOW consoleWindow);
int switchActiveBuffer(struct CONSOLEWINDOW consoleWindow);
HANDLE getBufferConsoleHandle(struct CONSOLEWINDOW consoleWindow);
int setUpDoubleBuffer(struct CONSOLEWINDOW consoleWindow);

// ! ConsoleWindow supportive function Ended **************

#endif