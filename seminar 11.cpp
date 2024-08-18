// seminar 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

unsigned getDigitsCount(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned count = 0;
	while (*str)
	{
		if (isDigit(*str))
		{
			count++;
		}
		str++;
	}
	return count;
}

unsigned getNumsCount(const char* str)
{
	if (!str)
	{
		return 0;
	}
	unsigned count = 0;
	while (*str)
	{
		if (isDigit(*str)&&!isDigit(*(str+1)))
		{
			count++;
		}
		str++;
	}
	return count;
}

unsigned myStrlen(const char* str)
{
	if (!str)
	{
		return 0;
	}
	unsigned len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}

unsigned countMinuses(const char* str)
{
	if (!str)
	{
		return 0;
	}
	unsigned count = 0;
	while (*str)
	{
		if (*str=='-')
		{
			count++;
		}
		str++;
	}
	return count;
}
char* censireNum(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	size_t resultLen = myStrlen(str) - getDigitsCount(str) + getNumsCount(str) - countMinuses(str);;

	char* res = new char[resultLen + 1];

	int resInd = 0;
	while (*str)
	{
		if (!isDigit(*str)&&*str!='-')
		{
			res[resInd] = *str;
			resInd++;
		}
		else if (!isDigit(*(str+1)))
		{
			res[resInd] = '*';
			resInd++;
		}
		str++;
	}
	res[resultLen] = '\0';
	return res;
}

//
bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

void countLowerAndUpper(const char* str, unsigned& lowerCount, unsigned& upperCount)
{
	lowerCount = upperCount = 0;
	if (!str)
	{
		return;
	}

	while (*str)
	{
		if (isLower(*str))
		{
			lowerCount++;
		}
		else if (isUpper(*str))
		{
			upperCount++;
		}
		str++;
	}
}

void getLowerAndUpperStrings(const char* str, char*& lower, char*& upper)
{
	if (!str)
	{
		return;
	}
	unsigned lowerCount = 0;
	unsigned upperCount = 0;
	countLowerAndUpper(str, lowerCount, upperCount);
	lower = new char[lowerCount + 1];
	upper = new char[upperCount + 1];
	lower[lowerCount] = upper[upperCount] = '\0';

	int lowerInd = 0;
	int upperInd = 0;
	while (*str)
	{
		if (isUpper(*str))
		{
			upper[upperInd] = *str;
			upperInd++;
		}

		else if (isLower(*str))
		{
			lower[lowerInd] = *str;
			lowerInd++;
		}

		str++;
	}
}

//
void merge(const int* arr1, size_t size1, const int* arr2, size_t size2, int* res)
{
	unsigned indArr1 = 0;
	unsigned indArr2 = 0;
	unsigned indRes = 0;

	while (indArr1<size1&&indArr2<size2)
	{
		if (arr1[indArr1]<=arr2[indArr2])
		{
			res[indRes] = arr1[indArr1];
			indRes++;
			indArr1++;
		}
		else
		{
			res[indRes] = arr2[indArr2];
			indRes++;
			indArr2++;
		}
	}

	while (indArr1<size1)
	{
		res[indRes] = arr1[indArr1];
		indRes++;
		indArr1++;
	}

	while (indArr2 < size2)
	{
		res[indRes] = arr2[indArr2];
		indRes++;
		indArr2++;
	}
}

int getBound(const int* arr, size_t size)
{
	if (!arr)
	{
		return -1;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i]>arr[i+1])
		{
			return i + 1;
		}
	}

	return -1;
}

void sortArrConcatOfTwoSortedArrays(int* arr, size_t size)
{
	if (!arr)
	{
		return;
	}

	int arr2StartInd = getBound(arr, size);
	if (arr2StartInd==-1)
	{
		return;
	}

	int* temp = new int[size];
	merge(arr, arr2StartInd, arr + arr2StartInd, size - arr2StartInd, temp);
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = temp[i];
	}

	delete[] temp;
}

//
unsigned getLowerCount(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned count = 0;
	while (*str)
	{
		if (isLower(*str))
		{
			count++;
		}
		str++;
	}
	return count;
}


void concatLettersAtBack(char* str, unsigned firstIndex, char ch, unsigned count)
{
	for (int i = 0; i < count; i++)
	{
		str[firstIndex + i] = ch;
	}
}


char* sortLower(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	unsigned len = getLowerCount(str);
	char* lower = new char[len + 1];

	constexpr unsigned alphabet_size = 26;
	constexpr char first_letter = 'a';

	lower[len] = '\0';

	unsigned indLower = 0;
	int countLower[alphabet_size]{ 0 };
	while (*str)
	{
		if (isLower(*str))
		{
			countLower[*str - first_letter]++;
		}
		str++;
	}
	for (size_t i = 0; i < alphabet_size ; i++)
	{
		concatLettersAtBack(lower, indLower, first_letter + i, countLower[i]);
		indLower += countLower[i];
	}
	return lower;
}

//task 02
unsigned countSmaller(const int* str, int el)
{
	if (!str)
	{
		return 0;
	}
	unsigned count = 0;
	while (*str)
	{
		if (*str<el)
		{
			count++;
		}
		str++;
	}
	return count;
}

void sortSecondTask(int* str, size_t size, int el)
{
	if (!str)
	{
		return;
	}

	int* smaller = new int[size];
	int* bigger = new int[size];

	int smallerInd = 0;
	int biggerInd = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (str[i] < el)
		{
			smaller[smallerInd] = str[i];
			smallerInd++;
		}
		else if(str[i]>el) 
		{
			bigger[biggerInd] = str[i];
			biggerInd++;
		}
	}

	int ind = 0;

	for (size_t i = 0; i < smallerInd; i++)
	{
		str[ind] = smaller[i];
		ind++;
	}
	str[ind] = el;
	ind++;
	for (size_t i = 0; i < biggerInd; i++)
	{
		str[ind] = bigger[i];
		ind++;
	}

	delete[] smaller;
	delete[] bigger;
}

//task 03
unsigned getPowerOfTwo(unsigned n)
{
	return 1 << n;
}
int** generateSubsets(const int* arr, size_t size, size_t& totalSubsets, int*& subsetsSizes)
{
	if (!arr)
	{
		return nullptr;
	}

	totalSubsets = getPowerOfTwo(size) - 1;
	int** resSet = new int* [totalSubsets];
	subsetsSizes = new int[totalSubsets];

	size_t ind = 0;
	for (int i = 1; i <= totalSubsets ; i++)
	{
		size_t subsetSize = 0;
		for (int j = 0; j < size; j++)
		{
			if (i&(1<<j))
			{
				subsetSize++;
			}
		}

		resSet[ind] = new int[subsetSize];
		subsetsSizes[ind] = subsetSize;
		size_t subInd = 0;

		for (int j = 0; j < size; j++)
		{
			if (i & (1 << j))
			{
				resSet[ind][subInd] = arr[j];
				subInd++;
			}
		}
		ind++;
	}

	return resSet;
}

void printSets(int** subsets, size_t totalSubsets, int* subsetsSizes)
{
	for (int i = 0; i < totalSubsets; i++)
	{
		std::cout << "{ ";
		for (int j = 0; j < subsetsSizes[i]; j++)
		{
			std::cout << subsets[i][j];
			if (j!=subsetsSizes[i]-1)
			{
				std::cout << ", ";
			}
		}
		std::cout << " }";
		if (i!=totalSubsets-1)
		{
			std::cout << ", ";
		}
	}
}

void freeSubsets(int** subsets, size_t totalSubsets, int* subsetsSizes)
{
	for (int i = 0; i < totalSubsets; i++)
	{
		delete[] subsets[i];
	}
	delete[] subsets;
	delete[] subsetsSizes;
}
int main()
{
	/*char* str = censireNum("abc-1234dgg-4fsdg5");
	std::cout << str << std::endl;

	delete[] str;*/

	//char* lower = nullptr;
	//char* upper = nullptr;
	//getLowerAndUpperStrings("AAqew12423BBq", lower, upper);

	//std::cout << lower << ' ' << upper << std::endl;
	//delete[] lower;
	//delete[] upper;

	/*constexpr size_t size = 6;
	int arr[size] = { -8,5,9,-12,4,7 };
	sortArrConcatOfTwoSortedArrays(arr, size);
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;*/

	/*char* str=sortLower("zAzAbbzazQc");
	std::cout << str << std::endl;
	delete[] str;*/

	//task 02
	/*constexpr int size = 9;
	int arr[size] = { 1, 5, 6, 3, 0, -1, 2, 9, 7 };

	sortSecondTask(arr, size, 3);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}*/

	//03
	constexpr int size = 3;
	int arr[size] = { 1,2,3 };
	size_t totalSets;
	int* subsetsSizes;
	int** subsets = generateSubsets(arr, size, totalSets, subsetsSizes);
	printSets(subsets, totalSets, subsetsSizes);
	freeSubsets(subsets, totalSets, subsetsSizes);
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
