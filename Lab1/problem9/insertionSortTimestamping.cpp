// Write a Cpp program to implement Insertion Sort and analyze time required on
// a. integer array of size 20 in ascending order.
// b. integer array of size 1000 in ascending order.
// c. integer array of size 10000 in ascending order.
// d. integer array of size 100000 in ascending order.
// e. integer array of size 1000000 in ascending order.

// Author - Vedika Udgir.

#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

class SelectionSort
{
private:
    int inputArray[1000000];
    int key;

public:
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

    void selection(int index)
    {
        for (int i = 0; i < index - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < index; j++)
            {
                if (inputArray[j] < inputArray[min])
                {
                    min = j;
                }
            }
            if (min != i)
            {
                int swap = inputArray[i];
                inputArray[i] = inputArray[min];
                inputArray[min] = swap;
            }
        }
    }
};

int main()
{
    SelectionSort obj;
    obj.setRandomElementsInArray(20);
    auto start20 = high_resolution_clock::now();
    obj.selection(20);
    auto end20 = high_resolution_clock::now();
    cout << endl
         << "Sorted Array is: ";

    auto duration20 = duration_cast<nanoseconds>(end20 - start20);

    cout << endl
         << "Time taken: " << duration20.count() << " nanoseconds\n";

    SelectionSort obj2;
    obj2.setRandomElementsInArray(1000);
    auto start1000 = high_resolution_clock::now();
    obj2.selection(1000);
    auto end1000 = high_resolution_clock::now();
    cout << endl
         << "Sorted Array is: ";

    auto duration1000 = duration_cast<nanoseconds>(end1000 - start1000);
    cout << endl
         << "Time taken: " << duration1000.count() << " nanoseconds\n";

    SelectionSort obj3;
    obj3.setRandomElementsInArray(10000);
    auto start10000 = high_resolution_clock::now();
    obj3.selection(10000);
    auto end10000 = high_resolution_clock::now();
    cout << endl
         << "Sorted Array is: ";

    auto duration10000 = duration_cast<nanoseconds>(end10000 - start10000);
    cout << endl
         << "Time taken: " << duration10000.count() << " nanoseconds\n";
}