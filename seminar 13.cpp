// seminar 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//bubble sort
void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void bubbleSort(int* arr, size_t size)
{
    unsigned lastSwapedInd = size - 1;
    for (int i = 0; i < size; i++)
    {
        int currIterLastSwaped = 0;
        for (int j = 0; j < lastSwapedInd; j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap(arr[j], arr[j + 1]);
                currIterLastSwaped++;
            }
        }
        if (currIterLastSwaped==0)
        {
            return;
        }
        lastSwapedInd = currIterLastSwaped;
    }
}

void print(const int* arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

//selection sort
void selectionSort(int* arr, size_t size)
{
    for (int i = 0; i < size-1; i++)
    {
        int minElInd = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j]<arr[minElInd])
            {
                minElInd = j;
            }
        }
        if (minElInd!=i)
        {
            swap(arr[i], arr[minElInd]);
        }
    }
}

void insertionSort(int* arr, size_t size)
{
    for (int i = 1; i < size; i++)
    {
        int currEl = arr[i];
        int currInd = i - 1;
        while (currInd>=0&&arr[currInd]>currEl)
        {
            arr[currInd + 1] = arr[currInd];
            currInd--;
        }
        arr[currInd+1] = currEl;
    }
}
int main()
{
    constexpr size_t SIZE = 5;
    int arr[SIZE] = { 5,4,3,2,1 };
    /*bubbleSort(arr, SIZE);*/
    /*selectionSort(arr, SIZE);*/
    insertionSort(arr, SIZE);
    print(arr, SIZE);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
