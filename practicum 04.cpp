// practicum 04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task 01
int abs(int num)
{
	if (num<0)
	{
		return -num;
	}
	return num;
}

double fabs(double num)
{
	if (num<0)
	{
		return -num;
	}
	return num;
}

//task 02
char toLower(char ch)
{
	return ch + ('a' - 'A');
}

char toUpper(char ch)
{
	return ch - ('a' - 'A');
}

//task 03
int convertCharToInt(char ch)
{
	return ch - '0';
}

char converIntToChar(int num)
{
	return num + '0';
}

//task 04
unsigned countDigits(unsigned num)
{
	unsigned count = 0;
	if (num==0)
	{
		count = 1;
	}
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return count;
}

//task 05
unsigned getKDigitOfN(unsigned n, unsigned k)
{
	unsigned digitsCount = countDigits(n);
	unsigned position = digitsCount - k;
	for (size_t i = 0; i < position; i++)
	{
		n /= 10;
	}
	return n % 10;
}

//task 06
unsigned getRest(unsigned a, unsigned b)
{
	if (a<b)
	{
		return 0;
	}
	int afterDevision = a / b;
	int opashka = afterDevision * b;
	return a - opashka;
}

int getResultAfterDevision(unsigned a, unsigned b)
{
	if (b==0)
	{
		return - 1;
	}

	int num = b;
	int result = 0;
	while (num<=a)
	{
		num += b;
		result++;
	}
	return result;
}

//task 08
unsigned squareRoot(unsigned num)
{
	unsigned root = 0;
	while (root * root <= num)
	{
		root++;
	}
	return root - 1;
}

//task 09
bool isExactRoot(unsigned num)
{
	unsigned root = squareRoot(num);
	if (root*root==num)
	{
		return true;
	}
	return false;
}

//task 10
int getLCM(unsigned n, unsigned k)
{
	unsigned max = n > k ? n : k;
	unsigned lcmCandidate = max;
	while (lcmCandidate % n != 0 || lcmCandidate % k != 0)
	{
		lcmCandidate += max;
	}
	return lcmCandidate;
}
//task 11
double getDistance(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool isPointInCircle(int x, int y, double r)
{
	double side = getDistance(x, y, 0, 0);
	if (side>r)
	{
		return false;
	}
	return true;
}
bool isTriangleInCircle(int x1, int y1, int x2, int y2, int x3, int y3, double r)
{
	return isPointInCircle(x1,y1,r)&&isPointInCircle(x2,y2,r)&&isPointInCircle(x3,y3,r);
}

//task 11-already done

//task 12
unsigned getSumOfDigits(unsigned num)
{
	int result = 0;
	while (num != 0)
	{
		int lastDigit = num % 10;
		result += lastDigit;
		num /= 10;
	}
	return result;
}

unsigned sumDigitsUntilOneDigitResult(unsigned num)
{
	while (num>9)
	{
		num = getSumOfDigits(num);
	}
	return num;
}
int main()
{
	/*std::cout << toLower('Q')*/;
	/*std::cout << converIntToChar(7);*/
	///*std::cout << getKDigitOfN(1234567,3);*/
	/*std::cout << getRest(4, 2);*/
	/*std::cout << getResultAfterDevision(30, 7);*/
	/*std::cout << squareRoot(25);*/
	/*std::cout << isExactRoot(25);*/
	/*std::cout << getLCM(9, 6);*/
	/*std::cout << isTriangleInCircle(1, -2, 3, 1, -1, 3, 3);*/
	/*std::cout << getSumOfDigits(555);*/
	std::cout << sumDigitsUntilOneDigitResult(27395132);
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
