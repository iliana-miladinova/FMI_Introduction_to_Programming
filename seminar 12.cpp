// seminar 12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//task 01
//each rows have two "system" variables.
//[0] is the count of the elements in the row
//[1] is the sum of the elements of the row 
int** createMatrix(int rows)
{
    int** mtx = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		int colls;
		std::cin >> colls;
		mtx[i] = new int[colls + 2] {0};
		mtx[i][0] = colls;
	}
	return mtx;
}

void freeMatrix(int** mtx, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] mtx[i];
	}
	delete[] mtx;
}

void print(int** mtx, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		int sizeOfRow = mtx[i][0];
		for (int j = 2; j < sizeOfRow+2; j++)
		{
			std::cout << mtx[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void swap(int*& first, int*& second)
{
	int* temp = first;
	first = second;
	second = temp;
}

void moveRowToTheCorrectPos(int** mtx, int lastModifiedRow)
{
	int curr = lastModifiedRow;
	while (curr>0&&mtx[curr][1]>mtx[curr-1][1])
	{
		swap(mtx[curr], mtx[curr - 1]);
		curr--;
	}
}

void addPoints(int** mtx, int row, int coll, int point)
{
	mtx[row][coll + 2] += point;
	mtx[row][1] += point;
	moveRowToTheCorrectPos(mtx, row);
}

//task 02
bool isWordSymbol(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

unsigned getWordsCount(const char* str)
{
	/*if (!str)
	{
		return 0;
	}*/
	unsigned count = 0;
	while (*str)
	{
		if (isWordSymbol(*str) && !isWordSymbol(*(str+1)))
		{
			count++;
		}
		str++;
	}
	return count;
}

void skipInvalid(const char*& str)
{
	/*if (*str)
	{
		return;
	}*/

	while (*str && !isWordSymbol(*str))
	{
		str++;
	}
}

char* getNextWord(const char*& str)
{/*
	if (!str)
	{
		return nullptr;
	}*/

	unsigned ind = 0;

	while (isWordSymbol(str[ind]))
	{
		ind++;
	}
	char* word = new char[ind + 1];
	word[ind] = '\0';

	for (int i = 0; i < ind; i++)
	{
		word[i] = str[i];
	}
	str += ind;
	return word;
}

char** tokenize(const char* str, size_t& size)
{
	unsigned wordsCount = getWordsCount(str);
	char** words = new char* [wordsCount];

	unsigned currentWordIndex = 0;
	while (*str)
	{
		skipInvalid(str);

		if (!(*str))
		{
			break;
		}

		char* word = getNextWord(str);

		words[currentWordIndex] = word;
		currentWordIndex++;
	}
	size = wordsCount; //or we can skip the size and use a santinel -> nullptr
	return words;
}

void printWords(char** words, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << words[i] << std::endl;
	}
}

void free(char** words, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] words[i];
	}
	delete[] words;
}

//task 03
unsigned countCharOccurances(const char* str, char ch)
{
	if (!str)
	{
		return 0;
	}

	unsigned count = 0;
	while (*str)
	{
		if (*str==ch)
		{
			count++;
		}
		str++;
	}
	return count;
}

unsigned getEndOfTokenIndex(const char* str, unsigned ch)
{
	for (int i = 0; ; i++)
	{
		if (str[i]=='\0'||str[i]==ch)
		{
			return i;
		}
	}
	return -1;
}

void copyNChars(const char* source, char* dest, unsigned n)
{
	for (int i = 0; i < n; i++)
	{
		dest[i] = source[i];
	}
}

char** split(const char* str, char separator)
{
	unsigned resLen = countCharOccurances(str, separator) + 2;
	char** res = new char* [resLen];
	res[resLen - 1] = nullptr;
	unsigned resInd = 0;

	while (*str)
	{
		int sepInd = getEndOfTokenIndex(str, separator);

		char* currToken = new char[sepInd + 1];
		currToken[sepInd] = '\0';

		copyNChars(str, currToken, sepInd);
		str += sepInd;
		res[resInd] = currToken;
		resInd++;
		if (*str==separator)
		{
			str++;
		}
	}
	return res;
}

void printWords1(char** tokens)
{
	while (*tokens)
	{
		std::cout << *tokens << std::endl;
		tokens++;
	}
}

void freeWords(char** tokens)
{
	for (int i = 0; tokens[i]!=nullptr ; i++)
	{
		delete[] tokens[i];
	}
	delete[] tokens;
}
int main()
{
    //01
	/*int rows;
	std::cin >> rows;

	int** mtx = createMatrix(rows);

	print(mtx, rows);

	int queriesCount;
	std::cin >> queriesCount;

	for (int i = 0; i < queriesCount; i++)
	{
		int row, coll, points;
		std::cin >> row >> coll >> points;
		addPoints(mtx, row, coll, points);
		print(mtx, rows);
	}

	print(mtx, rows);
	freeMatrix(mtx, rows);*/

	//02
	/*size_t count;
	char** words = tokenize("hello i am a sentence", count);
	printWords(words, count);
	free(words, count);*/

	//03
	char** res = split("this!is!test!spliting", '!');
	printWords1(res);
	freeWords(res);
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
