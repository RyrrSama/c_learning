#include "stringFuctions.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int strLenght;
    puts("Enter the string lenght:");
    scanf("%d", &strLenght);
    puts("Enter the string:");
    char *srcString = (char *) malloc(strLenght * sizeof(char));
    scanf("%s", srcString);
    printf("The number of vowels in the string is: %d\n",
           getVolwelsCount(srcString));
    printf("The number of consonants in the string is: %d\n",
           getConsonantsCount(srcString));
    free(srcString);
    return 0;
}