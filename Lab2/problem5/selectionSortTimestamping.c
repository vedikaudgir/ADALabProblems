// Write a C program to implement Selection Sort and analyze time required on
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

struct SelectionSort
{
    int inputArray[100000];
    int key;
};

void readArray(struct SelectionSort *obj, int index)
{
    for (int i = 0; i < index; i++)
    {
        printf("\nEnter element %d ", i);
        scanf("%d", &obj->inputArray[i]);
    }
}

void printArray(struct SelectionSort *obj, int index)
{
    for (int i = 0; i < index; i++)
    {
        printf("%4d", obj->inputArray[i]);
    }
}

void setRandomElementsInArray(struct SelectionSort *obj, int index)
{
    for (int i = 0; i < index; i++)
    {
        obj->inputArray[i] = rand() % 100;
    }
}

void setKey(struct SelectionSort *obj)
{
    printf("\nEnter element to find: ");
    scanf("%d", &obj->key);
}

void selection(struct SelectionSort *obj, int index)
{
    for (int i = 0; i < index - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < index; j++)
        {
            if (obj->inputArray[j] < obj->inputArray[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int swap = obj->inputArray[i];
            obj->inputArray[i] = obj->inputArray[min];
            obj->inputArray[min] = swap;
        }
    }
}

int main()
{
    struct SelectionSort obj;
    setRandomElementsInArray(&obj, 20);
    clock_t start20 = clock();
    selection(&obj, 20);
    clock_t end20 = clock();
    double duration20 = ((double)(end20 - start20)) / CLOCKS_PER_SEC * 1e9;
    printf("\nTime taken: %.0f nanoseconds\n", duration20);

    struct SelectionSort obj2;
    setRandomElementsInArray(&obj2, 1000);
    clock_t start1000 = clock();
    selection(&obj2, 1000);
    clock_t end1000 = clock();
    double duration1000 = ((double)(end1000 - start1000)) / CLOCKS_PER_SEC * 1e9;
    printf("\nTime taken: %.0f nanoseconds\n", duration1000);

    struct SelectionSort obj3;
    setRandomElementsInArray(&obj3, 10000);
    clock_t start10000 = clock();
    selection(&obj3, 10000);
    clock_t end10000 = clock();
    double duration10000 = ((double)(end10000 - start10000)) / CLOCKS_PER_SEC * 1e9;
    printf("\nTime taken: %.0f nanoseconds\n", duration10000);

    return 0;
}
