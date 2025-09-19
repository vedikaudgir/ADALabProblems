// C Program to implement Insertion Sort on character array of size 20 in ascending order
// Author - Vedika Udgir

#include <stdio.h>

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

void insertionSort()
{
    int i, j;
    char key;

    for (i = 1; i < 20; i++)
    {
        key = inputArray[i];
        j = i - 1;

        while (j >= 0 && inputArray[j] > key)
        {
            inputArray[j + 1] = inputArray[j];
            j = j - 1;
        }
        inputArray[j + 1] = key;
    }
}

int main()
{
    readArray();

    printf("\nOriginal Array:\n");
    printArray();

    insertionSort();

    printf("\nSorted Array (Ascending):\n");
    printArray();

    return 0;
}
