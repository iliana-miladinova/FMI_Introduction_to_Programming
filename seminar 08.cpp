// seminar 08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isEven(int num)
{
    int mask = 1;
    return !(num & mask);
}

unsigned powerOfTwo(unsigned k)
{
    if (k>31)
    {
        return 0;
    }
    return 1 << k;
}

unsigned makeBitZero(unsigned n, unsigned ind)
{
    unsigned mask = 1;
    mask <<= ind;
    mask = ~mask;
    return n & mask;
}

unsigned makeBitOne(unsigned n, unsigned ind)
{
    unsigned mask = 1;
    mask <<= ind;
    return n | mask;
}

bool checkBit(unsigned n, unsigned ind)
{
    unsigned mask = 1;
    mask <<= ind;
    return (n & mask) == mask;
}

unsigned toggleBit(unsigned n, unsigned ind)
{
    unsigned mask = 1;
    mask <<= ind;
    return n ^ mask;
}

//task 01
int getSingleNum(const int arr[], int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res ^= arr[i];
    }
    return res;
}

//task 02
//unsigned countOnesInBinary(int num)
//{
//    unsigned count = 0;
//    int mask = 1;
//    while (num != 0)
//    {
//        if ((num&mask)==mask)
//        {
//            count++;
//            
//        }
//        num >>= 1;
//    }
//    return count;
//}

//vtori nachin
unsigned countOnesInBinary(int num)
{
    unsigned count = 0;
    while (num)
    {
        num = num & (num - 1);
        count++;
    }
    return count;
}



//task 03
//int changeRightBit(int num)
//{
//    int bit = 0;
//    while (!(checkBit(num,bit)))
//    {
//        bit++;
//    }
//    return makeBitZero(num, bit);
//}

//vtori nachin
int changeRightBit(int num)
{
    return num & (num - 1);
}

//04
//int getLastKbitsOfNum(int num, int k)
//{
//    int res = 0;
//    int mask = 1;
//    for (int i = 0; i < k; i++)
//    {
//        res += (num & mask);
//        mask <<= 1;
//    }
//    return res;
//}

//vtori nachin
int getLastKbitsOfNum(int num, int k)
{
    int mask = (1 << k) - 1;
    return num & mask;
}

//05
//int getStartBit(int num1, int num2)
//{
//    int bit = 0;
//    while (checkBit(num1,bit)!=checkBit(num2,0))
//    {
//        bit++;
//    }
//    return bit;
//}
//
//bool isNum2InNum1(int num1, int num2)
//{
//    int bit=getStartBit(num1, num2);
//    num2 <<= bit;
//    return (num1 & num2) == num2;
//}

unsigned getLenInBinary(int num)
{
    unsigned len = 0;
    while (num!=0)
    {
        len++;
        num >>= 1;
    }
    return len;
}

int getStartBit(int num1, int num2)
{
    int bit = 0;
    while (checkBit(num1, bit) != checkBit(num2, 0))
    {
        bit++;
    }
    int lenNum2 = getLenInBinary(num2);
    for (int i = 1; i < lenNum2; i++)
    {
        if (checkBit(num2,i)!=checkBit(num1,bit+i))
        {
            bit = getStartBit(num1, num2);
        }
    }
    if (bit>31)
    {
        bit = -1;
    }
    return bit;
}



bool isNum2InNum1(int num1, int num2)
{
    /*unsigned num2Len = getLenInBinary(num2);
    unsigned mask = (1 << num2Len) - 1;
    while (num1>=num2)
    {
        if ((num1&mask)==num2)
        {
            return true;
        }
        num1 >>= 1;
    }
    return false;*/
    /*int bit = getStartBit(num1, num2);
    num2 <<= bit;
    return (num1 & num2) == num2;*/

    unsigned num2Len = getLenInBinary(num2);
    unsigned mask = (1 << num2Len) - 1;

    while (num1 >= (1 << (num2Len - 1))) 
    {
        if ((num1 & mask) == num2)
        {
            return true;
        }
        num1 >>= 1;
    }

    return false;
}

//06
int getPowerOfTwo(int num)
{
    return 1 << num;
}

void printSubsets(const int arr[], int size, int mask)
{
    std::cout << "{ ";
    for (int i = size - 1; i >= 0; i--)
    {
        if (mask % 2 != 0)
        {
            std::cout << arr[i] << ' ';
        }
        mask /= 2;
    }
    std::cout << "}" << std::endl;
}
void generateSubsets(const int arr[], int size)
{
    int combinations = powerOfTwo(size);
    for (int i = 0; i < combinations; i++)
    {
        printSubsets(arr, size, i);
    }
}

int* findSets(const int arr[], size_t N) {
    if (N == 0) {
        int* result = new int[2] {0, 0}; // Special case: empty input
        return result;
    }

    int totalSubsets = getPowerOfTwo(N)-1;
    int estimatedSize = totalSubsets * (N + 1) + 2; // Estimation for the required memory
    int* result = new int[estimatedSize];
    int index = 0;

    for (unsigned mask = 1; mask < powerOfTwo(N); mask++)
    {
        for (size_t i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                result[index++] = arr[i];
            }
        }
        result[index++] = 0; // Separator
    }
    result[index++] = 0; // End of last subset
    result[index] = 0;   // Double zero terminator

    return result;
}


void printSets(const int* sets) {
    while (*sets != 0 || *(sets + 1) != 0) {
        if (*sets == 0) {
            std::cout << "}, { ";
        }
        else {
            std::cout << *sets << " ";
        }
        sets++;
    }
    std::cout << "}" << std::endl;
}

int main()
{
   /* std::cout << isEven(-4) << std::endl;;
    std::cout << makeBitZero(6, 2) << std::endl;    
    std::cout << checkBit(3, 2) << std::endl;   
    std::cout << toggleBit(9, 2) << std::endl;  
    int arr[5] = { 4,1,2,1,2 };
    std::cout << getSingleNum(arr, 5) << std::endl;*/   
    /*std::cout << countOnesInBinary(13) << std::endl;
    std::cout << changeRightBit(12) << std::endl;*/
    /*std::cout << getLastKbitsOfNum(189, 4) << std::endl;*/
    /*std::cout << isNum2InNum1(13, 12);*/
    /*int arr[5] = { 1,2,3,4,5 };
    generateSubsets(arr, 5);*/
    int arr[] = { 1, 2, 3 ,4,5};
    size_t N = sizeof(arr) / sizeof(arr[0]);

    int* result = findSets(arr, N);
    std::cout << "{ ";
    printSets(result);

    delete[] result;
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
