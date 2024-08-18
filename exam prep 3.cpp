// exam prep 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//exam 2019
//task 11

int countFixed(int* arr, int length)
{
	if (!arr)
	{
		return -1;
	}

	int fixedCount = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i]==i)
		{
			fixedCount++;
		}
	}
	return fixedCount;
}
bool AnalyzeArray(int* arr, int length)
{
	if (!arr || length<2)
	{
		return 0;
	}

	int fixedCount = countFixed(arr, length);
	if (fixedCount>=2)
	{
		return true;
	}
	return false;

}

//2020
//task 02
int myStrlen(const char* str)
{
	if (!str)
	{
		return -1;
	}
	int len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}

void myStrcpy(const char* source, char* dest)
{
	if (!source||!dest)
	{
		return;
	}

	while (*source)
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}
char* reverseStr(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	int len = myStrlen(str);
	char* reverse = new char[len + 1];
	int reverseInd = 0;
	for (int i = len-1; i >= 0; i--)
	{
		reverse[reverseInd] = str[i];
		reverseInd++;
	}

	reverse[reverseInd] = '\0';

	return reverse;
}

char* revAndReplace(const char* str)
{
	if (!str) {
		return nullptr;
	}

	char* reverse = reverseStr(str);
	if (!reverse)
	{
		return nullptr;
	}

	int len = myStrlen(reverse);
	char* res = new char[len + 1];

	for (int i = 0; i < len; i++)
	{
		if (reverse[i]=='e')
		{
			res[i] = '!';
		}
		else if (reverse[i]=='y')
		{
			res[i] = '*';
		}
		else
		{
			res[i] = reverse[i];
		}
	}
	res[len] = '\0';
	delete[] reverse;
	return res;
	
}

//2 nachin
char* revandreplace(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	int len = myStrlen(str);

	char* res = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		char ch = str[len - 1 - i];
		if (ch=='e')
		{
			res[i] = '!';
		}
		else if (ch=='y')
		{
			res[i] = '*';
		}
		else
		{
			res[i] = ch;
		}
	}
	res[len] = '\0';
	return res;
}

//task 03
bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}
int getDigitFormChar(char ch)
{
	return ch - '0';
}
bool checkDate(const char* str)
{
	if (!str)
	{
		return false;
	}

	int strLen = myStrlen(str);
	if (strLen!=7)
	{
		return false;
	}

	if (str[4]!=' '||str[5]!='g'||str[6]!='.')
	{
		return false;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!isDigit(str[i]))
		{
			return false;
		}
	}
	int year = getDigitFormChar(str[0]) * 1000 + getDigitFormChar(str[1]) * 100 + getDigitFormChar(str[2]) * 10 + getDigitFormChar(str[3]);

	/*if (year%4==0)
	{
		if (year%100==0)
		{
			if (year%400==0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	return false;*/

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	return false;
}

//task 04
int countLower(const int* arr1, const int* arr2, int N)
{
	if (!arr1||!arr2)
	{
		return -1;
	}
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int sum = arr1[i] + arr2[i];
		if (sum>=97&&sum<=122)
		{
			count++;
		}
	}
	return count;
}

int countUpper(const int* arr1, const int* arr2, int N)
{
	if (!arr1||!arr2)
	{
		return -1;
	}
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int sum = arr1[i] + arr2[i];
		if (sum>=65&&sum<=90)
		{
			count++;
		}
	}
	return count;
}

int* countletters(const int* arr1, const int* arr2, int N)
{
	if (!arr1||!arr2)
	{
		return nullptr;
	}

	int* res = new int[2];

	int smallCount = countLower(arr1, arr2, N);
	int upperCount = countUpper(arr1, arr2, N);
	res[0] = upperCount;
	res[1] = smallCount;
	return res;
}

//2 nachin
int* countletters1(const int* arr1, const int* arr2, int N)
{
	if (!arr1 || !arr2)
	{
		return nullptr;
	}

	int* res = new int[2] {0, 0};
	for (int i = 0; i < N; i++)
	{
		int sum = arr1[i] + arr2[i];
		if (sum>=65&&sum<=90)
		{
			res[0]++;
		}
		else if (sum>=97&&sum<=122)
		{
			res[1]++;
		}
	}
	return res;
}

void printRes(int* res)
{
	std::cout << "{ ";
	for (int i = 0; i < 2; i++)
	{
		if (i != 1)
		{
			std::cout << res[i] << ", ";
		}
		else
		{
			std::cout << res[i];
		}
	}
	std::cout << " }" << std::endl;
}

//task 05
bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool isLetter(char ch)
{
	return isLower(ch) || isUpper(ch);
}
bool checkstr(const char* str)
{
	if (!str)
	{
		return false;
	}

	for (int i = 0; str[i]!='\0'; i++)
	{
		if (!isLetter(str[i]))
		{
			return false;
		}
		
	}

	

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isLetter(str[i]))
		{
			return false;
		}
		if (str[i + 1] != '\0')
		{
			if ((isLower(str[i]) && !isUpper(str[i + 1])) || (isUpper(str[i]) && !isLower(str[i + 1])))
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	//2019 task 11
	/*int arr[5] = { 0, 2, 2, 3, 5 };
	std::cout << AnalyzeArray(arr, 5);*/

	//2020
	//task 02
	/*char str[] = "I left you alone";
	char* res = revandreplace(str);
	std::cout << res;
	delete[] res;*/

	//task 03
	/*const char str[] = "2004 g.";
	std::cout << checkDate(str);*/

	//task 04
	//int arr1[5] = { 3,5,11,2,9 };
	//int arr2[5] = { 1,4,32,71,5 };
	//int* res = countletters1(arr1, arr2, 5);
	//printRes(res);
	//delete[] res;

	//task 05
	std::cout << checkstr("aZaAaCfEa");
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
