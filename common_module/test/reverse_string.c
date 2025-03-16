#include <stdio.h>
#include <stdlib.h>

int stringLength(char *inputString);
void reverseString(char *inputString, char *reversedString, int length);

int main()
{

    char inputString[20];
    printf("Enter a string to reverse: ");
    int status = scanf("%s", inputString);

    if (status != 1)
    {
        printf("Invalid input. Please enter a string.\n");
        return 1;
    }
    int length = stringLength(inputString);

    char *reversedString = (char *) malloc(length * sizeof(char));
    reverseString(inputString, reversedString, length);
    printf("Reversed string is: %s\n", reversedString);
    free(reversedString);
    return 0;
}

int stringLength(char *string)
{
    int lenght = 0;
    while (string[lenght] != '\0')
    {
        lenght++;
    }
    return lenght;
}
void reverseString(char *inputString, char *reversedStr, int length)
{

    for (int i = length; i > 0; i--)
    {
        reversedStr[length - i] = inputString[i - 1];
    }
    reversedStr[length] = '\0';
}