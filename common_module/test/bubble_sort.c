#include <stdio.h>
#include <stdlib.h>

#include "dataStructers.h"

int main()
{
    printf("Enter the number of elements in the array: ");
    int arraySize;
    scanf("%d", &arraySize);
    int *array = (int *) calloc(arraySize, sizeof(int));
    for (int i = 0; i < arraySize; i++)
    {
        printf("Enter a element to add into array: \n");
        scanf("%d", &array[i]);
    }
    bubbleSort(array, arraySize);
    printf("The sorted array is: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }
    free(array);
    return 0;
}