#ifndef CONSOLE_APPLICATION
#define CONSOLE_APPLICATION
#include<windows.h>
// Macro definitions
#define ROWS 500
#define COLUMN 500
// Type definitions
typedef struct Console{
    HANDLE standardConsole;
    HANDLE screenBuffer;


}Console;

// Function declaration
HANDLE createNewScreenBuffer();
BOOL setCurrentScreenBuffer(HANDLE hScreenBuffer);
BOOL closeConsoleScreenBuffer(HANDLE hScreenBuffer);
BOOL writeCurrentScreenBuffer(char* newChars, int newCharSize, int noOfCharsWritten);
void createConsoleBuffer();
void getDefaultConsoleBuffer();
#endif