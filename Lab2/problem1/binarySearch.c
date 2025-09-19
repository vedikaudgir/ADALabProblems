// Using recursion, write a C program to implement binary search on integer array of size. The key value to be searched and integer array should be considered as input from the user and display the index position and memory address of key value.
//  Author - Vedika Udgir

#include <stdio.h>
#include <stdbool.h>

int inputArray[15];
int key;
bool found = false;

void readArray()
{
    for (int i = 0; i < 15; i++)
    {
        printf("\nEnter element %d ", i);
        scanf("%d", &inputArray[i]);
    }
}

void printArray()
{
    for (int i = 0; i < 15; i++)
    {
        printf("%4d", inputArray[i]);
    }
}

void setKey()
{
    printf("\nEnter element to find: ");
    scanf("%d", &key);
}

int getKey()
{
    return key;
}

void BinarySearch(int startIndex, int lastIndex, int key)
{
    int midIndex = (startIndex + lastIndex) / 2;

    if (inputArray[midIndex] == key)
    {
        found = true;
        printf("%d found at index %d\nAddress of %d = %p", key, midIndex, key, &key);
    }

    if (key > inputArray[midIndex])
    {
        BinarySearch(midIndex + 1, lastIndex, key);
    }
    else if (key < inputArray[midIndex])
    {
        BinarySearch(startIndex, midIndex - 1, key);
    }
}

bool checkNotFound()
{
    if (!found)
    {
        return false;
    }
    return true;
}

int main()
{
    readArray();
    printArray();
    setKey();
    BinarySearch(0, 14, getKey());
    if (!checkNotFound())
    {
        printf("Element not  found!");
    }
}
