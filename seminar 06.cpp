// seminar 06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void print(const int arr[], size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		std::cout << arr[i]<<' ';
	}
}

int linearSearch(const int arr[], size_t len, int el)
{
	for (size_t i = 0; i < len; i++)
	{
		if (arr[i] == el) 
		{
			return i;
		}
	}
	return -1;
}

int binarySearch(const int arr[], size_t len, int el)
{
	int left = 0;
	int right = len - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (el>arr[mid])
		{
			left = mid + 1;
		}
		else if (el<arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

//sieveOfEratosten
void assignValueToAllCells(bool arr[], int len, bool value)
{
	for (size_t i = 0; i < len; i++)
	{
		arr[i] = value;
	}
}

void markAsNotPrime(bool sieve[], int len, int current)
{
	int toMark = current + current;

	while (toMark<len)
	{
		sieve[toMark] = true;
		toMark += current;
	}
}

void sieveErathostenes(bool sieve[], int len)
{
	for (int i = 2; i <= len; i++)
	{
		if (!sieve[i])
		{
			std::cout << i << ' ';
			markAsNotPrime(sieve, len, i);
		}
	}
}

//reverse array
void swap(int& n1, int& n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

void reverseArray(int arr[], int len)
{
	for (int i = 0; i < len/2; i++)
	{
		swap(arr[i], arr[len - i - 1]);
	}
}

//task 01
bool isPalindrome(const int arr[], int len)
{
	for (size_t i = 0; i < len/2; i++)
	{
		if (arr[i]!=arr[len-1-i])
		{
			return false;
		}
	}
	return true;
}

//task 02
int findMaxInArr(const int arr[], int len)
{
	int max = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}

int findLCMOfArr(const int arr[], int len)
{
	int max = findMaxInArr(arr, len);
	int lcmCandidate = max;
	for (size_t i = 0; i < len; i++)
	{
		if (lcmCandidate%arr[i]!=0)
		{
			lcmCandidate += max;
		}
	}
	return lcmCandidate;
}

//task 03
int findGCD(int n1, int n2)
{
	if (n1<n2)
	{
		swap(n1, n2);
	}
	while (n2 != 0)
	{
		int res = n1 % n2;
		n1 = n2;
		n2 = res;
	}
	return n1;
}

int findGCDofArr(const int arr[], int len)
{
	int res = arr[0];
	for (size_t i = 1; i < len; i++)
	{
		res = findGCD(res, arr[i]);
		if (res==1)
		{
			break;
		}
	}
	return res;
}

//task 04
bool isConcatOfTwoPalindromes(const int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		if (isPalindrome(arr,i)&&isPalindrome(arr+i, len - i))
		{
			return true;
		}
	}
	return false;
}

//task 05
unsigned countInversions(const int arr[], int len)
{
	unsigned count = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (arr[i]>arr[j])
			{
				count++;
			}
		}
	}
	return count;
}

//task 06
int findSmallestMissingElement(const int arr[], int len)
{
	int left = 0;
	int right = len - 1;
	int startEl = arr[0];

	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid]!=startEl+mid)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return startEl + left;
}

int findLargestMissingElement(const int arr[], int len)
{
	int left = 0;
	int right = len - 1;
	int startEl = arr[len-1];
	while (left<=right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid]!=startEl-mid-1)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	/*if (left<len&&arr[right]+1!=arr[right+1])
	{
		return arr[right] + 1;
	}*/
	return startEl - left + 1;
}
int main()
{
	/*int arr[5] = { 1,5,6,7,8 };
	print(arr, 5);
	std::cout << std::endl;
	bool containsSix=linearSearch(arr, 5, 6)>=0;
	std::cout << containsSix << std::endl;
	std::cout << binarySearch(arr, 5, 7) << std::endl;*/

	/*constexpr int MAX_SIZE = 1024;
	int n;
	std::cin >> n;
	bool sieve[MAX_SIZE];
	assignValueToAllCells(sieve, n, false);
	sieveErathostenes(sieve, n);*/

	/*constexpr int size = 5;
	int arr[size] = { 0,1,2,3,4 };
	reverseArray(arr, size);
	print(arr, size);*/

	//task 01
	/*constexpr int size = 8;
	int arr[size] = { 1,2,3,4,4,3,2,1 };
	std::cout << isPalindrome(arr, size);*/

	//task 02
	/*constexpr int size = 4;
	int arr[size] = { 9,18,6,12 };
	std::cout << findMaxInArr(arr, size)<<std::endl;
	std::cout << findLCMOfArr(arr, size) << std::endl;
	std::cout << findGCDofArr(arr, size) << std::endl;
	//03
	std::cout << findGCD(3, 12);*/

	//04
	/*constexpr int size = 9;
	int arr[size] = { 1,2,3,2,1,4,5,5,4 };
	std::cout << isConcatOfTwoPalindromes(arr, size);*/

	//05
	constexpr int size = 8;
	int arr[size] = { 2, 3, 5, 6, 9, 10, 12, 15 };
	/*std::cout << countInversions(arr, size);*/

	//06
	std::cout << findSmallestMissingElement(arr, size)<<std::endl;
	std::cout << findLargestMissingElement(arr, size) << std::endl;
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
