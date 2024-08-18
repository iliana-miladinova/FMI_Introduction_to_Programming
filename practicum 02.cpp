// practicum 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //task 01
    /*int num;
    std::cin >> num;
	switch (num)
	{
	case 0: 
		std::cout << "0" << std::endl;
		break;
	case 1:
		std::cout << "I" << std::endl;
		break;
	case 2:
		std::cout << "II" << std::endl;
		break;
	case 3:
		std::cout << "III" << std::endl;
		break;
	case 4:
		std::cout << "IV" << std::endl;
		break;
	case 5:
		std::cout << "V" << std::endl;
		break;
	case 6:
		std::cout << "VI" << std::endl;
		break;
	case 7:
		std::cout << "VII" << std::endl;
		break;
	case 8:
		std::cout << "VIII" << std::endl;
		break;
	case 9:
		std::cout << "IX" << std::endl;
		break;

	default: std::cout << "Invalid num" << std::endl;
		break;
	}*/

	//task 02
	/*char ch;
	std::cin >> ch;
	if (ch=='I'||ch=='X'||ch=='V'||ch=='M'||ch=='L'||ch=='D'||ch=='C')
	{
		int code = ch;
		std::cout << code << std::endl;
	}
	else
	{
		std::cout << -1 << std::endl;
	}*/

	//task 03
	/*int year;
	std::cin >> year;*/
	/*if (year%4==0)
	{
		if (year%100==0)
		{
			if (year%400==0)
			{
				std::cout << "Leap year" << std::endl;
			}
			else
			{
				std::cout << "Not a leap year" << std::endl;
			}
		}
		else
		{
			std::cout << "Leap year" << std::endl;
		}
	}
	else
	{
		std::cout << "Not a leap year" << std::endl;
	}*/

	//vtori nachin
	/*if ((year%4==0&&year%100!=0)||year%400==0)
	{
		std::cout << "Leap year" << std::endl;
	}
	else
	{
		std::cout << "Not a leap year" << std::endl;
	}*/

	//task 04
	/*char ch;
	std::cin >> ch;

	if (ch >= 'a' && ch <= 'z')
	{
		char upper = ch - ('a' - 'A');
		std::cout <<upper<<std::endl;
		if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u' || ch=='y')
		{
			std::cout << "Vowel" << std::endl;
		}
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		char lower = ch + ('a' - 'A');
		std::cout << lower << std::endl;;
		if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch=='Y')
		{
			std::cout << "Vowel" << std::endl;
		}
	}
	else
	{
		std::cout << "Invalid symbol" << std::endl;
	}*/

	//task 05;
	/*int num1, num2, num3;
	std::cin >> num1 >> num2 >> num3;
	if (num1>num2)
	{
		if (num2>num3)
		{
			std::cout << num3 << ' ' << num2 << ' ' << num1;
		}
		else if(num1>num3)
		{
			std::cout << num2 << ' ' << num3 << ' ' << num1;
		}
		else
		{
			std::cout << num2 << ' ' << num1 << ' ' << num3;
		}
	}
	else
	{
		if (num1>num3)
		{
			std::cout << num3 << ' ' << num1 << ' ' << num2;
		}
		else if(num2>num3)
		{
			std::cout << num1 << ' ' << num3 << ' ' << num2;
		}
		else
		{
			std::cout << num1 << ' ' << num2 << ' '<<num3;
		}
	}*/

	//task 06
	/*int num;
	std::cin >> num;
	if (num==0)
	{
		std::cout << "Zero" << std::endl;
	}
	if (num%2==0)
	{
		std::cout << "Even" << std::endl;
	}
	else
	{
		std::cout << "Odd" << std::endl;
	}*/

	//task 07
	/*int num1, num2, num3;
	std::cin >> num1 >> num2 >> num3;
	if (num1>num2)
	{
		if (num3>num1)
		{
			std::cout << num3 * 100 + num1 * 10 + num2;
		}
		else if (num3>num2)
		{
			std::cout << num1 * 100 + num3 * 10 + num2;
		}
		else
		{
			std::cout << num1 * 100 + num2 * 10 + num3;
		}
	}
	else if (num1>num3)
	{
		if (num2>num1)
		{
			std::cout << num2 * 100 + num1 * 10 + num3;
		}
		else if (num2>num3)
		{
			std::cout << num1 * 100 + num2 * 10 + num3;
		}
		else
		{
			std::cout << num1 * 100 + num3 * 10 * num2;
		}
	}
	else
	{
		if (num2<num3)
		{
			std::cout << num3 * 100 + num2 * 10 + num1;
		}
		else
		{
			std::cout << num2 * 100 + num3 * 10 + num1;
		}
	}*/

	//task 08-already done

	//task 09;
	//int day, month, year;
	//std::cin >> day >> month >> year;

	//bool isValidMonth = month >= 1 && month <= 12;
	//bool isLeapYear=false;
	//if (year%4==0)
	//{
	//	/*isLeapYear = true;*/
	//	if (year%100==0)
	//	{
	//		if (year%400==0)
	//		{
	//			isLeapYear == true;
	//		}
	//		/*else
	//		{
	//			isLeapYear == false;
	//		}*/

	//	}
	//	else
	//	{
	//		isLeapYear == true;
	//	}
	//}
	///*else
	//{
	//	isLeapYear == false;
	//}*/

	//bool validDaysForMonth=false;
	//switch (month)
	//{
	//case 1:
	//case 3:
	//case 5:
	//case 7:
	//case 8:
	//case 10:
	//case 12:
	//	validDaysForMonth = day >= 1 && day <= 31;
	//	break;
	//case 4:
	//case 6:
	//case 9:
	//case 11:
	//	validDaysForMonth = day >= 1 && day <= 30;
	//	break;
	//case 2:
	//	if (isLeapYear)
	//	{
	//		validDaysForMonth = day >= 1 && day <= 29;
	//	}
	//	else
	//	{
	//		validDaysForMonth = day >= 1 && day <= 28;
	//	}
	//	break;
	//}

	///*if (isValidMonth&&validDaysForMonth)
	//{
	//	std::cout << 1 << std::endl;
	//}
	//else
	//{
	//	std::cout << 0 << std::endl;
	//}*/

	//std::cout << isValidMonth && validDaysForMonth;

	//task 10;
	//double num1, num2;
	//char ch;
	//std::cin >> num1 >> ch >> num2;
	///*double res;*/
	//switch (ch)
	//{
	//case '+':
	//	/*res = */std::cout << num1 + num2 << std::endl;
	//	break;
	//case '-':
	//	std::cout<<num1 - num2<<std::endl;
	//	break;

	//case '*':
	//	std::cout<< num1 * num2<<std::endl;
	//	break;

	//case '/':
	//	if (num2==0)
	//	{
	//		std::cout << "You cannot devide by zero!" << std::endl;
	//	}
	//	else
	//	{
	//		std::cout << num1 / num2 << std::endl;;
	//	}
	//	break;
	//default: std::cout << "Invalid Operation!" << std::endl;
	//	break;
	//}

	///*std::cout << res << std::endl;*/

//	double a;
//	char symbol;
//	double b;
//
//	std::cin >> a >> symbol >> b;
//
//	double result = 0;
//
//	if (symbol == '+')
//	{
//		result = a + b;
//	}
//	else if (symbol == '-')
//	{
//		result = a - b;
//	}
//	else if (symbol == '*')
//	{
//		result = a * b;
//	}
//	else if (symbol == '/')
//	{
//		if (b != 0)
//		{
//			result = a / b;
//		}
//		else
//		{
//			std::cout << "cannot devide by zero";
//		}
//	}
//
//	std::cout << result;

	//task 11;
	int num;
	std::cin >> num;

	/*std::cout << num / 1000 << std::endl;
	std::cout << num / 100 << std::endl;
	std::cout << (num / 100) % 10 << std::endl;
	std::cout << num / 10 << std::endl;
	std::cout << (num / 10) % 10 << std::endl;
	std::cout << num % 10 << std::endl;*/

	int firstDig = num / 1000;
	int secondDig = (num / 100) % 10;
	int thirdDig = (num / 10) % 10;
	int fourthDig = num % 10;

	int num1 = firstDig * 10 + fourthDig;
	int num2 = secondDig * 10 + thirdDig;

	if (num1>num2)
	{
		std::cout << num1 << '>' << num2 << std::endl;
	}
	else if (num1<num2)
	{
		std::cout << num1 << '<' << num2 << std::endl;
	}
	else
	{
		std::cout << num1 << '=' << num2 << std::endl;
	}

	//task 12 - already done
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
