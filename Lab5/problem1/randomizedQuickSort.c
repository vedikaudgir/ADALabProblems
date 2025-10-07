// C Program to implement randomized quick Sort on integer array of size 15 and analyze time required in ascending order
// Author - Vedika Udgir

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputArray[15] = {};

void printArray()
{
    for (int i = 0; i < 15; i++)
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

int partition_r(int a[], int start, int end)
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
        int pi = partition_r(a, start, end);

        quickSort(a, start, pi);
        quickSort(a, pi + 1, end);
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    setRandomElementsInArray(15);

    printf("\nOriginal Array:\n");
    printArray();

    start = clock();
    quickSort(inputArray, 0, 15);
    end = clock();

    printf("\nSorted Array (Ascending):\n");
    printArray();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for sorting = %f seconds\n", cpu_time_used);

    return 0;
}