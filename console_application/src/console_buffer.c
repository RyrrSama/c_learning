#include <stdio.h>
#include <windows.h>

COORD topLeft = {0,0};
void redrawScreenBuffer(HANDLE )
void clearScreenBuffer(HANDLE hConsole){
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    DWORD consoleCharCount;
    DWORD consoleSize;
    if (!GetConsoleScreenBufferInfo(hConsole, &consoleScreenBufferInfo))
    {
        printf("Failed to get console buffer info. Error %ld\n", GetLastError());
    }

    consoleSize = consoleScreenBufferInfo.dwSize.X * consoleScreenBufferInfo.dwSize.Y;
    // Fill the console with spaces
    if (!FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &consoleCharCount)){
        printf("Failed to clear Console Buffer. Error %ld\n", GetLastError());
        return;
    }
    // Reset the console text attributes
    if (!FillConsoleOutputAttribute(hConsole, consoleScreenBufferInfo.wAttributes, consoleSize, topLeft, &consoleCharCount)){
        printf("Failed to reset console attributes. Error %ld/n", GetLastError());
        return;
    }

    // Reset cusor to the top-left corner
    SetConsoleCursorPosition(hConsole, topLeft);
    
}

int main()
{
    // Save the original console buffer
    HANDLE hOriginal = GetStdHandle(STD_OUTPUT_HANDLE);

    // Create a new console screen buffer
    HANDLE hNewBuffer =
        CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, // Access flags
                                  0,                            // No sharing
                                  NULL, // Default security attributes
                                  CONSOLE_TEXTMODE_BUFFER, // Buffer type
                                  NULL                     // Reserved
        );

    if (hNewBuffer == INVALID_HANDLE_VALUE)
    {
        printf("Failed to create console buffer. Error: %ld\n", GetLastError());
        return 1;
    }

    // Set the new buffer as the active screen buffer
    if (!SetConsoleActiveScreenBuffer(hNewBuffer))
    {
        printf("Failed to set active console buffer. Error: %ld\n",
               GetLastError());
        CloseHandle(hNewBuffer);
        return 1;
    }

    // Write to the new buffer
    const char *message = "Hello from the new console buffer!";
    DWORD charsWritten;
    WriteConsole(hNewBuffer, message, (DWORD) strlen(message), &charsWritten,
                 NULL);

    clearScreenBuffer(hNewBuffer);
    SetConsoleTextAttribute(hNewBuffer, 1);
    FillConsoleOutputCharacter(hNewBuffer, 'X', 100, topLeft, &charsWritten);
    topLeft.Y+=1;
    SetConsoleTextAttribute(hNewBuffer, 5);
    FillConsoleOutputCharacter(hNewBuffer, 'X', 100, topLeft, &charsWritten);
    topLeft.Y+=1;
    SetConsoleTextAttribute(hNewBuffer, 50);
    FillConsoleOutputCharacter(hNewBuffer, 'Y', 100, topLeft, &charsWritten);
    // WriteConsole(hNewBuffer, message, (DWORD) strlen(message), &charsWritten,
    //              NULL);

    // Wait for user input
    printf("Press Enter to switch back to the original buffer...\n");
    getchar();

    // Restore the original console buffer
    SetConsoleActiveScreenBuffer(hOriginal);

    // Close the new buffer handle
    CloseHandle(hNewBuffer);

    printf("Back to the original console buffer.\n");

    return 0;
}