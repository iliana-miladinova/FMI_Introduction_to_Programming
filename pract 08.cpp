// pract 08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task 01
int getBitByPOsition(int num, int pos)
{
    int mask = 1<<pos;
    int res = num & mask;
    res >>= pos;
    return res;
}

//task 02
int getNumByPOsition(int num, int pos, int len)
{
    /*num >>= len;
    int mask = 1;
    mask <<= pos;
    return num & (mask - 1);*/
    num >>= (len-1);
    int mask = 1;
    mask <<= pos;
    return num & (mask - 1);

    /*int mask = (1 << len) - 1;
    mask<<=pos;
    return (num & mask) >> pos;*/
}

//task 03
int encode(int num, int key)
{
    return num ^ key;
}

int decode(int code, int key)
{
    return code ^ key;
}

//task 04
void swap(int& num1, int& num2)
{
    num1 ^= num2;
    num2 ^= num1;
    num1 ^= num2;
}

//task 05 
int changeBit(int num, int pos, int bit)
{
    int mask = 1 << pos;
    if (bit==1)
    {
        num |= mask;
    }
    else
    {
        mask = ~mask;
        num &= mask;
    }
    return num;
}

//task 06
//int countOnes(int num)
//{
//    int mask = 1;
//    int count = 0;
//    while (num)
//    {
//        num = num & (num - 1);
//        mask <<= 1;
//    }
//    return count;
//}
//
//bool isPermutation(int num1, int num2)
//{
//    return countOnes(num1) == countOnes(num2);
//}

//vtori nachin
bool isPermutation(int num1, int num2)
{
    int mask = num1 ^ num2;
    int count = 0;
    while (mask)
    {
        if (mask%2!=0)
        {
            count++;
        }
        mask /= 2;
    }
    return (mask % 2) == 0;
}
//task 07
int toggleBit(int num, int pos)
{
    int mask = 1 << pos;
    return num ^ mask;
}
//task 08
void printSubsets(const int arr[], int size, int mask)
{
    std::cout << "{ ";
    for (int i = size-1; i >= 0; i--)
    {
        /*if (mask&&(1<<i))
        {
            std::cout << arr[i] << ' ';
        }*/
        if (mask%2!=0)
        {
            std::cout << arr[i] << ' ';
        }
        mask /= 2;
    }
    std::cout<<'}'<<std::endl;
}
int powerOfTwo(int pow)
{
    return 1 << pow;
}

void generateSubset(const int arr[], int size)
{
    int combinations = powerOfTwo(size);
    for (int i = 0; i < combinations; i++)
    {
        printSubsets(arr, size, i);
    }
}
int main()
{
    /*std::cout << getBitByPOsition(9, 2) << std::endl;
    std::cout << getNumByPOsition(16, 4, 3)<<std::endl;
    std::cout << encode(10, 51932) << std::endl;
    std::cout << decode(51926, 51932) << std::endl;*/
    /*int num1 = 120;
    int num2 = 2;
    swap(num1, num2);
    std::cout << num1 << ' ' << num2 << std::endl;
    std::cout << changeBit(120, 4, 0) << std::endl;
    std::cout << isPermutation(7, 11) << std::endl;
    std::cout << toggleBit(120, 2);*/
    int arr[3] = { 1,2,3 };
    generateSubset(arr, 3);
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
