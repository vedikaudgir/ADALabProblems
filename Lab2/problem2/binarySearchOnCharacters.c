// Using recursion write a C program to implement binary search on character array of size 15. The key value to be searched and character array should be considered as input from the user and display the index position and memory address of key value.
//  Author - Vedika Udgir

#include <stdio.h>
#include <stdbool.h>

char inputArray[15];
char key;
bool found = false;

void readArray()
{
    for (int i = 0; i < 15; i++)
    {
        printf("\nEnter element %d: ", i);
        scanf(" %c", &inputArray[i]);
    }
}

void printArray()
{
    printf("\n");
    for (int i = 0; i < 15; i++)
    {
        printf("%4c", inputArray[i]);
    }
}

void setKey()
{
    printf("\nEnter element to find: ");
    scanf(" %c", &key);
}

int getKey()
{
    return key;
}

void binarySearch(int startIndex, int lastIndex, int key)
{
    int midIndex = (startIndex + lastIndex) / 2;

    if ((char)inputArray[midIndex] == (char)key)
    {
        found = true;
        printf("%c found at index %d\nAddress of %c = %p", key, midIndex, key, &key);
    }

    if ((char)key > (char)inputArray[midIndex])
    {
        binarySearch(midIndex + 1, lastIndex, key);
    }
    else if ((char)key < (char)inputArray[midIndex])
    {
        binarySearch(startIndex, midIndex - 1, key);
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
    binarySearch(0, 14, getKey());
    if (!checkNotFound())
    {
        printf("Element not  found!");
    }
}
