#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arrayLength = 0;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &arrayLength);
    int *arrayList = (int *) malloc(arrayLength * sizeof(int));
    if (arrayList == NULL)
    {
        printf("Memory not allocated.\n");
    }
    int currentIndex = 0;
    int element      = 0;
    int minElement   = INT_MAX;
    int maxElement   = INT_MIN;
    while (currentIndex < arrayLength)
    {
        printf("Enter the number to add to list:\n");
        scanf("%d", &element);
        printf("Adding %d in %d index\n", element, currentIndex);
        arrayList[currentIndex] = element;
        if (element >= maxElement)
        {
            maxElement = element;
        }
        if (element <= minElement)
        {
            minElement = element;
        }

        currentIndex++;
    }

    printf("\n");

    printf("The largest element in the array is %d\n", maxElement);
    printf("The smallest element in the array is %d\n", minElement);

    free(arrayList);
    return 0;
}