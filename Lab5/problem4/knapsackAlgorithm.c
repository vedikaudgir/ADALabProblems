// Implementing knapsack algorithm.
// Author - Vedika Udgir

#include <stdio.h>
#include <stdlib.h>
#define MAX 7

int value[MAX];
int weight[MAX];
float ratio[MAX];
int sackCapacity = 15;
int totalProfit = 0;

void readArray(int a[])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("\nEnter element %d: ", i);
        scanf(" %d", &a[i]);
    }
}

void printArray(int a[])
{
    printf("\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%4d", a[i]);
    }
}

void mergeSubarrays(int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int array1[n1], array2[n2];
    int array1value[n1], array2value[n2];
    int array1weight[n1], array2weight[n2];

    for (i = 0; i < n1; i++)
    {
        array1[i] = ratio[start + i];
        array1value[i] = value[start + i];
        array1weight[i] = weight[start + i];
    }
    for (j = 0; j < n2; j++)
    {
        array2[j] = ratio[mid + j + 1];
        array2value[j] = value[mid + j + 1];
        array2weight[j] = weight[mid + j + 1];
    }

    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
        if (array1[i] < array2[j])
        {
            ratio[k] = array1[i];
            value[k] = array1value[i];
            weight[k] = array1weight[i];
            i++;
        }
        else
        {
            ratio[k] = array2[j];
            value[k] = array2value[j];
            weight[k] = array2weight[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        ratio[k] = array1[i];
        value[k] = array1value[i];
        weight[k] = array1weight[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        ratio[k] = array2[j];
        value[k] = array2value[j];
        weight[k] = array2weight[j];
        j++;
        k++;
    }
}

void mergeSort(int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        mergeSubarrays(start, mid, end);
    }
}

void knapsack()
{
    int i, j;
    for (i = 0; i < MAX; i++)
    {
        ratio[i] = (float)value[i] / (float)weight[i];
    }
    mergeSort(0, MAX - 1);

    for (i = MAX - 1; i >= 0; i--)
    {
        if (weight[i] > sackCapacity)
        {
            break;
        }
        else
        {
            sackCapacity -= weight[i];
            totalProfit += value[i];
        }
    }
    printf("\nTotal profit = %d", totalProfit);
}

void main()
{
    printf("\nEnter values of 7 items: ");
    readArray(value);
    printArray(value);

    printf("\nEnter weights of 7 items: ");
    readArray(weight);
    printArray(weight);

    knapsack();
}