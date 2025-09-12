// Write a Cpp program to implement Bubble Sort and analyze time required on
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

class BubbleSort
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

    void bubbleSort(int index)
    {
        for (int i = 0; i < index; i++)
        {
            bool flag = 0;
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
            if (flag = 0)
            {
                break;
            }
        }
    }
};

int main()
{
    BubbleSort obj;
    obj.setRandomElementsInArray(20);
    auto start20 = high_resolution_clock::now();
    obj.bubbleSort(20);
    auto end20 = high_resolution_clock::now();
    cout << endl
         << "Sorted Array is: ";

    auto duration20 = duration_cast<nanoseconds>(end20 - start20);

    cout << endl
         << "Time taken: " << duration20.count() << " nanoseconds\n";

    BubbleSort obj2;
    obj2.setRandomElementsInArray(1000);
    auto start1000 = high_resolution_clock::now();
    obj2.bubbleSort(1000);
    auto end1000 = high_resolution_clock::now();
    cout << endl
         << "Sorted Array is: ";

    auto duration1000 = duration_cast<nanoseconds>(end1000 - start1000);
    cout << endl
         << "Time taken: " << duration1000.count() << " nanoseconds\n";

    BubbleSort obj3;
    obj3.setRandomElementsInArray(10000);
    auto start10000 = high_resolution_clock::now();
    obj3.bubbleSort(10000);
    auto end10000 = high_resolution_clock::now();
    cout << endl
         << "Sorted Array is: ";

    auto duration10000 = duration_cast<nanoseconds>(end10000 - start10000);
    cout << endl
         << "Time taken: " << duration10000.count() << " nanoseconds\n";
}