// exam prep 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//2023-2024
//task 01
bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

unsigned getDigitFromChar(char ch)
{
	return ch - '0';
}

char getCharFromDigit(unsigned digit)
{
	return digit + '0';
}

bool containsDigit(const char* str, unsigned digit)
{
	while (*str)
	{
		char dig = getCharFromDigit(digit);
		if (*str==dig)
		{
			return true;
		}
		str++;
	}
	return false;
}

bool containsAlldigits(const char* str)
{
	/*int count = 0;*/
	for (int i = 9; i >= 0; i--)
	{
		if (!containsDigit(str,i))
		{
			return false;
			/*count++;*/
		}
	}
	return true;
	/*if (count==10)
	{
		return true;
	}
	return false;*/
}
int analyzeArray(const char* str)
{
	if (!str||containsAlldigits(str))
	{
		return -1;
	}

	for (int i = 9; i >= 0; i--)
	{
		if (!containsDigit(str,i))
		{
			return i;
		}
	}
	return -1;
}

//task 02
int findIndex(const int arr[], size_t L)
{
	int count = 0;
	int globalCount = 0;
	for (int i = 0; i < L; i++)
	{
		if (arr[i]>=count+1)
		{
			count++;
		}
		else
		{
			if (count>globalCount)
			{
				globalCount = count;
			}
			count = 0;
		}
	}
	return globalCount;
}

//task 03
long maxNum(long num1, long num2)
{
	return num1 > num2 ? num1 : num2;
}

long minNum(long num1, long num2)
{
	return num1 < num2 ? num1 : num2;
}

unsigned numLen(long num)
{
	if (num==0)
	{
		return 1;
	}
	unsigned count = 0;
	while (num!=0)
	{
		count++;
		num /= 10;
	}
	return count;
}

char* getStringFromNum(long num)
{
	unsigned countDigits = numLen(num);
	char* arr = new char[countDigits + 1];
	for (int i = countDigits-1; i >=0 ; i--)
	{
		arr[i] = getCharFromDigit(num % 10);
		num /= 10;
	}
	arr[countDigits] = '\0';
	return arr;
}
char* findDiff(const long arr[], size_t N)
{
	if (N<2)
	{
		return nullptr;
	}


	long num1 = arr[0];
	long num2 = arr[1];
	long minDiff = abs(arr[0] - arr[1]);
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (abs(arr[i]-arr[j])<minDiff)
			{
				minDiff = abs(arr[i] - arr[j]);
				num1 = arr[i];
				num2 = arr[j];
			}
		}
	}

	long max = maxNum(num1, num2);
	long min = minNum(num1, num2);

	unsigned lenMax = numLen(max);
	unsigned lenMin = numLen(min);
	unsigned resLen = lenMax + lenMin + 1;//zaradi zapetayata
	char* res = new char[resLen + 1];//'\0'

	char* arrMax = getStringFromNum(max);
	char* arrMin = getStringFromNum(min);
	int resInd = 0;
	for (int i = 0; i < lenMax; i++)
	{
		res[resInd++] = arrMax[i];
	}
	res[resInd++] = ',';
	for (int i = 0; i < lenMin; i++)
	{
		res[resInd++] = arrMin[i];
	}
	res[resInd] = '\0';

	delete[] arrMin;
	delete[] arrMax;
	return res;
}

//2 grupa
//task 01
long findSeq(const char* arr, char S)
{
	if (!arr)
	{
		return 0;
	}
	int count = 0;
	int globalCount = 0;
	while (*arr)
	{
		if (*arr==S)
		{
			count++;
		}
		else
		{
			if (count>globalCount)
			{
				globalCount = count;
			}
			count = 0;
		}
		arr++;
	}
	if (count>globalCount)
	{
		globalCount = count;
	}
	return globalCount;
}

//task 02
bool searchInText1(const char* const* grid, size_t M, size_t N, bool** visited, int currRow, int currCol, int index, const char* word)
{
	if (!grid)
	{
		return false;
	}
	for (int i = 0; i < M; i++)
	{
		if (!grid[i])
		{
			return false;
		}
	}
	int wordLen = strlen(word);
	if (wordLen == index)
	{
		return true;
	}
	if (currRow<0 || currRow>M - 1 || currCol<0 || currCol>N - 1 || visited[currRow][currCol] || grid[currRow][currCol] != word[index])
	{
		return false;
	}

	visited[currRow][currCol] = true;
	bool found = searchInText1(grid, M, N, visited, currRow + 1, currCol, index + 1, word) ||
		searchInText1(grid, M, N, visited, currRow - 1, currCol, index + 1, word) ||
		searchInText1(grid, M, N, visited, currRow, currCol + 1, index + 1, word) ||
		searchInText1(grid, M, N, visited, currRow, currCol - 1, index + 1, word);
	if (!found)
	{
		visited[currRow][currCol] = false;
	}
	return found;
}

void freeMatrix(bool** visited, size_t M)
{
	for (int i = 0; i < M; i++)
	{
		delete[] visited[i];
	}
	delete[] visited;
}
bool findWord(const char* const* grid, size_t M, size_t N, const char* word)
{
	bool** visited = new bool* [M];
	for (int i = 0; i < M; i++)
	{
		visited[i] = new bool[N] {false};
	}
	int index = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (grid[i][j]==word[index])
			{
				if (searchInText1(grid,M,N,visited,i,j,index,word))
				{
					freeMatrix(visited,M);
					return true;
				}
			}
		}
	}
	freeMatrix(visited,M);
	return false;
}

//task 03
unsigned powerOfTwo(unsigned n)
{
	return 1 << n;
}
int getTotalLen(const int* arr, size_t N)
{
	int totalSets = powerOfTwo(N) - 1;
	int size = 0;
	for (int i = 1; i <=totalSets ; i++)
	{
		int temp = i;
		for (int j = 0; j <N ; j++)
		{
			if (temp%2!=0)
			{
				size++;
			}
			temp /= 2;
			
		}
		size++;
	}
	size += 1;
	return size;
}
int* findSets(const int* arr, size_t N)
{
	if (!arr)
	{
		return nullptr;
	}

	int totalSets = powerOfTwo(N) - 1;
	int resLen = getTotalLen(arr, N);
	int* res = new int[resLen];
	int resInd = 0;
	for (int i = 1; i <=totalSets ; i++)
	{
		int temp = i;
		for (int j = 0; j < N; j++)
		{
			if (temp%2!=0)
			{
				res[resInd] = arr[j];
				resInd++;
			}
			temp /= 2;
		}
		res[resInd] = 0;
		resInd++;
	}
	res[resInd] = 0;
	/*resInd++;
	res[resInd++] = 0;*/
	return res;
}

int main()
{
    //01
	/*char str[] = "Iliana2007";
	std::cout << analyzeArray(str);*/

	//02
	/*int arr[16] = { 1,2,3,4,5,2,1,2,3,4,5,6,5,2,3,4 };
	std::cout << findIndex(arr, 16);*/

	//task 03
	/*long arr[9] = { 14,13,8,5,1,2,18,19,6 };
	char* res = findDiff(arr, 9);
	std::cout << res;*/

	//task 01
	/*std::cout << findSeq("aabbbbddddccdddddddeeedddddddd", 'd');*/

	//task 02
	/*const char* grid[] = { "abc",
							"def",
							"ghi",
							"jkl" };
	const char* word = "abcfehik";
	std::cout << findWord(grid, 4, 4, word);*/

	//task 03
	int arr[4] = { 1,2,3,4 };
	int* res = findSets(arr, 4);
	for (int i = 0; i < getTotalLen(arr,4); i++)
	{
		std::cout << res[i];
	}
	delete[] res;
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
