#include "dataStructers.h"

void bubbleSort(int *array, int arraySize)
{
    for (int passIndex = 0; passIndex < arraySize; passIndex++)
    {
        for (int elementIndex = 0; elementIndex < arraySize - 1; elementIndex++)
        {
            if (array[elementIndex] > array[elementIndex + 1])
            {
                int temp                = array[elementIndex];
                array[elementIndex]     = array[elementIndex + 1];
                array[elementIndex + 1] = temp;
            }
        }
    }
}