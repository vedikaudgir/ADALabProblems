// C Program to implement Bubble Sort on character array of size 20
// and analyze time required in ascending order
// Author - Vedika Udgir

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

char inputArray[20];

void readArray()
{
    for (int i = 0; i < 20; i++)
    {
        printf("\nEnter element %d: ", i);
        scanf(" %c", &inputArray[i]);
    }
}

void printArray()
{
    printf("\nArray elements:\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%4c", inputArray[i]);
    }
    printf("\n");
}

void bubbleSort()
{
    char temp;
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19 - i; j++)
        {
            if (inputArray[j] > inputArray[j + 1])
            {
                temp = inputArray[j];
                inputArray[j] = inputArray[j + 1];
                inputArray[j + 1] = temp;
            }
        }
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    readArray();
    printf("\nOriginal Array:");
    printArray();

    start = clock();
    bubbleSort();
    end = clock();

    printf("\nSorted Array (Ascending):");
    printArray();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for sorting = %f seconds\n", cpu_time_used);

    return 0;
}
