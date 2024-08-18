// pract 14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task 01
int getSumToN(int n)
{
	if (n==1)
	{
		return 1;
	}
	return n + getSumToN(n - 1);
}

//task 02
bool isDigitInNum(int num, int dig)
{
	if (num==0)
	{
		return false;
	}
	return num % 10 == dig || isDigitInNum(num / 10, dig);
}

//task 03
int getSumOfDigits(int num)
{
	if (num<=9)
	{
		return num;
	}
	return num % 10 + getSumOfDigits(num / 10);
}

//task 04
bool isMonotonicallyIncreasing(const int* arr, size_t size)
{
	if (size<=1)
	{
		return true;
	}
	return arr[1]>=arr[0] && isMonotonicallyIncreasing(arr + 1, size - 1);
}

//task 05
bool isPrimeHelper(int num, int devisor)
{
	if (devisor==1)
	{
		return true;
	}

	if (num%devisor==0)
	{
		return false;
	}

	return isPrimeHelper(num, devisor - 1);
}

bool isPrime(int num)
{
	if (num<=1)
	{
		return false;
	}
	return isPrimeHelper(num, sqrt(num));
}

//task 06
void moveElements(int* arr, size_t size, int ind)
{
	for (int i = size; i > ind; i--)
	{
		arr[i] = arr[i - 1];
	}
}
void insertInArrByIndex(int* arr, size_t size, int num, int index)
{
	if (index>=size || arr[index]>=num)
	{
		moveElements(arr, size, index);
		arr[index] = num;
		size++;
		return;
	}

	insertInArrByIndex(arr, size, num, index + 1);
}

void insertInArray(int* arr, size_t size, int num)
{
	return insertInArrByIndex(arr, size, num, 0);
}

void printArr(int* arr, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

//task 07
int removeLastDigit(int num)
{
	return num / 10;

}

int reverse(int num)
{
	if (num<=9)
	{
		return num;
	}
	int res = 0;
	while (num!=0)
	{
		res = res * 10 + num % 10;
		num /= 10;
	}
	return res;
}
int removeFirstDigit(int num)
{
	int rev = reverse(num);
	int withoutFirst=removeLastDigit(rev);
	return reverse(withoutFirst);
}

bool isPalindrome(int num)
{
	int rev = reverse(num);
	return num == rev;
}
bool canBePalindrome(int num)
{
	if (num<=9)
	{
		return false; //we cannot remove a digit
	}

	if (isPalindrome(num))
	{
		return true;
	}

	int withoutLastDig = removeLastDigit(num);
	int withoutFirstDig = removeFirstDigit(num);

	return canBePalindrome(withoutLastDig) || canBePalindrome(withoutFirstDig);
}

//task 08
int getBinomicalCoef(int n, int k)
{
	if (n==0||k==0||n==k)
	{
		return 1;
	}
	if (k>n)
	{
		return 0;
	}
	return getBinomicalCoef(n - 1, k - 1) + getBinomicalCoef(n - 1, k);
}

//task 09
int findRightIndex(const int* arr, size_t size, int index)
{
	if (index<=0||index>=size-1)
	{
		return -1;
	}

	double average = (arr[index - 1] + arr[index + 1]) / 2;
	if (arr[index]>average)
	{
		return index;
	}
	return findRightIndex(arr, size, index - 1);
}

int findRightIndex(const int* arr, size_t size)
{
	return findRightIndex(arr, size, size - 2);
}

//task 10
bool isPrime1(int num)
{
	if (num<=1)
	{
		return false;
	}

	double temp = sqrt(num);

	for (int i = 2; i < temp; i++)
	{
		if (num%i!=0)
		{
			return false;
		}
	}

	return true;
}

bool isPerfectSquare(int num)
{
	int root = sqrt(num);
	return root * root == num;
}

void findPalindromes(int* arr, size_t size, int index)
{
	if (index<size)
	{
		if (isPalindrome(arr[index]))
		{
			std::cout << arr[index] << ' ';
		}
		findPalindromes(arr, size, index + 1);
	}
}

void findPrimes(int* arr, size_t size, int index)
{
	if (index<size)
	{
		if (isPrime(arr[index]))
		{
			std::cout << arr[index] << ' ';
		}
		findPrimes(arr, size, index + 1);
	}
}

void findPerfectSquares(const int* arr, size_t size, int index)
{
	if (index < size)
	{
		if (isPerfectSquare(arr[index]))
		{
			std::cout << arr[index] << ' ';
		}
		findPerfectSquares(arr, size, index + 1);
	}
}

void printInInterval(int num1, int num2)
{
	int len = (num2 - num1)+1;
	int* arr = new int[len];

	for (int i = 0; i < len; i++)
	{
		arr[i] = num1 + i;
	}

	findPalindromes(arr, len, 0);
	std::cout << std::endl;

	findPrimes(arr, len, 0);
	std::cout << std::endl;

	findPerfectSquares(arr, len, 0);
	std::cout << std::endl;

	delete[] arr;
}
int main()
{
    //task 01
	/*std::cout << getSumToN(5);*/

	//task 02
	/*std::cout << isDigitInNum(1258636, 9);*/

	//task 03
	/*std::cout << getSumOfDigits(12345);*/

	//task 04
	/*int arr[5] = { 3,4,11,9,10 };
	std::cout << isMonotonicallyIncreasing(arr, 5);*/

	//task 05
	/*std::cout << isPrime(64);*/

	//task 06
	/*int arr[6] = { 1,2,5,6,9,23 };
	insertInArray(arr, 6, 7);
	printArr(arr, 7);*/

	//task 07
	/*std::cout << canBePalindrome(123435);*/

	//task 08
	/*std::cout << getBinomicalCoef(10, 3);*/

	//task 09
	/*int arr[9] = { 1,7,6,3,9,10,8,26,4 };
	std::cout << findRightIndex(arr, 9);*/

	//task 10
	printInInterval(100, 110);
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
