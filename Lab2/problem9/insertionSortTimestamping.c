// Write a C program to implement Insertion Sort and analyze time required on
// a. integer array of size 20 in ascending order.
// b. integer array of size 1000 in ascending order.
// c. integer array of size 10000 in ascending order.
// d. integer array of size 100000 in ascending order.
// e. integer array of size 1000000 in ascending order.

// Author - Vedika Udgir.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputArray[1000000];
int key;

void readArray(int index)
{
    for (int i = 0; i < index; i++)
    {
        printf("\nEnter element %d ", i);
        scanf("%d", &inputArray[i]);
    }
}

void printArray(int index)
{
    for (int i = 0; i < index; i++)
    {
        printf("%4d", inputArray[i]);
    }
}

void setRandomElementsInArray(int index)
{
    for (int i = 0; i < index; i++)
    {
        inputArray[i] = rand() % 100;
    }
}

void setKey()
{
    printf("\nEnter element to find: ");
    scanf("%d", &key);
}

void insertion(int index)
{
    for (int i = 1; i < index; i++)
    {
        int temp = inputArray[i];
        int j = i - 1;

        while (j >= 0 && inputArray[j] > temp)
        {
            inputArray[j + 1] = inputArray[j];
            j--;
        }
        inputArray[j + 1] = temp;
    }
}

int main()
{
    clock_t start, end;
    double time_taken;
    setRandomElementsInArray(20);
    start = clock();
    insertion(20);
    end = clock();
    printf("\nSorted Array is: ");
    printArray(20);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    setRandomElementsInArray(1000);
    start = clock();
    insertion(1000);
    end = clock();
    printf("\nSorted Array is: ");
    printArray(1000);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    setRandomElementsInArray(10000);
    start = clock();
    insertion(10000);
    end = clock();
    printf("\nSorted Array is: ");
    printArray(10000);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}
