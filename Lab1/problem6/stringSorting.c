// C Program to implement Bubble Sort on array of strings of size 5
// in ascending order
// Author - Vedika Udgir

#include <stdio.h>
#include <string.h>

char strArray[5][20];

void readArray()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Enter string %d: ", i);
        scanf("%19s", strArray[i]);
    }
}

void printArray()
{
    printf("\nArray of Strings:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", strArray[i]);
    }
}

void bubbleSortStrings()
{
    char temp[20];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (strcmp(strArray[j], strArray[j + 1]) > 0)
            {
                strcpy(temp, strArray[j]);
                strcpy(strArray[j], strArray[j + 1]);
                strcpy(strArray[j + 1], temp);
            }
        }
    }
}

int main()
{
    readArray();
    printf("\nOriginal Array:");
    printArray();

    bubbleSortStrings();

    printf("\nSorted Array (Ascending):");
    printArray();

    return 0;
}
