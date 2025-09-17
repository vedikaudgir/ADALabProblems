// C Program to implement Selection Sort on character array of size 20
// and analyze time required in ascending order
// Author - Vedika Udgir

#include <stdio.h>
#include <time.h>

char inputArray[20];

void readArray()
{
    for (int i = 0; i < 20; i++)
    {
        printf("Enter element %d: ", i);
        scanf(" %c", &inputArray[i]);
    }
}

void printArray()
{
    for (int i = 0; i < 20; i++)
    {
        printf("%4c", inputArray[i]);
    }
    printf("\n");
}

void selectionSort()
{
    int i, j, minIndex;
    char temp;

    for (i = 0; i < 19; i++)
    {
        minIndex = i;
        for (j = i + 1; j < 20; j++)
        {
            if (inputArray[j] < inputArray[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            temp = inputArray[i];
            inputArray[i] = inputArray[minIndex];
            inputArray[minIndex] = temp;
        }
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    readArray();
    printf("\nOriginal Array:\n");
    printArray();

    start = clock();
    selectionSort();
    end = clock();

    printf("\nSorted Array (Ascending):\n");
    printArray();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for sorting = %f seconds\n", cpu_time_used);

    return 0;
}
