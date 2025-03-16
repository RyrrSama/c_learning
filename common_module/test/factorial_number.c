#include <stdio.h>

int factorial(int n);

int main()
{
    int userInput;
    printf("Enter a postive numer to find factorial: ");
    int status = scanf("%d", &userInput);

    if (status != 1)
    {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    if (userInput < 0)
    {
        printf("Please enter a positive number.\n");
        return 1;
    }

    int factorialValue = factorial(userInput);
    printf("Factorial of %d is %d\n", userInput, factorialValue);
    return 0;
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}