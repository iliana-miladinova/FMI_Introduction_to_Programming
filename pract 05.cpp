// pract 05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task 01
void swap(int& n1, int& n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

//task 02
unsigned countDigits(int num)
{
    unsigned count = 0;
    while (num != 0)
    {
        count++;
        num /= 10;
    }
    return count;
}

int reverse(int num)
{
    int newNum = 0;
    while (num != 0)
    {
        newNum = newNum * 10 + num % 10;
        num /= 10;
    }
    return newNum;

}

unsigned& removeDigitByPosition(unsigned& n, unsigned position)
{
    unsigned digitsCount = countDigits(n);
    unsigned newNum = 0;
    for (unsigned i = digitsCount; i >= 1; i--)
    {
        if (i!=position)
        {
            newNum = newNum * 10 + n % 10;
        }
        n /= 10;
    }
    n=reverse(newNum);
    return n;
}

//task 05
int getGCD(int n1, int n2)
{
    if (n1 < n2)
    {
        swap(n1, n2);
    }
    while (n2 != 0)
    {
        int res = n1 % n2;
        n1 = n2;
        n2 = res;
    }
    return n1;
}

void simplifyFraction(int& n1, int& n2)
{
    int gcd = getGCD(n1, n2);
    n1 /= gcd;
    n2 /= gcd;
}

void sumFractions(int& numinator1, int& denuminator1, int& numinator2, int& denuminator2)
{
    if (denuminator1==denuminator2)
    {
        numinator1 = numinator1 + numinator2;
        simplifyFraction(numinator1, denuminator1);
    }
    simplifyFraction(numinator1, denuminator1);

    simplifyFraction(numinator2, denuminator2);
    if (denuminator1==denuminator2)
    {
        numinator1 = numinator1 + numinator2;
        simplifyFraction(numinator1, denuminator1);
    }

    std::cout << numinator1 << ' ' << denuminator1<<std::endl;
}

//task 04
int getDigitByPosition(unsigned num, unsigned pos)
{
    int digitsCount = countDigits(num);
    if (digitsCount<pos)
    {
        return -1;
    }
    for (unsigned i = digitsCount; i >= 1; i--)
    {
        if (i==pos)
        {
            return num % 10;
        }
        num /= 10;
    }
}

unsigned& includeDigitInPosition(unsigned& num, unsigned pos, unsigned digit)
{
    unsigned digitCount = countDigits(num);
    if (pos>digitCount+1)
    {
        return num;
    }

    int newNum = 0;
    for (unsigned i = digitCount+1; i >= 1; i--)
    {
        if (pos==i)
        {
            newNum = newNum * 10 + digit;
        }
        else 
        {
            newNum = newNum * 10 + num % 10;
            num /= 10;
        }

    }
    num=reverse(newNum);
    return num;
}

void swapDigitsByPosition(unsigned& num1, unsigned& num2, unsigned pos)
{
    unsigned digitNum1 = getDigitByPosition(num1, pos);
    unsigned digitNum2 = getDigitByPosition(num2, pos);
    if (digitNum1==-1||digitNum2==-1)
    {
        return;
    }
    num1 = removeDigitByPosition(num1, pos);
    num2 = removeDigitByPosition(num2, pos);

    num1 = includeDigitInPosition(num1, pos, digitNum2);
    num2 = includeDigitInPosition(num2, pos, digitNum1);
}

//task 05
void splitNum(int num, int& oddPos, int& evenPos)
{
    oddPos = 0;
    evenPos = 0;
    unsigned digitsCount = countDigits(num);
    for (unsigned i = digitsCount; i >= 1; i--)
    {
        if (i%2!=0)
        {
            oddPos = oddPos*10 + num % 10;
        }
        else
        {
            evenPos = evenPos*10 + num % 10;
        }

        num /= 10;
    }
    oddPos = reverse(oddPos);
    evenPos = reverse(evenPos);
}

//task 06
bool isPrimeNumber(int num)
{
    if (num==0 || num==1)
    {
        return false;
    }

    for (size_t i = 2; i <=sqrt(num) ; i++)
    {
        if (num%i==0)
        {
            return false;
        }
    }
    return true;
}

unsigned countPrimeDevisors(int num)
{
    int count = 0;
    for (size_t i = 1; i <= num; i++)
    {
        if (num%i==0&&isPrimeNumber(i))
        {
            count++;
        }
    }
    return count;
}

void findMaxAndMin(int& a, int& b, unsigned k)
{
    int max = 0;
    for (int i = a; i <=b ; i++)
    {
        int primeDevCount = countPrimeDevisors(i);
        if (primeDevCount==k)
        {
            a == i;
            break;
        }
    }

    for (int i = b; i >= a; i--)
    {
        int primeDevCount = countPrimeDevisors(i);
        if (primeDevCount==k)
        {
            b == i;
            break;
        }
    }

}

//task 07
int power(int n, int k)
{
    int res = 1;
    for (size_t i = 0; i < k; i++)
    {
        res *= n;
    }
    return res;
}
void addLastTwoDigitsOfAtoB(int& a, int& b, int k)
{
    int currNum = 0;
    for (size_t i = 0; i < k; i++)
    {
        currNum = currNum * 10 + a % 10;
        a /= 10;
    }
    currNum = reverse(currNum);
    int digitCountB = countDigits(b);
    b = currNum * power(10, digitCountB) + b;
}

//pract 08
int& removeDigitsAtBackByPossition(int& num, unsigned pos)
{
    unsigned digitsCount = countDigits(num);
    unsigned digitsToRemove = digitsCount - pos;
    for (size_t i = 0; i < digitsToRemove; i++)
    {
        num /= 10;
    }
    return num;
}

int& removeDigitsAtFrontByPossition(int& num, unsigned pos)
{
    num = reverse(num);
    unsigned digitsToRemove = pos - 1;

    for (size_t i = 0; i < digitsToRemove; i++)
    {
        num /= 10;
    }
    num = reverse(num);
    return num;
}

int& removeDigitsByPosition(int& num, unsigned front, unsigned back)
{
    if (front > back || front < 1 || back > countDigits(num))
    {
        std::cout << "Invalid positions" << std::endl;
        return;
    }
    num = removeDigitsAtBackByPossition(num, back);
    num = removeDigitsAtFrontByPossition(num, front);
    return num;
}

int main()
{
    /*int n1 = 12;
    int n2 = 45;
    swap(n1, n2);
    std::cout << n1 << ' ' << n2 << std::endl;*/

    /*unsigned n = 12345;
    removeDigitByPosition(n, 3);
    std::cout << n;*/
    /*int num = 16;
    int denum = 20;
    simplifyFraction(num, denum);
    std::cout << num << ' ' << denum<<std::endl;

    int num2 = 15;
    int denum2 = 25;
    sumFractions(num, denum, num2, denum2);*/

    /*std::cout << includeDigitInPosition(1345, 5, 6);*/

    /*unsigned num1 = 1234;
    unsigned num2 = 567;
    swapDigitsByPosition(num1, num2, 2);
    std::cout << num1 << ' ' << num2 << std::endl;*/
    /*int odd;
    int even;
    splitNum(1234567, odd, even);
    std::cout << odd << ' ' << even;*/

    //int a = 1921;
    //int b = 321;
    ///*findMaxAndMin(a, b, 3);*/
    //addLastTwoDigitsOfAtoB(a, b, 2);
    //std::cout << a << ' ' << b;

    int num = 1234567;
    removeDigitsByPosition(num, 2, 5);
    std::cout << num;
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
