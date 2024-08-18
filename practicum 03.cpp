// practicum 03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int power(int num, int power)
{
    int result = 1;
    for (size_t i = 0; i < power; i++)
    {
        result *= num;
    }
    return result;
}
int main()
{
    //task 01
    /*int start, end;
    std::cin >> start >> end;
    if (start<0||start>255||end<0||end>255)
    {
        std::cout << "Invalid codes!" << std::endl;
    }
    else
    {
        char ch;
        for (size_t i = start; i <= end; i++)
        {
            ch = i;
            std::cout << i << "-->"<<ch<<std::endl;
        }
       std::cout << std::endl;
    }*/

    //task 02
    /*int num;
    std::cin >> num;
    
    int fact=1;
    for (size_t i = 1; i <=num; i++)
    {
        fact *= i;
    }
    std::cout << "Factorial: "<<fact << std::endl;*/

    //task 03
    /*int num;
    std::cin >> num;

    int sum = 0;
    for (size_t i = 0; i <= num; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            sum += j;
        }
    }
    std::cout << sum << std::endl;*/

    //task 04
    /*unsigned num;
    std::cin >> num;

    int sum = 0;
    int curr = 0;
    for (size_t i = 0; i < num; i++)
    {
        curr = curr * 10 + 9;
        sum += curr;
    }
    std::cout << sum;*/

    //task 05
    /*unsigned num;
    std::cin >> num;

    int first = 0;
    int second = 1;
    int fibb;
    std::cout << first << ' ';
    std::cout << second << ' ';
    unsigned temp = num - 2;
    for (size_t i = 0; i < temp; i++)
    {
        int tempFirst = first;
        first = second;
        second = tempFirst + second;
        std::cout << second << ' ';
    }*/

    //2 nachin
    /*unsigned num;
    std::cin >> num;

    int first = 0;
    int second = 1;
    int fibb = 0;
    for (size_t i = 0; i < num; i++)
    {
        std::cout << first << ' ';

        fibb = first + second;
        first=second;
        second = fibb;
    }*/

    //task 06
    /*unsigned n;
    std::cin >> n;

    int num;
    int sum = 0;
    do
    {
        std::cin >> num;
        if (num<n && num%2==0)
        {
            sum += num;
        }
    } while (num!=-1);
    std::cout << sum;*/

    //task 07
    /*unsigned n, k;
    std::cin >> n >> k;
    int sum = 0;
    for (size_t i = n; i <= k ; i++)
    {
        
        for (size_t j = 1; j <= i; j++)
        {
            if (i%j==0)
            {
                sum += j;
            }
        }
        if (sum==i)
        {
            std::cout << i << ' ';
        }
        sum = 0;
    }*/

    /*int n, m;
    std::cin >> n >> m;
    int max = n > m ? n : m;
    int min = n < m ? n : m;
    int res = 0;

    for (int i = min; i <= max; i++) 
    {
        for (int j = 1; j < i; j++) 
        {
            if (i % j == 0) 
            {
                res += j;
            }
        }

        if (i == res)
        {
            std::cout << i << std::endl;
        }
        res = 0;
    }*/

    /*int n, k;
    std::cin >> n >> k;
    int min = n < k ? n : k;
    int max = n > k ? n : k;

    int sum = 0;
    for (size_t i = min; i <= max ; i++)
    {
        for (size_t j = 1; j < i; j++)
        {
            if (i%j==0)
            {
                sum += j;
            }
        }

        if (i==sum)
        {
            std::cout << i << ' ';
        }
        sum = 0;
    }*/

    //task 08
    /*int num;
    std::cin >> num;

    for (size_t i = 0; i < num/2; i++)
    {
        bool isPrime = true;
        if (i==0 || i==1)
        {
            isPrime = false;
        }

        int tempSqrt = sqrt(i);
        for (size_t j = 2; j < tempSqrt; j++)
        {
            if (i%j==0)
            {
                isPrime = false;
            }
        }

        if (isPrime)
        {
            if (num-i==0||num-i==1)
            {
                isPrime = false;
            }

            int tempS = sqrt(num - i);
            for (size_t k = 2; k < tempS; k++)
            {
                if ((num-i)%k==0)
                {
                    isPrime = false;
                }
            }

 
        }
        if (isPrime)
        {
            std::cout << num << '=' << i << '+' << num - i << std::endl;
            std::cout << num << '=' << num - i << '+' << i << std::endl;
            break;
        }
    }*/

    //task 09
    unsigned n;
    std::cin >> n;

    unsigned num;
    int max = 0;
    int secondMax = 0;
    do
    {
        std::cin >> num;
        n--;

        if (num>=max)
        {
            max = num;
        }

        if (num>=secondMax && max>=num)
        {
            secondMax = num;
        }
    } while (n>0);

    std::cout << max << ' ' << secondMax << std::endl;
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
