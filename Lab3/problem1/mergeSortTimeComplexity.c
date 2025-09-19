// C Program to implement merge Sort on character array of size 25 and analyze time required in ascending order
// Author - Vedika Udgir

#include <stdio.h>
#include <time.h>

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
        int mid = start + ((end - start) / 2);

        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        mergeSubarrays(a, start, mid, end);
    }
}

int main()
{
    clock_t start, end;
    double cpu_time_used;

    setRandomElementsInArray(25);
    printf("\nOriginal Array:\n");
    printArray();

    start = clock();
    mergeSort(inputArray, 0, 25);
    end = clock();

    printf("\nSorted Array (Ascending):\n");
    printArray();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for sorting = %f seconds\n", cpu_time_used);

    return 0;
}
