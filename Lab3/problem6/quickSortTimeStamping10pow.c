// Write a C program to implement quick Sort and analyze time required on
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

void printArray(int index)
{
    for (int i = 0; i < index; i++)
    {
        printf("%4d", inputArray[i]);
    }
    printf("\n");
}

void setRandomElementsInArray(int index)
{
    for (int i = 0; i < index; i++)
    {
        inputArray[i] = rand() % 100;
    }
}

void swap(int *n1, int *n2)
{
    int swap = *n1;
    *n1 = *n2;
    *n2 = swap;
}
int setPivot(int a[], int start, int end)
{
    int p = a[start];
    int i = start;
    int j = end;

    while (i < j)
    {
        while (a[i] <= p && i <= end - 1)
        {
            i++;
        }
        while (a[j] > p && j >= start + 1)
        {
            j--;
        }
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[start], &a[j]);
    return j;
}

void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int newPivot = setPivot(a, start, end);

        quickSort(a, start, newPivot - 1);
        quickSort(a, newPivot + 1, end);
    }
}

int main()
{
    clock_t start, end;
    double time_taken;
    setRandomElementsInArray(20);
    start = clock();
    quickSort(inputArray, 0, 20);
    end = clock();
    printf("\nSorted Array is: ");
    printArray(20);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    setRandomElementsInArray(1000);
    start = clock();
    quickSort(inputArray, 0, 1000);
    end = clock();
    printf("\nSorted Array is: ");
    printArray(1000);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    setRandomElementsInArray(10000);
    start = clock();
    quickSort(inputArray, 0, 10000);
    end = clock();
    printf("\nSorted Array is: ");
    printArray(10000);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}
