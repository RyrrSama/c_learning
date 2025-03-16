#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int userInput;
    printf("Enter a number: ");
    int status   = scanf("%d", &userInput);
    bool isPrime = true;
    printf("status: %d\n", status);
    if (status != 1)
    {
        printf("Invaild input\n");
        return 1;
    }

    if (userInput <= 1)
    {
        isPrime = false;
    }

    else if ((userInput == 2) || (userInput == 3))
    {
        isPrime = true;
    }
    else if ((userInput % 2 != 0) && (userInput % 3 != 0))
    {
        isPrime = true;
    }
    else
    {
        isPrime = false;
    }

    if (isPrime)
    {
        printf("%d is a Prime Number\n", userInput);
    }
    else
    {
        printf("%d is not a Not Prime Number\n", userInput);
    }
    return 0;
}