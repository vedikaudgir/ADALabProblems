// Write a C program that analyzes time for best case scenario for Merge Sort and Quick Sort.
// Author - Vedika Udgir

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int inputArray[25];

void printArray()
{
    for (int i = 0; i < 25; i++)
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
void mergeSubarrays(int a[], int startMergeSort, int mid, int endMergeSort)
{
    int i, j, k;
    int n1 = mid - startMergeSort + 1;
    int n2 = endMergeSort - mid;

    int array1[n1], array2[n2];

    for (i = 0; i < n1; i++)
    {
        array1[i] = a[startMergeSort + i];
    }
    for (j = 0; j < n2; j++)
    {
        array2[j] = a[mid + j + 1];
    }

    i = 0;
    j = 0;
    k = startMergeSort;
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

void mergeSort(int a[], int startMergeSort, int endMergeSort)
{
    if (startMergeSort < endMergeSort)
    {
        int mid = startMergeSort + ((endMergeSort - startMergeSort) / 2);

        mergeSort(a, startMergeSort, mid);
        mergeSort(a, mid + 1, endMergeSort);
        mergeSubarrays(a, startMergeSort, mid, endMergeSort);
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
    clock_t startMergeSort, endMergeSort;
    clock_t startQuickSort, endQuickSort;
    double cpu_time_used_for_merge_sort, cpu_time_used_for_quick_sort;

    setRandomElementsInArray(25);
    selectionSort();

    printf("\nOriginal Array:\n");
    printArray();

    startMergeSort = clock();
    mergeSort(inputArray, 0, 25);
    endMergeSort = clock();

    cpu_time_used_for_merge_sort = ((double)(endMergeSort - startMergeSort)) / CLOCKS_PER_SEC;
    printf("\nTime taken by merge sort = %f seconds\n", cpu_time_used_for_merge_sort);

    startQuickSort = clock();
    quickSort(inputArray, 0, 25);
    endQuickSort = clock();

    cpu_time_used_for_quick_sort = ((double)(endQuickSort - startQuickSort)) / CLOCKS_PER_SEC;
    printf("\nTime taken by quick sort = %f seconds\n", cpu_time_used_for_quick_sort);

    return 0;
}
