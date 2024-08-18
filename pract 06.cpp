// pract 06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task 01
double getAverage(const int arr[], int len)
{
    double sum = 0;
	for (size_t i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	double average=sum / len;
	return average;
}

int getClosestToAverage(const int arr[], int len)
{
	double average = getAverage(arr, len);
	int closest = 0;
	double closestDiff = fabs(average - arr[0]);
	for (size_t i = 0; i < len; i++)
	{
		if (fabs(average-arr[i])<closestDiff)
		{
			closest = arr[i];
			closestDiff = fabs(average - arr[i]);
		}
	}
	return closest;
}

//task 02
bool isSorted(const int arr[], int len)
{
	if (len==1)
	{
		return true;
	}
	bool isAscending = true;
	if (arr[0]>arr[1])
	{
		isAscending = false;
	}
	for (int i = 1; i < len-1; i++)
	{
		if (isAscending)
		{
			if (arr[i]>arr[i+1])
			{
				return false;
			}
		}
		else
		{
			if (arr[i]<arr[i+1])
			{
				return false;
			}
		}
	}
	return true;
}

//task 03
void swap(int& n1, int& n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

void swapFirstNElementsInArr(int arr[], int size, int n)
{
	if (n>size)
	{
		return;
	}
	for (int i = 0; i < n/2; i++)
	{
		swap(arr[i], arr[n - i - 1]);
	}
}

void print(const int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout<<std::endl;
}

//task 04
unsigned getLargestReapetingNumsLine(const int arr[], int len)
{
	unsigned max = 1;
	unsigned currLen = 1;
	int curr = arr[0];
	for (int i = 1; i < len; i++)
	{
		if (curr==arr[i])
		{
			currLen++;
		}
		else
		{
			if (currLen > max)
			{
				max = currLen;
			}
			curr = arr[i];
			currLen = 1;
		}
	}
	if (currLen>max)
	{
		max = currLen;
	}
	return max;
}

//task 05
int abs(int num)
{
	if (num<0)
	{
		return -num;
	}
	return num;
}
void makeArrFromDiffs(const int arr[], int len, int result[])
{
	for (int i = 0; i < len-1; i++)
	{
		result[i] = abs(arr[i] - arr[i + 1]);
	}
}

void inputArr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cin >> arr[i];
	}
}

//task 06
bool isSubarrayFromInd(const int arr1[], int len1, const int arr2[], int len2, int ind)
{
	for (int i = 0; i < len2; i++)
	{
		if (arr1[i+ind]!=arr2[i])
		{
			return false;
		}
	}
	return true;
}

bool isSubarray(const int arr1[], int len1, const int arr2[], int len2)
{
	for (int i = 0; i < len1; i++)
	{
		if (arr1[i]==arr2[0])
		{
			if (isSubarrayFromInd(arr1,len1,arr2,len2,i))
			{
				return true;
			}
		}
	}
	return false;
}

//07
void shiftArrayFromInd(int arr[], int& len, int ind)
{
	for (int i = ind; i < len-1; i++)
	{
		arr[i] = arr[i + 1];
	}
	len--;
}
void removeNegativeElements(int arr[], int& len)
{
	for (size_t i = 0; i < len; i++)
	{
		if (arr[i]<0)
		{
			shiftArrayFromInd(arr, len, i);
			i--;
		}
	}
}

//task 08
//bool isDigitInArray(const int arr[], int len, int dig)
//{
//	int countRepetitions = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i]==dig)
//		{
//			/*countRepetitions++;*/
//			return true;
//		}
//	}
//	/*if (countRepetitions>0)
//	{
//		return true;
//	}*/
//	return false;
//}

unsigned countRepetitions(const int arr[], int len, int dig)
{
	int countRepetitions = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i]==dig)
		{
			countRepetitions++;
		}
	}
	return countRepetitions;
}

bool isPermutation(const int arr1[], const int arr2[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int countRepOfDigInArr1 = countRepetitions(arr1, len, i);
		int countRepOfDigInArr2 = countRepetitions(arr2, len, i);
		if (countRepOfDigInArr1!=countRepOfDigInArr2)
		{
			return false;
		}
	}
	return true;
}
int main()
{
    //01
	/*constexpr int size = 4;
	int arr[size] = { 5,7,4,9 };
	std::cout << getAverage(arr, size) << std::endl;
	std::cout << getClosestToAverage(arr, size) << std::endl;*/

	//02
	/*constexpr int size = 4;
	int arr[size] = { 1,3,8,15 };
	std::cout << isSorted(arr, size) << std::endl;*/

	//03
	/*constexpr int size = 7;
	int arr[size] = { 1,-4,4,-5,-9,2,10 };
	swapFirstNElementsInArr(arr, size, 4);
	
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;*/

	//04
	/*constexpr int size = 11;
	int arr[size] = { 3,3,2,4,2,5,2,2,3,3,3 };
	std::cout << getLargestReapetingNumsLine(arr, size) << std::endl;*/

	//05
	/*constexpr int size = 7;
	int arr[size];
	inputArr(arr, size);
	int resultArr[size - 1];
	makeArrFromDiffs(arr, size, resultArr);
	print(resultArr, size - 1);*/

	//06
	/*constexpr int len1 = 6;
	int arr1[len1];
	inputArr(arr1, len1);

	constexpr int len2 = 3;
	int arr2[len2];
	inputArr(arr2, len2);
	std::cout << isSubarray(arr1, len1, arr2, len2);*/

	//07
	/*constexpr int len = 7;
	int arr[len];
	inputArr(arr, len);
	removeNegativeElemenst(arr, len);
	print(arr, len);*/

	/*int arr[] = { 1, -4, 4, -5, -9, 2, 10 };
	int len = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Original array: ";
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	removeNegativeElements(arr, len);

	std::cout << "Array after removing negative elements: ";
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;*/

	//08
	constexpr int len = 6;
	int arr[len];
	inputArr(arr, len);
	int arr2[len];
	inputArr(arr2, len);
	std::cout << isPermutation(arr, arr2, len) << std::endl;

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
