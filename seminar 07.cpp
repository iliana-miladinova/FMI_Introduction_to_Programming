// seminar 07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
unsigned fromBinaryToDecimal(unsigned num)
{
    unsigned res = 0;
    unsigned mult = 1;
    while (num != 0)
    {
        res += (num % 10) * mult;
        mult *= 2;
        num /= 10;
    }
    return res;
}

unsigned fromDecimalToBinary(unsigned num)
{
    unsigned res = 0;
    unsigned mult = 1;
    while (num != 0)
    {
        if (num%2==1)
        {
            res += mult;
        }
        mult *= 10;
        num /= 2;
    }
    return res;
}

//from random to random
unsigned getIndexFromSymbol(char ch)
{
    if (ch>='0'&&ch<='9')
    {
        return ch - '0';
    }
    else if (ch>='A'&&ch<='Z')
    {
        return (ch - 'A') + 10;
    }
    else
    {
        return -1;
    }
}

char getSymbolFromIndex(unsigned ind)
{
    if (ind>=0&&ind<=9)
    {
        return ind + '0';
    }
    else
    {
        return (ind - 10) + 'A';
    }
    return 0;
}

void print(const char arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i]<<' ';
    }
    std::cout<<std::endl;
}

unsigned fromRandomToDecimal(const char from[], size_t size, unsigned k)
{
    unsigned res = 0;
    for (int i = size-1, mult=1; i >= 0; i--, mult*=k)
    {
        res += getIndexFromSymbol(from[i]) * mult;
    }
    return res;
}

void fromDecimalToRandom(unsigned num, char to[], size_t len, unsigned k)
{
    for (int arrayIter=len-1; arrayIter >= 0; arrayIter--)
    {
        int ind = num % k;
        char current = getSymbolFromIndex(ind);
        to[arrayIter] = current;
        num /= k;
    }
}

void fromRandomToRandom(const char from[], size_t len1, unsigned k, char to[], size_t len2, unsigned n)
{
    unsigned int decimal = fromRandomToDecimal(from, len1, k);
    fromDecimalToRandom(decimal, to, len2, n);
}
int main()
{
    std::cout << fromBinaryToDecimal(10110) << std::endl;
    std::cout << fromDecimalToBinary(30) << std::endl;
    constexpr int SIZE = 5;
    {
        char from[] = { '0', 'A', 'A','B', '3' };
        unsigned n = fromRandomToDecimal(from, SIZE, 16); //AAB3 in hex to decimal;
        std::cout << n << std::endl;;

    }
    {
        char to[SIZE] = {};
        fromDecimalToRandom(1234, to, SIZE, 16); //124 in decimal to hex;
        print(to, SIZE);
    }

    {
        char from[SIZE] = { '0', '0', 'A','B', '3' };

        char to[SIZE];
        //init(to, SIZE, '0');

        fromRandomToRandom(from, SIZE, 16, to, SIZE, 10);

        print(to, SIZE);
    }
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
