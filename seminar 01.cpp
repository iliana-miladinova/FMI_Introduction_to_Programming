// seminar 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //task 01
    /*int num;
    std::cin >> num;
    bool isEven = num % 2 == 0;
    std::cout << isEven;*/

    //02
    /*int num;
    std::cin >> num;
    int sto = num % 10;
    int des = (num / 10) % 10;
    int ed = (num / 100) % 10;
    int newNum = sto * 100 + des * 10 + ed + 1;
    std::cout << newNum;*/

    //03
  /*  char ch;
    std::cin >> ch;
    bool isVowel = ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i'
        || ch == 'A' || ch == 'E' || ch == 'O' || ch == 'U' || ch == 'I';
    std::cout << isVowel;*/

    //04
   /* int num;
    std::cin >> num;
    bool isValidGrade = num >= 2 && num <= 6;
    std::cout << isValidGrade;*/

    //05
    /*int num;
    std::cin >> num;
    std::cout << (num / 10);*/

    //06
   /* int a;
    int b;
    std::cin >> a >> b;
    int expr1 = a + b;
    int expr2 = a - b;
    std::cout << expr1 * expr1 * expr1 * expr1 - expr2 * expr2;*/

    //07
    /*int money;
    std::cin >> money;
    int hun = money / 100;
    std::cout << hun<<"x100lv ";
    money %= 100;
    int fifty = money / 50;
    std::cout << fifty << "x50lv ";
    money %= 50;

    int twenty = money / 20;
    std::cout << twenty << "x20lv ";
    money %= 20;

    int ten = money / 10;
    std::cout << ten << "x10lv ";
    money %= 10;

    int five = money / 10;
    std::cout << five << "x5lv ";
    money%= 5;

    int two = money / 2;
    std::cout << two << "x2lv ";
    money %= 2;

    std::cout << money << "x1lv " << std::endl;*/

    //08
    int num1;
    int num2;
    std::cin >> num1 >> num2;

    bool isBigger = num1 > num2;

    std::cout <<( num1 * isBigger + num2 * !isBigger);
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
