#include <stdio.h>

int main()
{
    int sumOfNumber = 0;
    int userInput   = 0;
    puts("Enter The number to caluctate the sum of numbers:");
    scanf("%d", &userInput);
    while (userInput != 0)
    {
        sumOfNumber += userInput % 10;
        userInput = userInput / 10;
    }
    puts("The sum of the numbers is:");
    printf("%d", sumOfNumber);
    return 0;
}