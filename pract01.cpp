
// pract01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //task 01
   /* int num1;
    int num2;
    std::cin >> num1 >> num2;
    std::cout << num1 / num2<<std::endl;
    std::cout << num1 % num2<<std::endl;*/

    //task 02
    /*double num1;
    std::cin >> num1;
    double numInInches = num1 * 0.393701;
    std::cout << "Inches: " << numInInches;*/

    //task 03
    /*double length;
    double width;
    std::cout << "Length: ";
    std::cin >> length;
    std::cout << "Width: ";
    std::cin >> width;
    int perimeter = 2 * length + 2 * width;
    int area = length * width;
    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Area: " << area << std::endl;*/

    //04
    /*int seconds;
    std::cin >> seconds;
    int minutes = seconds / 60;
    int remSeconds = seconds % minutes;
    int hours = minutes / 60;
    int remMinutes = minutes % hours;
    int days = hours / 24;
    int remHours = hours % days;
    std::cout << days <<' ' << remHours <<' ' << remMinutes <<' ' << remSeconds << std::endl;*/

    //05
    /*double num1, num2, num3, num4;
    std::cout << "First interval: ";
    std::cin >> num1 >> num2;
    std::cout << "Second interval: ";
    std::cin >> num3 >> num4;
    bool isIntervalBetween = num1 <= num4 && num3 <= num2;
    std::cout << isIntervalBetween;*/

    //06
    /*int num1, num2, num3, num4;
    std::cin >> num1 >> num2 >> num3 >> num4;
    bool isNum1Even = num1 % 2 == 0;
    bool isNum2Even = num2 % 2 == 0;
    bool isNum3Even = num3 % 2 == 0;
    bool isNum4Even = num4 % 2 == 0;
    std::cout << num1 * isNum1Even + num2 * isNum2Even + num3 * isNum3Even + num4 * isNum4Even;*/

    //07
    /*int num1, num2, num3, num4;
    std::cin >> num1 >> num2 >> num3 >> num4;
    int addNum = num2 - num1;
    bool isNum2PlusAddNumEqualToNum3 = (num2 + addNum == num3);
    bool isNum3PlusAddNumEqualToNum4 = (num3 + addNum == num4);
    std::cout << isNum2PlusAddNumEqualToNum3 && isNum3PlusAddNumEqualToNum4;*/

    //08
    //int num1, num2, num3, num4;
    //std::cin >> num1 >> num2 >> num3 >> num4;
    //double devisor1 = num2 / num1;
    //double devisor2 = num3 / num2;
    //double devisor3 = num4 / num3;
    //bool isProgression = num1 != 0 && num2 != 0 && num3 != 0 && devisor1 == devisor2&&devisor2==devisor3;
    //std::cout << isProgression;

    //09
   /* double num1, num2;
    std::cin >> num1 >> num2;

    num1 += num2;
    num2=num1-num2;
    num1 = num1 - num2;
    std::cout << num1 << ' ' << num2;*/

    //10
    /*int num1;
    int num2;
    std::cin >> num1 >> num2;

    bool isBigger = num1 > num2;

    std::cout << (num1 * isBigger + num2 * !isBigger);*/

    //11
    int num;
    std::cin >> num;
    
    int lastDigit = num % 10;

    bool isTwoDigitNum = num % 100 == num;
    std::cout << num * isTwoDigitNum + lastDigit * !isTwoDigitNum;
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
