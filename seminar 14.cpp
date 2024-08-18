// seminar 14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task 01
unsigned fact(unsigned n)
{
	if (n==0)
	{
		return 1;
	}
	return n * fact(n - 1);
}

//task 02
int fibb(int n)
{
	if (n==0||n==1)
	{
		return 1;
	}
	return fibb(n - 1) + fibb(n - 2);
}

//task 03
int power(int n, int k)
{
	if (k==0)
	{
		return 1;
	}
	return n * power(n, k - 1);
}

int fastPower(int n, int k)
{
	if (k==0)
	{
		return 1;
	}
	else if (k%2==1)
	{
		return n * fastPower(n, k - 1);
	}
	else
	{
		return fastPower(n * n, k / 2);
	}
}

//04
int sumArr(const int* arr, size_t size)
{
	if (size==0)
	{
		return 0;
	}
	return arr[0] + sumArr(arr + 1, size - 1);
}

//task 05
bool linearSearch(const int* arr, size_t size, int searched)
{
	if (size==0)
	{
		return false;
	}
	return arr[0] == searched || linearSearch(arr + 1, size - 1, searched);
}

//task 06
bool binarySearch(const int* arr, size_t size, int searched)
{
	if (size==0)
	{
		return false;
	}
	int mid = size / 2;
	if (arr[mid]==searched)
	{
		return true;
	}
	else if (arr[mid]>searched)
	{
		return binarySearch(arr, mid, searched);
	}
	else
	{
		return binarySearch(arr + mid + 1, size - mid - 1, searched);
	}
}

//task 07
unsigned myStrLen(const char* str)
{
	if (!str)
	{
		return 0;
	}
	unsigned count=0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
bool isPalindrome(const char* str, size_t len)
{
	if (len<=1)
	{
		return true;
	}
	return str[0] == str[len - 1] && isPalindrome(str + 1, len - 2);
}

bool isPalindrome(const char* str)
{
	return isPalindrome(str, myStrLen(str));
}

//serch in text
bool isPrefix(const char* text, const char* pattern)
{
	if (*pattern=='\0')
	{
		return true;
	}
	return *text == *pattern && isPrefix(text + 1, pattern + 1);
}

bool findInText(const char* text, size_t textLen, const char* pattern, size_t patternLen)
{
	if (patternLen>textLen)
	{
		return false;
	}
	return isPrefix(text, pattern) || findInText(text + 1, textLen - 1, pattern, patternLen);
}

bool findInText(const char* text, const char* pattern)
{
	return findInText(text, myStrLen(text), pattern, myStrLen(pattern));
}

//task 08
bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

void returnLowerAndUpperCount(const char* str, int& lower, int& upper)
{
	if (*str == '\0')
	{
		return;
	}
	if (isUpper(str[0]))
	{
		upper++;
	}
	else if (isLower(str[0]))
	{
		lower++;
	}
	returnLowerAndUpperCount(str + 1, lower, upper);
}

//
int myMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int getMaxInArr(const int* arr, size_t size)
{
	if (size==0)
	{
		return INT_MIN;
	}
	return myMax(arr[0], getMaxInArr(arr + 1, size - 1));
}

int getMaxInArr2(const int* arr, size_t size)
{
	if (size==0)
	{
		return INT_MAX;
	}
	if (size==1)
	{
		return arr[0];
	}
	int mid = size / 2;
	return myMax(getMaxInArr2(arr, mid), getMaxInArr2(arr + mid, size - mid));
}
int main()
{
	//01
	/*std::cout << fact(4);*/

	//02
	/*std::cout << fibb(5);*/

	//03
	/*std::cout << power(2, 5);*/
	//std::cout << power(2, 4);

	//04
	/*int arr[5] = { 1,2,3,4,5 };
	std::cout << sumArr(arr, 5);*/

	//05
	/*int arr[5] = { 1,2,6,3,1 };
	std::cout << linearSearch(arr, 5, 6);*/

	//06
	/*int arr[6] = { 1,5,7,12,16,20 };
	std::cout << binarySearch(arr, 6, 16);*/

	//07
	/*std::cout << isPalindrome("abcba");*/

	//
	/*std::cout<<findInText("abcba", "cb");*/

	//08
	/*int lower=0, upper=0;
	returnLowerAndUpperCount("afPsdTfsdSDFFDS",lower , upper);

	std::cout << lower << " " << upper << std::endl;*/

	//
	int arr[5] = { 1, 2, 6, 10, 1 };

	std::cout << getMaxInArr2(arr, 5);

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
