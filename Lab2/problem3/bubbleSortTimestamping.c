// Write a C program to implement Bubble Sort and analyze time required on
// a. integer array of size 20 in ascending order.
// b. integer array of size 1000 in ascending order.
// c. integer array of size 10000 in ascending order.
// d. integer array of size 100000 in ascending order.
// e. integer array of size 1000000 in ascending order.
//
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

void bubbleSort(int index)
{
    for (int i = 0; i < index; i++)
    {
        int flag = 0;
        for (int j = 0; j < index - i - 1; j++)
        {
            if (inputArray[j] > inputArray[j + 1])
            {
                int swap = inputArray[j];
                inputArray[j] = inputArray[j + 1];
                inputArray[j + 1] = swap;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int main()
{
    srand(time(NULL));

    clock_t start20 = clock();
    setRandomElementsInArray(20);
    bubbleSort(20);
    clock_t end20 = clock();
    printf("\nTime taken for size 20: %ld nanoseconds\n", (end20 - start20) * 1000000000 / CLOCKS_PER_SEC);

    clock_t start1000 = clock();
    setRandomElementsInArray(1000);
    bubbleSort(1000);
    clock_t end1000 = clock();
    printf("\nTime taken for size 1000: %ld nanoseconds\n", (end1000 - start1000) * 1000000000 / CLOCKS_PER_SEC);

    clock_t start10000 = clock();
    setRandomElementsInArray(10000);
    bubbleSort(10000);
    clock_t end10000 = clock();
    printf("\nTime taken for size 10000: %ld nanoseconds\n", (end10000 - start10000) * 1000000000 / CLOCKS_PER_SEC);

    clock_t start100000 = clock();
    setRandomElementsInArray(100000);
    bubbleSort(100000);
    clock_t end100000 = clock();
    printf("\nTime taken for size 100000: %ld nanoseconds\n", (end100000 - start100000) * 1000000000 / CLOCKS_PER_SEC);

    clock_t start1000000 = clock();
    setRandomElementsInArray(1000000);
    bubbleSort(1000000);
    clock_t end1000000 = clock();
    printf("\nTime taken for size 1000000: %ld nanoseconds\n", (end1000000 - start1000000) * 1000000000 / CLOCKS_PER_SEC);

    return 0;
}
