/**
 * @file stringFunctions.h
 * @brief Header file containing declarations for string manipulation functions.
 *
 * This file provides function declarations for various string manipulation
 * operations such as converting characters to lower or upper case, comparing
 * strings, reversing strings, checking for palindromes, and counting vowels
 * and consonants.
 */

#ifndef stringFunctions_h
#define stringFunctions_h // Header guard

#include <stdbool.h>

/**
 * @brief Converts a character to lowercase.
 *
 * @param c The character to convert.
 * @return The lowercase equivalent of the character.
 */
char charToLower(const char c);

/**
 * @brief Converts a character to uppercase.
 *
 * @param c The character to convert.
 * @return The uppercase equivalent of the character.
 */
char charToUpper(const char c);

/**
 * @brief Compares two strings for equality.
 *
 * @param srcStr The source string.
 * @param desStr The destination string.
 * @return true if the strings are equal, false otherwise.
 */
bool stringCompare(const char *srcStr, const char *desStr);

/**
 * @brief Reverses a given string.
 *
 * @param inputStr The input string to reverse.
 * @param reversedStr The buffer to store the reversed string.
 * @param length The length of the input string.
 */
void reverseString(const char *inputStr, char *reversedStr);

/**
 * @brief Gets the length of a string.
 *
 * @param str The string whose length is to be determined.
 * @return The length of the string.
 */
int getStringLenght(const char *str);

/**
 * @brief Checks if a string is a palindrome.
 *
 * @param str The string to check.
 * @return true if the string is a palindrome, false otherwise.
 */
bool isPalindrome(const char *str);

/**
 * @brief Counts the number of vowels in a string.
 *
 * @param str The string to check.
 * @return The number of vowels in the string.
 */
int getVolwelsCount(const char *str);

/**
 * @brief Counts the number of consonants in a string.
 *
 * @param str The string to check.
 * @return The number of consonants in the string.
 */
int getConsonantsCount(const char *str);

/**
 * @brief Converts a string to lowercase.
 *
 * @param str The string to convert.
 * @return The lowercase equivalent of the string.
 */
char *toLower(const char *str);

/**
 * @brief Converts a string to uppercase.
 *
 * @param str The string to convert.
 * @return The uppercase equivalent of the string.
 */
char *toUpper(const char *str);

#endif