// seminar 15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task 1
unsigned fibb_rec(unsigned n, unsigned* cache)
{
	if (n<=1)
	{
		return 1;
	}

	if (cache[n]!=0)
	{
		return cache[n];
	}
	else
	{
		int curr = fibb_rec(n - 1, cache) + fibb_rec(n - 2, cache);
		cache[n] = curr;
		return curr;
	}
}

unsigned fibb(unsigned n)
{
	unsigned* cache = new unsigned[n + 1] {0};
	unsigned res = fibb_rec(n, cache);
	delete[] cache;
	return res;
}

//task 02
//min operations memoization
unsigned min(unsigned n1, unsigned n2)
{
	return n1 < n2 ? n1 : n2;
}

unsigned min(unsigned n1, unsigned n2, unsigned n3)
{
	return min(min(n1, n2), n3);
}

unsigned getMinOperationsRec(unsigned n, unsigned* cache)
{
	if (n==1)
	{
		return 0;
	}

	if (cache[n]!=0)
	{
		return cache[n];
	}

	int div2 = INT_MAX, div3 = INT_MAX, min1 = INT_MAX;

	if (n%3==0)
	{
		div3 = getMinOperationsRec(n / 3, cache);
	}
	if (n%2==0)
	{
		div2 = getMinOperationsRec(n / 2, cache);
	}
	min1 = getMinOperationsRec(n - 1, cache);

	int res = min(min1, div2, div3) + 1;
	cache[n] = res;
	return res;
}

unsigned getMinOperations(unsigned n)
{
	unsigned* cache = new unsigned[n + 1] {0};
	int res = getMinOperationsRec(n, cache);
	delete[] cache;
	return res;
}

//task 03
int sumAllTail(const int* arr, size_t size, int sum = 0)
{
	if (size==0)
	{
		return sum;
	}
	return sumAllTail(arr + 1, size - 1, sum + arr[0]);
}

//task 04
bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

unsigned getSumOfNumsInStr(const char* str, unsigned currentNum = 0, unsigned globalSum = 0)
{
	if (*str=='\0')
	{
		globalSum += currentNum;
		return globalSum;
	}
	if (isDigit(*str))
	{
		currentNum = currentNum * 10 + (*str - '0');
	}
	else
	{
		globalSum += currentNum;
		currentNum = 0;
	}
	return getSumOfNumsInStr(str + 1, currentNum, globalSum);
}

//task 05
void getBoolVectors(bool* arr, size_t size, unsigned beginInd = 0)
{
	if (beginInd==size)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << std::endl;
		return;
	}
	arr[beginInd] = 0;
	getBoolVectors(arr, size, beginInd + 1);
	arr[beginInd] = 1;
	getBoolVectors(arr, size, beginInd + 1);
}

//backtracking
const size_t rows = 6;
const size_t cols = 5;

bool isValid(int x, int y)
{
	return x >= 0 && y >= 0 && x < rows && y < cols;
}

bool findPathRec(const char fild[rows][cols], bool visited[rows][cols], int currX, int currY, int destX, int destY)
{
	if (!isValid(currX,currY)||fild[currX][currY]!=' '||visited[currX][currY])
	{
		return false;
	}

	visited[currX][currY] = true;

	if (currX==destX&&currY==destY)
	{
		return true;
	}

	bool foundPath = findPathRec(fild, visited, currX + 1, currY, destX, destY) ||
		findPathRec(fild, visited, currX, currY + 1, destX, destY) ||
		findPathRec(fild, visited, currX - 1, currY, destX, destY) ||
		findPathRec(fild, visited, currX, currY - 1, destX, destY);

	if (!foundPath)
	{
		visited[currX][currY] = false;
	}

	return foundPath;
}

void printPath(const char field[rows][cols], const bool visited[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (visited[i][j])
			{
				std::cout << "| 1 |";
			}
			else
			{
				std::cout << "| " << field[i][j] << " |";
			}
		}
		std::cout << std::endl;
	}
}

bool findPath(const char field[rows][cols], int startX, int startY, int destX, int destY)
{
	bool visited[rows][cols]{ false };
	bool containsPath = findPathRec(field, visited, startX, startY, destX, destY);
	if (containsPath)
	{
		printPath(field, visited);
	}
	else
	{
		std::cout << "NO PATH!" << std::endl;
	}
	return containsPath;
}

//task 07 funkcii ot po visok red

bool areOnesAndZeroEqual(const bool* arr, size_t size)
{
	int zeros = 0, ones = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i]==0)
		{
			zeros++;
		}
		else
		{
			ones++;
		}
	}
	return zeros == ones;
}

void genBoolVectors(bool* arr, size_t size, bool(*filter)(const bool* arr, size_t size), unsigned beginInd = 0)
{
	if (beginInd==size)
	{
		if (filter(arr,size))
		{
			for (int i = 0; i < size; i++)
			{
				std::cout << arr[i] << ' ';
			}
			std::cout << std::endl;
		}
		return;
	}
	arr[beginInd] = 0;
	genBoolVectors(arr, size, filter, beginInd + 1);
	arr[beginInd] = 1;
	genBoolVectors(arr, size, filter, beginInd + 1);
}

//task 08
unsigned getCharsCountCond(const char* str, bool(*pred)(char))
{
	unsigned count = 0;
	while (*str)
	{
		if (pred(*str))
		{
			count++;
		}
		str++;
	}
	return count;
}

int main()
{
	//task 01
	/*std::cout << fibb(45);*/

	//task 02
	/*std::cout << getMinOperations(24);*/

	//03
	/*int arr[5] = { 3,5,1,4,2 };
	std::cout << sumAllTail(arr, 5);*/

	//04
	/*std::cout << getSumOfNumsInStr("asd123as33d");*/

	//05
	//const size_t size = 3;
	//bool arr[size];
	//getBoolVectors(arr, size);

	//06
	//char field[rows][cols]
	//{
	//	{' ', ' ', ' ', ' ', ' '},
	//	{' ', ' ', ' ', ' ', ' '},
	//	{' ', 'X', ' ', ' ', ' '},
	//	{' ', 'X', ' ', 'X', 'X'},
	//	{'X', 'X', ' ', ' ', ' '},
	//	{' ', ' ', ' ', 'X', ' '}

	//};

	//findPath(field, 3, 0, 5, 4);

	//07
	/*const size_t size = 4;
	bool arr[size];
	genBoolVectors(arr, size, areOnesAndZeroEqual);*/

	//08
	std:: cout << "Digits count: "<<getCharsCountCond("abc341XY", isDigit) << std::endl;
	std::cout << "All chars: " << getCharsCountCond("abc341XY", [](char ch) {return true; })<<std::endl;
	std::cout << "Lower letters: " << getCharsCountCond("abc341XY", [](char ch) {return ch >= 'a' && ch <= 'z'; }) << std::endl;
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
