//Using recursion write a C program to implement binary search on character array of size 15. The key value to be searched and character array should be considered as input from the user and display the index position and memory address of key value.
// Author - Vedika Udgir

#include <iostream>
using namespace std;

class BinarySearchOnCharacters
{
private:
    char inputArray[15];
    char key;
            bool found = false;

public:
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
        cout << endl;
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
        int midIndex = (startIndex + lastIndex)/2;

        if ((char)inputArray[midIndex] == (char)key)
        {
            found = true;
            printf("%c found at index %d\nAddress of %c = %p", key, midIndex, key, &key);
        }

        if ((char)key > (char)inputArray[midIndex] )
        {
            binarySearch(midIndex+1, lastIndex, key);
        }
        else if ((char)key < (char)inputArray[midIndex] )
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
    BinarySearchOnCharacters(){}
    ~BinarySearchOnCharacters(){}
};

int main()
{
    BinarySearchOnCharacters obj;

    obj.readArray();
    obj.printArray();
    obj.setKey();
    obj.binarySearch(0, 14, obj.getKey());
    if(!obj.checkNotFound())
    {
        cout << "Element not  found!";
    }
}