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
        printf("%8d", inputArray[i]);
    }
    printf("\n");
}

void setRandomElementsInArray(int index)
{
    for (int i = 0; i < index; i++)
    {
        inputArray[i] = rand() % 10000;
    }
}

void swap(int *n1, int *n2)
{
    int swap = *n1;
    *n1 = *n2;
    *n2 = swap;
}
int partition(int a[], int start, int end)
{
    int pivot = a[start];
    int i = start - 1, j = end + 1;

    while (1)
    {

        do
        {
            i++;
        } while (a[i] < pivot);

        do
        {
            j--;
        } while (a[j] > pivot);

        if (i >= j)
            return j;

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int setRandomPivot(int a[], int start, int end)
{
    srand(time(0));
    int random = start + rand() % (end - start);

    int temp = a[random];
    a[random] = a[start];
    a[start] = temp;

    return partition(a, start, end);
}

void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int pi = setRandomPivot(a, start, end);

        quickSort(a, start, pi);
        quickSort(a, pi + 1, end);
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
