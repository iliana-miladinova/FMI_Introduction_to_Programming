// seminar 03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int power(int n, int k)
{
    int res = 1;
    for (size_t i = 0; i <k ; i++)
    {
        res *= n;
    }
    return res;
}

bool isPrime(int a)
{
    bool isPrime = true;
    for (size_t i = 2; i < sqrt(a); i++)
    {
        if (a % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int main()
{
    //in class
    //task 01 - NOK
    /*unsigned int n, k;
    std::cin >> n >> k;
    unsigned int max = n > k ? n : k;
    unsigned lcmCandidate = max;
    while (lcmCandidate% n != 0 || lcmCandidate % k != 0)
    {
        lcmCandidate += max;
    }
    std::cout << lcmCandidate;*/

    //task 02 - NOD Evklid
   /* unsigned int n, k;
    std::cin >> n >> k;
    if (k>n)
    {
        unsigned int temp = n;
        n = k;
        k = temp;
    }
    while (k != 0)
    {
        unsigned int res = n % k;
        n = k;
        k = res;
    }
    std::cout << n << std::endl;*/

    //task 03
   /* unsigned int num;
    std::cin >> num;
    bool isPrime = true;
    for (size_t i = 2; i < sqrt(num); i++)
    {
        if (num%i==0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        std::cout << "Prime" << std::endl;
    }
    else
    {
        std::cout << "Not Prime" << std::endl;
    }*/

    //task 04;
   /* unsigned int num;
    std::cin >> num;

    for (size_t i = num; i >1; i--)
    {
        unsigned temp = sqrt(i);
        bool isPrime = true;
        for (size_t j = 2; j <= temp; j++)
        {
            if (i%j==0)
            {
                isPrime = false;
                break;
            }
        }
        if (!isPrime)
        {
            continue;
        }
        unsigned count = 0;
        while (num%i==0)
        {
            count++;
            num /= i;
        }
        
        if (count>0)
        {
            std::cout << i;
            if (count>=2)
            {
                std::cout << '^' << count<<' ';
            }
        }
    }
    std::cout<<std::endl;*/

    //task 05
    /*unsigned num;
    std::cin >> num;

    for (size_t i = 2; i <=num ; i++)
    {
       int count = 0;
       while (num % i == 0)
       {
           count++;
           num /= i;
       }
       if (count>0)
       {
           std::cout << i<<' ';
           if (count>=2)
           {
               std::cout << "^ " << count << ' ';
           }
       }
    }
    std::cout<<std::endl;*/

    //task 06
    /*unsigned num;
    std::cin >> num;
    
    unsigned mostCommonDig = -1;
    unsigned mostCommonDigitOccurances = 0;
    for (unsigned currDig= 0; currDig <= 9; currDig++)
    {
        unsigned copyOfNum = num;
        unsigned currDigOccurances = 0;
        while (copyOfNum!=0)
        {
            int lastDig = copyOfNum % 10;
            if (lastDig==currDig)
            {
                currDigOccurances++;
            }
            copyOfNum /= 10;
        }

        if (currDigOccurances>mostCommonDigitOccurances)
        {
            mostCommonDig = currDig;
            mostCommonDigitOccurances = currDigOccurances;
        }
    }

    std::cout << mostCommonDig << std::endl;*/

    //homework
    //task 01
    /*int num;
    int sum = 0;
    do
    {
        std::cin >> num;
        sum += num;
    } while (num!=0);
    std::cout << sum;*/

    //task 02
    /*int num1, num2;
    std::cin >> num1 >> num2;
    if (num1>num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    for (size_t i = num1; i >= 1; i--)
    {
        if (num1%i==0 && num2%i==0)
        {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;*/

    //task 03
    //unsigned num;
    //std::cin >> num;
    //unsigned count = 0;
    //int copyOfNum = num;
    //while (copyOfNum!=0)
    //{
    //    count++;
    //    copyOfNum /= 10;
    //}
    //unsigned mid = count / 2;
    ///*unsigned devisor = pow(10, count / 2);*/
    //int left, rigth, newNum;
    //unsigned devisor = power(10, mid);
    //unsigned devisor2 = power(10, mid - 1);
    //if (count%2!=0)
    //{
    //    /*left = num / (devisor * 10);
    //    rigth = num % (devisor );
    //    newNum = left * (devisor) + rigth;*/
    //    rigth = num / power(10, mid + 1);
    //    left = num % devisor;
    //    newNum = rigth * devisor + left;
    //}
    //else
    //{
    //    /*left = num / (devisor * 10);
    //    rigth = num % devisor;
    //    newNum = left * devisor + rigth;*/
    //    left = num / power(10, mid + 1);
    //    rigth = num % devisor2;
    //    newNum = left * devisor2 + rigth;

    //  
    //}
    //std::cout << newNum<<std::endl;
    
    //task 04
    //unsigned a, b;
    //std::cin >> a >> b;

    //for (size_t i = a; i <=b ; i++)
    //{
    //    /*bool isPrime = true;
    //    for (size_t j = 2; j < sqrt(i); j++)
    //    {
    //        if (i%j==0)
    //        {
    //            isPrime = false;
    //            break;
    //        }
    //    }*/
    //    if (isPrime(i))
    //    {
    //        std::cout << i << ' ';
    //    }
    //}
    
    //task 05
    /*unsigned num;
    std::cin >> num;

    if (num <= 0) 
    {
        std::cout << "false" << std::endl;
    }
    bool isPowOfTwo = true;
    while (num > 1)    
    {
        if (num % 2 != 0) 
        {
            isPowOfTwo = false;
            break;
        }
        num /= 2;
    }

    if (isPowOfTwo) 
    {
        std::cout << "true" << std::endl;
    }
    else 
    {
        std::cout << "false" << std::endl;
    }*/

    //task 06
    int a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;

    for (int i = -100; i <=100; i++)
    {
        int res = a * power(i, 4) + b * power(i, 3) + c * power(i, 2) + d * i + e;
        if (res>=0)
        {
            std::cout << i << ' ';
        }
    }
    std::cout<<std::endl;

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
