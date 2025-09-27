#include <stdio.h>
#include <windows.h>

COORD topLeft = {0, 0};

void clearScreenBuffer(HANDLE hConsole) {
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    DWORD consoleCharCount;
    DWORD consoleSize;

    if (!GetConsoleScreenBufferInfo(hConsole, &consoleScreenBufferInfo)) {
        printf("Failed to get console buffer info. Error %ld\n", GetLastError());
        return;
    }

    consoleSize = consoleScreenBufferInfo.dwSize.X * consoleScreenBufferInfo.dwSize.Y;

    // Fill the console with spaces
    if (!FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &consoleCharCount)) {
        printf("Failed to clear Console Buffer. Error %ld\n", GetLastError());
        return;
    }

    // Reset the console text attributes
    if (!FillConsoleOutputAttribute(hConsole, consoleScreenBufferInfo.wAttributes, consoleSize, topLeft, &consoleCharCount)) {
        printf("Failed to reset console attributes. Error %ld\n", GetLastError());
        return;
    }

    // Reset cursor to the top-left corner
    SetConsoleCursorPosition(hConsole, topLeft);
}

void redrawConsole(HANDLE hConsole) {
    // Example content to redraw after resizing
    DWORD charsWritten;
    FillConsoleOutputCharacter(hConsole, '*', 50, topLeft, &charsWritten);
    topLeft.Y += 1;
    FillConsoleOutputCharacter(hConsole, '*', 50, topLeft, &charsWritten);
    topLeft.Y = 0; // Reset for future use
}

int main() {
    HANDLE hOriginal = GetStdHandle(STD_OUTPUT_HANDLE);

    HANDLE hNewBuffer = CreateConsoleScreenBuffer(
        GENERIC_READ | GENERIC_WRITE, // Access flags
        0,                            // No sharing
        NULL,                         // Default security attributes
        CONSOLE_TEXTMODE_BUFFER,      // Buffer type
        NULL                          // Reserved
    );

    if (hNewBuffer == INVALID_HANDLE_VALUE) {
        printf("Failed to create console buffer. Error: %ld\n", GetLastError());
        return 1;
    }

    if (!SetConsoleActiveScreenBuffer(hNewBuffer)) {
        printf("Failed to set active console buffer. Error: %ld\n", GetLastError());
        CloseHandle(hNewBuffer);
        return 1;
    }

    // Initial content
    redrawConsole(hNewBuffer);

    // Monitor for console resizing
    CONSOLE_SCREEN_BUFFER_INFO prevInfo, currInfo;
    GetConsoleScreenBufferInfo(hNewBuffer, &prevInfo);

    printf("Resize the console window and press Enter to exit...\n");

    while (1) {
        GetConsoleScreenBufferInfo(hNewBuffer, &currInfo);

        // Check if the console size has changed
        if (currInfo.dwSize.X != prevInfo.dwSize.X || currInfo.dwSize.Y != prevInfo.dwSize.Y) {
            clearScreenBuffer(hNewBuffer);
            redrawConsole(hNewBuffer);
            prevInfo = currInfo; // Update the previous size
        }

        // Break on Enter key
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
            break;
        }

        Sleep(100); // Avoid busy-waiting
    }

    // Restore the original console buffer
    SetConsoleActiveScreenBuffer(hOriginal);
    CloseHandle(hNewBuffer);

    printf("Back to the original console buffer.\n");

    return 0;
}