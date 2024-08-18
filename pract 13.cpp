// pract 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task 01
int binarySearchInRow(const int* arr, size_t size, int el)
{
    int left = 0;
    int right = size - 1;
    while (left<=right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid]<el)
        {
            left = mid + 1;
        }
        else if (arr[mid]>el)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

void getElInd(int** mtx, int rowsCount, int colsCount, int el, int& rowInd, int& colInd)
{
    int left = 0;
    int right = rowsCount - 1;

    while (left<=right)
    {
        int mid = left + (right - left) / 2;
        int res = binarySearchInRow(mtx[mid], colsCount, el);
        if (res!=-1)
        {
            rowInd = mid;
            colInd = res;
            return;
        }
        else if (mtx[mid][colsCount-1]<el)
        {
            left = mid + 1;
        }
        else if (mtx[mid][0]>el)
        {
            right = mid - 1;
        }
    }
    rowInd = -1;
    colInd = -1;
}

//task 02
int getIndexOfInserted(int* arr, size_t size, int num)
{
    if (!arr || size==0)
    {
        return -1;
    }
    if (num<arr[0])
    {
        return 0;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (num>arr[i]&&num<=arr[i+1])
        {
            return i + 1;
        }
    }
    if (num>arr[size-1])
    {
        return size;
    }
}

//2 nachin
int getIndexToInsertBinary(int* arr, size_t size, int num)
{
    int left = 0;
    int right = size - 1;
    while (left<=right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid]>num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

//task 03
int findIndexOfMinusOne(int* X, int* Y, size_t n)
{
    if (!X||!Y||n==0)
    {
        return -1;
    }

    int left = 0;
    int right = n - 1;
    while (left<=right)
    {
        int mid = left + (right - left) / 2;
        if (X[mid]!=Y[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

//task 05
void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void cocktailSort(int* arr, size_t size)
{
    if (size<=1)
    {
        return;
    }

    int start = 0;
    int end = size - 1;
    bool swapped = true;

    while (swapped)
    {
        swapped = false;
        for (int i = start; i < end; i++)
        {
            if (arr[i]>arr[i+1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        end--;

        if (!swapped)
        {
            break;
        }

        swapped = false;

        for (int i = end; i > start; i--)
        {
            if (arr[i]<arr[i-1])
            {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        start++;
    }
}

void print(int* arr, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

//task 06
int findFirstMising(int* arr, size_t size)
{
    if (!arr || size==0)
    {
        return -1;
    }

    cocktailSort(arr, size);
    for (int i = 0; i < size-1; i++)
    {
        if (arr[i+1]!=arr[i]+1)
        {
            return arr[i] + 1;
        }
    }
    return arr[size-1]+1;
}

//task 07
int findKbiggest(int* arr, size_t size, int k)
{
    if (!arr || size==0 || k>size)
    {
        return -1;
    }

    cocktailSort(arr, size);
    return arr[size - k];
}

//2 nachin
int partition(int* arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j]>pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int findKLargestWithQuickSort(int* arr, size_t size, int k)
{
    if (!arr || size == 0 || k > size)
    {
        return -1;
    }

    int left = 0;
    int right = size - 1;

    while (left<=right)
    {
        int pivotInd = partition(arr, left, right);
        if (pivotInd==k-1)
        {
            return arr[pivotInd];
        }
        else if (pivotInd>k-1)
        {
            right = pivotInd - 1;
        }
        else
        {
            left = pivotInd + 1;
        }
    }
    return -1;
}

//task 08
int findMaxCandies(int* prices, size_t size, int k)
{
    if (!prices || size==0)
    {
        return 0;
    }
    cocktailSort(prices, size);
    int totalPrice = 0;
    int candies = 0;
    for (int i = 0; i < size; i++)
    {
        if (totalPrice+prices[i]<=k)
        {
            totalPrice += prices[i];
            candies++;
        }
        else
        {
            break;
        }
    }

    return candies;
}

void selectionSort(int* arr, size_t size)
{
    if (!arr||size==0)
    {
        return;
    }

    for (int i = 0; i < size-1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j]>arr[minInd])
            {
                minInd = j;
            }
        }
        if (minInd!=i)
        {
            swap(arr[i], arr[minInd]);
        }
    }
}

int countEven(int* arr, size_t size)
{
    if (!arr||size==0)
    {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%2==0)
        {
            count++;
        }
    }
    return count;
}
void sortEvenAndOdd(int* arr, size_t size)
{
    if (!arr||size==0)
    {
        return;
    }
    int evenCount = countEven(arr, size);
    int oddCount = size - evenCount;

    int* even = new int[evenCount];
    int* odd = new int[oddCount];
    int evenInd = 0;
    int oddInd = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i]%2==0)
        {
            even[evenInd] = arr[i];
            evenInd++;
        }
        else
        {
            odd[oddInd] = arr[i];
            oddInd++;
        }
    }

    cocktailSort(even, evenCount);
    selectionSort(odd, oddCount);
    for (int i = 0; i < evenCount; i++)
    {
        arr[i] = even[i];
    }
    for (int i = 0; i < oddCount; i++)
    {
        arr[i + evenCount] = odd[i];
    }

    delete[] even;
    delete[] odd;
}

//task 10
void printCouples(int* arr, int size)
{
    if (!arr || size==0)
    {
        return;
    }
    
    int count = size / 2;

    int* girls = new int[count];
    int* boys = new int[count];

    int girlsInd = 0;
    int boysInd = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%2==0)
        {
            girls[girlsInd] = arr[i];
            girlsInd++;
        }
        else
        {
            boys[boysInd] = arr[i];
            boysInd++;
        }
    }

    if (girlsInd != count || boysInd != count) 
    {
        delete[] boys;
        delete[] girls;
        return;
    }

    cocktailSort(girls, count);
    cocktailSort(boys, count);

    for (int i = 0; i < count; i++)
    {
        std::cout << boys[i] << ' ' << girls[i] << std::endl;
    }

    delete[] boys;
    delete[] girls;
}
int main()
{
    //task 01
    /*constexpr int rows = 3;
    constexpr int cols = 3;
    int** mtx = new int* [rows];
    mtx[0] =new int[cols] { 1,2,3 };
    mtx[1] = new int[cols] {4, 5, 6};
    mtx[2] = new int[cols] {7, 8, 9};
    int rowInd;
    int colInd;
    getElInd(mtx, rows, cols, 7, rowInd, colInd);
    std::cout << rowInd << ' ' << colInd << std::endl;*/

    //02
    //int arr[7] = { 1,2,5,6,7,9,10 };
    //std::cout << /*getIndexOfInserted(arr, 7,6 )*/ getIndexToInsertBinary(arr,7,11);
    
    //03
  /*  int X[4] = { 5,2,9,1 };
    int Y[5] = { 5,2,-1,9,1 };
    std::cout << findIndexOfMinusOne(X, Y, 4);*/

    //05
    /*int arr[5] = { 7,6,4,9,5 };
    cocktailSort(arr, 5);
    print(arr, 5);*/

    //06
    /*int arr[5] = { 0,6,3,2,1 };
    std::cout << findFirstMising(arr, 5);*/
    
    //07
 /*   int arr[7] = { 39,4,6,1,2,66,33 };
    std::cout << findKLargestWithQuickSort(arr, 7, 5);*//*findKbiggest(arr, 7, 3);*/

    //08
    /*int arr[7] = { 39, 4, 6, 1, 2, 66, 33 };
    std::cout << findMaxCandies(arr, 7, 40);*/

    //09
    /*int arr[6] = { 1,2,3,6,5,4 };
    sortEvenAndOdd(arr, 6);
    print(arr, 6);*/

    //10
    int people[14] = { 201, 186, 180, 186, 183, 185, 170, 161, 194, 197, 164, 175, 161, 186 };
    printCouples(people, 14);
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
