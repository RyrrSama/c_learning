#include <stdio.h>
#include <stdlib.h>

#include "stringFuctions.h"

int main()
{
    int lenght = 0;
    puts("Enter a length of the string: ");
    scanf("%d", &lenght);
    char *string = (char *) malloc(lenght * sizeof(char));
    puts("Enter a string: ");
    scanf("%s", string);
    if (isPalindrome(string))
    {
        printf("The string %s is a palindrome.\n", string);
    }
    else
    {
        printf("The string %s is not a palindrome.\n", string);
    }
    return 0;
}