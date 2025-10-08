// Write a C program to implement merge Sort and analyze time required on
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

void mergeSubarrays(int a[], int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int array1[n1], array2[n2];

    for (i = 0; i < n1; i++)
    {
        array1[i] = a[start + i];
    }
    for (j = 0; j < n2; j++)
    {
        array2[j] = a[mid + j + 1];
    }

    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
        if (array1[i] < array2[j])
        {
            a[k] = array1[i];
            i++;
        }
        else
        {
            a[k] = array2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = array1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = array2[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        mergeSubarrays(a, start, mid, end);
    }
}

int main()
{
    clock_t start, end;
    double time_taken;
    setRandomElementsInArray(20);
    start = clock();
    mergeSort(inputArray, 0, 20);
    end = clock();
    printf("\nSorted Array is: ");
    printArray(20);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    setRandomElementsInArray(1000);
    start = clock();
    mergeSort(inputArray, 0, 1000);
    end = clock();
    printf("\nSorted Array is: ");
    printArray(1000);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    setRandomElementsInArray(10000);
    start = clock();
    mergeSort(inputArray, 0, 10000);
    end = clock();
    printf("\nSorted Array is: ");
    printArray(10000);
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}
