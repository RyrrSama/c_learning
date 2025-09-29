#include <math.h>
#include <stdio.h>
#include <windows.h>
// Key mapping
#define VK_P 0x50 // Virtual key code for 'p'
#define VK_R 0x52 // Virtual key code for 'r'

CONSOLE_SCREEN_BUFFER_INFO prevConsoleScreenBufferInfo, consoleScreenBufferInfo;
HANDLE hDefaultScreenBuffer, hCacheScreenBuffer01, hCacheScreenBuffer02;
COORD TOPLEFT, BOTTOMLEFT, TOPRIGHT, BOTTOMRIGHT, CENTER, playerPostion;
HANDLE hActiveScreenBuffer;
DWORD bufferSize, noOfCharWritten;
CONSOLE_CURSOR_INFO cursorInfo;
const char *playerSprint = "<-->";
int isPaused             = 0;
// Function declarations

void clearCacheScreenBuffer(HANDLE hScreenBuffer);
void switchActiveBuffer();
void drawButton(HANDLE hScreenBuffer);

// Function Definition
// TODO: Need to implement Menu Setup
void menuSetup(HANDLE hScreenBuffer)
{

    consoleScreenBufferInfo.dwSize.X;
    consoleScreenBufferInfo.dwSize.Y;
}

void pauseState()
{
    while (1)
    {
        if (GetAsyncKeyState(VK_R))
        {
            isPaused = 0;
            break;
        }
        SetConsoleCursorPosition(hActiveScreenBuffer, CENTER);
        WriteConsole(hActiveScreenBuffer, "Game Paused", 11, &noOfCharWritten,
                     NULL);
        switchActiveBuffer();
        Sleep(500);
    }
}
void resetConsoleHandles()
{
    SetConsoleActiveScreenBuffer(hDefaultScreenBuffer);
    CloseHandle(hCacheScreenBuffer01);
    CloseHandle(hCacheScreenBuffer02);
}

void hideCursor(HANDLE hScreenBuffer)
{

    cursorInfo.bVisible = FALSE;
    cursorInfo.dwSize   = 1;
    SetConsoleCursorInfo(hScreenBuffer, &cursorInfo);
}

void updatePlayerPostion()
{
    float oldPlayerScalePercentageX =
        ((float) playerPostion.X / prevConsoleScreenBufferInfo.dwSize.X) * 100;
    float oldPlayerScalePercentageY =
        ((float) playerPostion.Y / prevConsoleScreenBufferInfo.dwSize.Y) * 100;

    playerPostion.X = round((oldPlayerScalePercentageX / 100) *
                            consoleScreenBufferInfo.dwSize.X);
    playerPostion.Y = round((oldPlayerScalePercentageY / 100) *
                            consoleScreenBufferInfo.dwSize.Y);
}

void drawPlayer(HANDLE hScreenBuffer)
{
    if (GetAsyncKeyState(VK_UP) & 0x8000 && playerPostion.Y > 1)
        playerPostion.Y--;
    if (GetAsyncKeyState(VK_DOWN) & 0x8000 &&
        playerPostion.Y < consoleScreenBufferInfo.srWindow.Bottom - 1)
        playerPostion.Y++;
    if (GetAsyncKeyState(VK_LEFT) & 0x8000 && playerPostion.X > 1)
        playerPostion.X -= 1;
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000 &&
        playerPostion.X < consoleScreenBufferInfo.srWindow.Right - 5)
        playerPostion.X += 1;
    SetConsoleCursorPosition(hScreenBuffer, playerPostion);
    WriteConsole(hScreenBuffer, playerSprint, 5, &noOfCharWritten, NULL);
}

void switchActiveBuffer()
{
    hActiveScreenBuffer = (hActiveScreenBuffer == hCacheScreenBuffer01)
                              ? hCacheScreenBuffer02
                              : hCacheScreenBuffer01;
    SetConsoleActiveScreenBuffer(hActiveScreenBuffer);
}

HANDLE getCacheScreenBufferHandle()
{
    return (hActiveScreenBuffer == hCacheScreenBuffer01) ? hCacheScreenBuffer02
                                                         : hCacheScreenBuffer01;
}
// Function to clear the off-screen buffer
void clearCacheScreenBuffer(HANDLE hScreenBuffer)
{
    GetConsoleScreenBufferInfo(hScreenBuffer, &consoleScreenBufferInfo);
    FillConsoleOutputCharacter(hScreenBuffer, ' ', bufferSize, TOPLEFT,
                               &noOfCharWritten);
    SetConsoleCursorPosition(hScreenBuffer, TOPLEFT);
}

void updateScreenBufferInfo(HANDLE hScreenBuffer)
{

    GetConsoleScreenBufferInfo(hScreenBuffer, &consoleScreenBufferInfo);
    TOPLEFT.X = consoleScreenBufferInfo.srWindow.Left;
    TOPLEFT.Y = consoleScreenBufferInfo.srWindow.Top;

    BOTTOMLEFT.Y = consoleScreenBufferInfo.srWindow.Bottom;
    BOTTOMLEFT.X = consoleScreenBufferInfo.srWindow.Left;

    BOTTOMRIGHT.Y = consoleScreenBufferInfo.srWindow.Bottom;
    BOTTOMRIGHT.X = consoleScreenBufferInfo.srWindow.Right;

    TOPRIGHT.X = consoleScreenBufferInfo.srWindow.Right;
    TOPRIGHT.Y = consoleScreenBufferInfo.srWindow.Top;

    CENTER.X = consoleScreenBufferInfo.srWindow.Right / 2;
    CENTER.Y = consoleScreenBufferInfo.srWindow.Bottom / 2;

    bufferSize =
        consoleScreenBufferInfo.dwSize.X * consoleScreenBufferInfo.dwSize.Y;
}

int setupConsoleWindow()
{
    //  Get default Console ScreenBuffer handle
    hDefaultScreenBuffer = GetStdHandle(STD_OUTPUT_HANDLE);
    // Create double buffer Screen console handles
    hCacheScreenBuffer01 =
        CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, // Access flags
                                  0,                            // No sharing
                                  NULL, // Default security attributes
                                  CONSOLE_TEXTMODE_BUFFER, // Buffer type
                                  NULL                     // Reserved
        );
    hCacheScreenBuffer02 =
        CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, // Access flags
                                  0,                            // No sharing
                                  NULL, // Default security attributes
                                  CONSOLE_TEXTMODE_BUFFER, // Buffer type
                                  NULL                     // Reserved
        );
    if (hCacheScreenBuffer01 == INVALID_HANDLE_VALUE ||
        hCacheScreenBuffer02 == INVALID_HANDLE_VALUE)
    {
        return 1;
    }
    // initiate with default active screen console buffer
    hActiveScreenBuffer = hCacheScreenBuffer01;
    // Set current Active buffer
    SetConsoleActiveScreenBuffer(hActiveScreenBuffer);
    // Update ConsoleBufferScreenInfo
    updateScreenBufferInfo(hActiveScreenBuffer);
    // Update Initial Screen Console info to perv Console Info
    GetConsoleScreenBufferInfo(hActiveScreenBuffer,
                               &prevConsoleScreenBufferInfo);
    //  Hide Cursor for all Console Screen Buffer
    hideCursor(hCacheScreenBuffer01);
    hideCursor(hCacheScreenBuffer02);
    //  Initiate default player postion top center of the window
    playerPostion = CENTER;
    return 0;
}

void drawBorder(HANDLE hScreenBuffer)
{

    // Draw Top Boarder
    FillConsoleOutputCharacter(hScreenBuffer, '=',
                               consoleScreenBufferInfo.srWindow.Right, TOPLEFT,
                               &noOfCharWritten);
    COORD coord       = TOPLEFT;
    DWORD innerRegion = consoleScreenBufferInfo.srWindow.Right - 2;
    for (short row = 1; row < consoleScreenBufferInfo.srWindow.Bottom; row++)
    {
        coord.Y += 1;
        // Left Border
        FillConsoleOutputCharacter(hScreenBuffer, '|', 1, coord,
                                   &noOfCharWritten);
        coord.X += 1;
        // Region Fill
        FillConsoleOutputCharacter(hScreenBuffer, '.', innerRegion, coord,
                                   &noOfCharWritten);
        coord.X += innerRegion;
        // Right Border
        FillConsoleOutputCharacter(hScreenBuffer, '|', 1, coord,
                                   &noOfCharWritten);
        coord.X = 0;
    }

    FillConsoleOutputCharacter(hScreenBuffer, '=',
                               consoleScreenBufferInfo.srWindow.Right,
                               BOTTOMLEFT, &noOfCharWritten);
}

void drawFrame(HANDLE hScreenBuffer)
{
    // Update latest Console Screen Buffer Info
    updateScreenBufferInfo(hScreenBuffer);
    // Clear old frame data from console Screen Buffer
    clearCacheScreenBuffer(hScreenBuffer);
    // Draw Static border
    drawBorder(hScreenBuffer);
    // Draw Player
    drawPlayer(hScreenBuffer);
    // Update Console Screen Buffer
    switchActiveBuffer();
}

BOOL setCursorPosition(HANDLE hScreenBuffer, short px, short py)
{
    COORD coord = {px, py};
    return SetConsoleCursorPosition(hScreenBuffer, coord);
}

void gameLoop(int fps)
{
    while (1)
    {
        if (prevConsoleScreenBufferInfo.dwSize.X !=
                consoleScreenBufferInfo.dwSize.X ||
            prevConsoleScreenBufferInfo.dwSize.Y !=
                consoleScreenBufferInfo.dwSize.Y)
        {
            updatePlayerPostion();
            // Update the previous size
            prevConsoleScreenBufferInfo = consoleScreenBufferInfo;
        }
        HANDLE hCacheScreenBuffer = getCacheScreenBufferHandle();

        drawFrame(hCacheScreenBuffer);

        if (GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
        if (GetAsyncKeyState(VK_P))
        {
            pauseState();
        }
        Sleep(1000 / fps);
    }
}

int main()
{
    // Setup Game Console ScreenBuffer
    int newConsoleStatus = setupConsoleWindow();
    if (newConsoleStatus == 1)
    {
        printf("Failed to create new ConsoleScreenBuffer. Error %ld\n",
               GetLastError());
        return 1;
    }
    // Game loop
    gameLoop(24);
    // Close Cache Screen Buffer Handles
    resetConsoleHandles();
    return 0;
}