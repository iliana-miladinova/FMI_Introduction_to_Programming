// pract 07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task 01
int getIndexOfSymbol(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		return 10 + (ch - 'A');
	}
	else
	{
		return -1;
	}
}

char getSymbolFromIndex(int ind)
{
	if (ind >= 0 && ind <= 9)
	{
		return ind + '0';
	}
	if (ind >= 10)
	{
		return (ind - 10) + 'A';
	}
	return 0;
}

void print(const char arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void addOneToNum(char num[], int len, int k)
{
	for (int i = len-1; i >= 0; i--)
	{
		int index = getIndexOfSymbol(num[i]);
		if (index==k-1)
		{
			num[i] = '0';
		}
		else
		{
			index++;
			num[i] = getSymbolFromIndex(index);
			break;
		}
	}
}

//task 02
void takeOneFromNum(char num[], int len, int k)
{
	for (int i = len-1; i >= 0; i--)
	{
		int index = getIndexOfSymbol(num[i]);
		if (index==0)
		{
			num[i] = getSymbolFromIndex(k - 1);
		}
		else
		{
			index--;
			num[i] = getSymbolFromIndex(index);
			break;
		}
	}
}

//task 04
void addTwoNum(const char num1[], const char num2[], int len, int k, char res[])
{
	int remainder = 0;
	for (int i = len-1; i >=0; i--)
	{
		int sum = getIndexOfSymbol(num1[i]) + getIndexOfSymbol(num2[i]) + remainder;
		remainder = sum / k;
		res[i] = getSymbolFromIndex(sum%k);
	}
	if (remainder>0)
	{
		for (int i = len; i > 0; i--)
		{
			res[i] = res[i - 1];
		}
		res[0] = remainder;
	}
}

//task 04
unsigned getSize(int num, int k)
{
	unsigned size = 0;
	while (num != 0)
	{
		size++;
		num /= k;
	}
	return size;
}

void fromDecimalToRandom(unsigned num, char arr[], int len, int k)
{
	for (int arrayIter = len-1; arrayIter >= 0; arrayIter--)
	{
		int index = num % k;
		arr[arrayIter] = getSymbolFromIndex(index);
		num /= k;
	}
}

bool isPalindromInK(unsigned int n, int k)
{
	if (k>16)
	{
		return false;
	}
	if (n<10)
	{
		return true;
	}
	unsigned size = getSize(n, k);
	constexpr unsigned maxSize = 1000;
	char arr[maxSize];
	fromDecimalToRandom(n, arr, size, k);
	for (int i = 0; i < size/2; i++)
	{
		if (arr[i]!=arr[size-i-1])
		{
			return false;
		}
	}
	return true;
}

//task 05
unsigned fromRandomToDecimal(const char from[], int len, int k)
{
	unsigned res = 0;
	for (int arrayIter = len-1, mult=1; arrayIter >=0; arrayIter--, mult*=k)
	{
		int index = getIndexOfSymbol(from[arrayIter]);
		res += index * mult;
	}
	return res;
}

bool areEqual(const char num1[], int len, int k, const char num2[], int len2, int n)
{
	unsigned decimal1 = fromRandomToDecimal(num1, len, k);
	unsigned decimal2 = fromRandomToDecimal(num2, len2, n);
	return decimal1 == decimal2;
}
int main()
{
	//task 01
	/*char arr[3] = { '0','1','1' };
	addOneToNum(arr, 3, 2);
	print(arr, 3);*/

	//task 02
	/*char arr[3] = { '1','0','0' };
	takeOneFromNum(arr, 3, 2);
	print(arr, 3);*/

	//task 03
	/*char arr[3] = { '1','7','5' };
	char arr2[3] = { '5','3','7' };
	char res[3];
	addTwoNum(arr, arr2, 3, 8, res);
	print(res, 3);*/

	//task 04
	/*std::cout << isPalindromInK(7, 2);*/

	//tasko 05
	char arr1[3] = { '3','4','5' };
	char arr2[2] = { 'E','5' };
	std::cout << areEqual(arr1, 3, 8, arr2, 2, 16);
	
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
