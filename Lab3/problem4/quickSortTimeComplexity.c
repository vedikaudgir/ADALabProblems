// C Program to implement quick Sort on character array of size 25 and analyze time required in ascending order
// Author - Vedika Udgir

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputArray[25] = {98, 23, 45, 14, 6, 67, 33, 42};

void printArray()
{
    for (int i = 0; i < 25; i++)
    {
        printf("%4d", inputArray[i]);
    }
    printf("\n");
}

// void setRandomElementsInArray(int index)
// {
//     for (int i = 0; i < index; i++)
//     {
//         inputArray[i] = rand() % 100;
//     }
// }

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
    double cpu_time_used;

    // setRandomElementsInArray(25);
    printf("\nOriginal Array:\n");
    printArray();

    start = clock();
    quickSort(inputArray, 0, 7);
    end = clock();

    printf("\nSorted Array (Ascending):\n");
    printArray();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for sorting = %f seconds\n", cpu_time_used);

    return 0;
}
