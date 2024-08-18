// izpit zad.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
unsigned getPowerOfTwo(unsigned n)
{
    return 1 << n;
}

size_t getLenOfTheWholeSet(const int* arr,size_t size)
{
	size_t totalSets = getPowerOfTwo(size) - 1;
	size_t resSize = 0;
	for (size_t i = 1; i <=totalSets ; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i&(1<<j))
			{
				resSize++;
			}
		}
		resSize++;
	}
	resSize += 1;
	return resSize;
}

int* generateSubsets(const int* arr, size_t size)
{
	size_t totalSets = getPowerOfTwo(size) - 1;
	size_t resSize = getLenOfTheWholeSet(arr, size);
	int* resSet = new int[resSize];
	size_t ind = 0;
	for (int i = 1; i <= totalSets ; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i&(1<<j))
			{
				resSet[ind] = arr[j];
				ind++;
			}
		}
		resSet[ind] = 0;
		ind++;
	}
	resSet[ind] = 0;
	ind++;
	return resSet;
}

void printSet(const int* arr, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

void printSets(const int* sets)
{
	std::cout << "{ ";
	while (*sets != 0 || *(sets + 1) != 0)
	{
		if (*sets == 0)
		{
			std::cout << "}, { ";
		}
		else 
		{
			std::cout << *sets << " ";
		}
		sets++;
	}
	std::cout << "}" << std::endl;
}

//task 01
//unsigned countChars(const char* str, char ch)
//{
//	if (!str)
//	{
//		return 0;
//	}
//
//	unsigned count = 0;
//	while (*str)
//	{
//		if (*str==ch&&*(str+1)==ch)
//		{
//			count++;
//		}
//		str++;
//	}
//	return count + 1;
//}

long findSeq(const char* str, char S)
{
	if (!str)
	{
		return -1;
	}
	int currLen = 0;
	int globalLen = 0;

	while (*str)
	{
		if (*str == S)
		{
			currLen++;
			if (currLen > globalLen)
			{
				globalLen = currLen;

			}
		}
		else
		{
			currLen = 0;
		}
		str++;
	}
	return globalLen;
}



// ������� �� ���������� �� ������ �������� ������������
int** generateSubsets(const int* arr, size_t size, size_t& totalSubsets)
{
	totalSubsets = getPowerOfTwo(size) - 1; // ���� �� ������ �������� ������������
	int** resSet = new int* [totalSubsets];

	size_t ind = 0;
	for (size_t i = 1; i <= totalSubsets; i++)
	{
		size_t subsetSize = 0;
		// �������� ������� �� �������� ������������
		for (size_t j = 0; j < size; j++)
		{
			if (i & (1 << j)) {
				subsetSize++;
			}
		}
		// �������� ����� �� �������� ������������
		resSet[ind] = new int[subsetSize + 1]; // +1 �� ������� ����������
		size_t subsetInd = 0;

		// �������� ���������� � �������� ������������
		for (size_t j = 0; j < size; j++) 
		{
			if (i & (1 << j)) 
			{
				resSet[ind][subsetInd++] = arr[j];
			}
		}
		resSet[ind][subsetInd] = 0; // �������� ����� ���������� , ����� ������������� ���� ��� ��������(����������� ����� �� ���������)
		ind++;
	}

	return resSet;
}

// ������� �� ���������� �� ������������
void printSubsets(int** subsets, size_t totalSubsets)
{
	for (size_t i = 0; i < totalSubsets; i++)
	{
		std::cout << "[";
		for (size_t j = 0; subsets[i][j] != 0; j++) 
		{
			std::cout << subsets[i][j];
			if (subsets[i][j + 1] != 0) 
			{
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
	}
}

// ������� �� ������������� �� �������
void deleteSubsets(int** subsets, size_t totalSubsets) 
{
	for (size_t i = 0; i < totalSubsets; i++) 
	{
		delete[] subsets[i];
	}
	delete[] subsets;
}


//2 �����
int** generateSubsets1(const int* arr, size_t size, size_t& totalSubsets, int*& subsetSizes) 
{
	totalSubsets = getPowerOfTwo(size) - 1; // ���� �� ������ �������� ������������
	int** resSet = new int* [totalSubsets];
	subsetSizes = new int[totalSubsets]; //����� ������� �� ����� ��������

	size_t ind = 0;
	for (size_t i = 1; i <= totalSubsets; i++)
	{
		size_t subsetSize = 0;
		// �������� ������� �� �������� ������������
		for (size_t j = 0; j < size; j++)
		{
			if (i & (1 << j)) 
			{
				subsetSize++;
			}
		}

		// �������� ����� �� �������� ������������
		resSet[ind] = new int[subsetSize];
		subsetSizes[ind] = subsetSize;
		size_t subsetInd = 0;

		// �������� ���������� � �������� ������������
		for (size_t j = 0; j < size; j++) 
		{
			if (i & (1 << j)) 
			{
				resSet[ind][subsetInd++] = arr[j];
			}
		}
		ind++;
	}

	return resSet;
}

// ������� �� ���������� �� ������������
void printSubsets(int** subsets, size_t totalSubsets, int* subsetSizes)
{
	for (size_t i = 0; i < totalSubsets; i++) 
	{
		std::cout << "[";
		for (size_t j = 0; j < subsetSizes[i]; j++) 
		{
			std::cout << subsets[i][j];
			if (j != subsetSizes[i] - 1) 
			{
				std::cout << ", ";
			}
		}
		std::cout << "]\n";
	}
}

// ������� �� ������������� �� �������
void deleteSubsets(int** subsets, size_t totalSubsets, int* subsetSizes) 
{
	for (size_t i = 0; i < totalSubsets; i++) 
	{
		delete[] subsets[i];
	}
	delete[] subsets;
	delete[] subsetSizes;
}
int main()
{
	/*constexpr size_t size = 4;
	int arr[size] = { 1,2,3,4 };
	int* set = generateSubsets(arr, size);
	size_t size2 = getLenOfTheWholeSet(arr, size);
	printSet(set, size2);
	printSets(set);
	delete[] set;*/

	//01
	/*char str[] = "BaaaCCtkpaaaaaraa";
	std::cout << findSeq(str, 'a');*/

	//
	/*int arr[3] = { 1, 2, 3 };
	size_t totalSubsets;
	int** subsets = generateSubsets(arr, 3, totalSubsets);
	printSubsets(subsets, totalSubsets);
	deleteSubsets(subsets, totalSubsets);*/

	//
	int arr[3] = { 1,2,3 };
	size_t totalSubsets;
	int* subsetSizes;
	int** subsets = generateSubsets1(arr, 3, totalSubsets, subsetSizes);
	printSubsets(subsets, totalSubsets, subsetSizes);
	deleteSubsets(subsets, totalSubsets, subsetSizes);
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
