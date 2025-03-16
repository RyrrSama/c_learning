/**
 * @file stringFunctions.c
 * @brief Implementation of various string manipulation functions.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stringFuctions.h"

static const char *VOWELS = "aeiou";
// String support functions
int getStringLenght(const char *string)
{
    int lenght = 0;
    while (string[lenght] != '\0')
    {
        lenght++;
    }
    return lenght;
}

void reverseString(const char *inputString, char *reversedStr)
{
    int length = getStringLenght(inputString);
    for (int i = length; i > 0; i--)
    {
        reversedStr[length - i] = inputString[i - 1];
    }
    reversedStr[length] = '\0';
}

bool stringCompare(const char *srcString, const char *desString)
{
    int srcLenght = getStringLenght(srcString);
    int desLenght = getStringLenght(desString);
    if (srcLenght != desLenght)
    {
        return false;
    }
    for (int i = 0; i < srcLenght; i++)
    {
        if (srcString[i] != desString[i])
        {
            return false;
        }
    }
    return true;
}

bool isPalindrome(const char *string)
{
    int lenght           = getStringLenght(string);
    char *reversedString = (char *) malloc(lenght * sizeof(char));
    reverseString(string, reversedString);
    bool palindrome = stringCompare(string, reversedString);
    free(reversedString);
    return palindrome;
}

char charToLower(const char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }
    return c;
}

char charToUpper(const char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 32;
    }
    return c;
}

static bool isCharAVowel(const char c)
{
    int count = 0;
    while (VOWELS[count] != '\0')
    {
        if (VOWELS[count] == c)
        {
            return true;
        }
        count++;
    }
    return false;
}

char *toLower(const char *string)
{
    int stringLength  = getStringLenght(string);
    char *lowerString = (char *) malloc((stringLength + 1) * sizeof(char));
    if (lowerString == NULL)
    {
        printf("ERROR: Memory allocation failed\n");
        return NULL; // Memory allocation failed
    }
    for (int index = 0; index < stringLength; index++)
    {
        lowerString[index] = charToLower(string[index]);
    }
    return lowerString;
}

char *toUpper(const char *string)
{
    int stringLength  = getStringLenght(string);
    char *upperString = (char *) malloc((stringLength + 1) * sizeof(char));
    if (upperString == NULL)
    {
        printf("ERROR: Memory allocation failed\n");
        return NULL; // Memory allocation failed
    }
    for (int index = 0; index < stringLength; index++)
    {
        upperString[index] = charToUpper(string[index]);
    }
    return upperString;
}

int getVolwelsCount(const char *string)
{
    int count        = 0;
    int volwelsCount = 0;
    while (string[count] != '\0')
    {
        if (isCharAVowel(string[count]))
        {
            volwelsCount++;
        }
        count++;
    }
    return volwelsCount;
}

int getConsonantsCount(const char *string)
{
    int count           = 0;
    int consonantsCount = 0;
    while (string[count] != '\0')
    {
        if (!isCharAVowel(string[count]))
        {
            consonantsCount++;
        }
        count++;
    }
    return consonantsCount;
}