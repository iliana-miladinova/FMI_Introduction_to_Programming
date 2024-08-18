// pract 12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void print(int** matrix, int rowsCount, int rowLength)
{
	if (!matrix)
		return;

	for (size_t i = 0; i < rowsCount; i++)
	{
		if (!matrix[i])
			return;
	}

	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t j = 0; j < rowLength; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void free(int** mtx, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] mtx[i];
	}
	delete[] mtx;
}

unsigned myStrlen(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
//task 01
int** removeRowByInd(int** mtx, int row, int rowsCount, int colsCount)
{
	if (!mtx)
	{
		return nullptr;
	}

	int resLen = rowsCount - 1;
	int** res = new int* [resLen];
	for (int i = 0, j=0; i < rowsCount; i++)
	{
		if (i!=(row-1))
		{
			/*res[j] = new int[colsCount];
			for (int k = 0; k < colsCount; k++)
			{
				res[j][k] = mtx[i][k];
			}
			j++;*/
			res[j] = mtx[i];
			j++;
		}
	}

	return res;
}

//task 02
int** removeColByInd(int** mtx, int col, int rowsCount, int colsCount)
{
	if (!mtx || col< 1 || col>colsCount)
	{
		return nullptr;
	}

	for (size_t i = 0; i < rowsCount; i++)
	{
		if (!mtx[i])
		{
			return nullptr;
		}
	}

	int** res = new int* [rowsCount];
	for (int i = 0; i < rowsCount; i++)
	{
		res[i] = new int[colsCount - 1];
		for (int j = 0, k=0; j < colsCount; j++)
		{
			if (j!=(col-1))
			{
				res[i][k] = mtx[i][j];
				k++;
			}
		}
	}
	return res;
}

//task 03
int** transposeMatrix(int** mtx, int rowsCount, int colsCount)
{
	if (!mtx)
	{
		return nullptr;
	}

	for (int i = 0; i < rowsCount; i++)
	{
		if (!mtx[i])
		{
			return nullptr;
		}
	}

	int** res = new int* [colsCount];
	for (int i = 0; i < colsCount; i++)
	{
		res[i] = new int[rowsCount];
	}
	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < colsCount; j++)
		{
			res[j][i] = mtx[i][j];
		}
	}

	return res;
}

//task 04
int devideAndRound(int nom, int denom)
{
	if (denom==0)
	{
		return -1;
	}

	int res = nom / denom;
	int ostatak = nom % denom;

	if (ostatak*2>=denom)
	{
		res += 1;
	}

	return res;
}

char** getZigZag(const char* str)
{
	if (!str)
	{
		return nullptr;
	}
	int lenStr = myStrlen(str);
	int resCols = devideAndRound(lenStr, 2);
	int resRows = 3;
	char** res = new char* [resRows];

	for (int i = 0; i < resRows; i++)
	{
		res[i] = new char[resCols];
		for (int j = 0; j < resCols; j++)
		{
			res[i][j] = ' ';
		}
	}
	int strInd = 0;
	bool goingDown = false;
	int row = 0;
	for (int col = 0; col < resCols; col++)
	{
		if (strInd >= lenStr) {
			break; // Излизане от цикъла, ако всички символи са вече използвани
		}

		// Запълваме символите в текущата колона
		while (row >= 0 && row < resRows) {
			if (strInd < lenStr) {
				res[row][col] = str[strInd++];
			}
			// Проверяваме дали сме достигнали до началния или последния ред
			if (row == 0 || row == resRows - 1) {
				goingDown = !goingDown; // Превключване на посоката на запълване
			}
			if (goingDown) {
				row += 1; // Преминаване надолу
			}
			else {
				row -= 1; // Преминаване нагоре
			}
		}
		// След завършване на текущата колона, възстановяваме `row` за следващата колона
		row = (goingDown ? resRows - 1 : 0);
		
			/*if (j%2==0)
			{
				res[i][j] = str[strInd];
				strInd++;
			}
			else
			{
				if (i==1)
				{
					res[i][j] = str[strInd];
					strInd++;
				}
			}
			if (strInd>lenStr)
			{
				break;
			}*/
	}
	return res;
}

void printZigZag(char** matrix, int numRows, int numCols)
{
	for (int i = 0; i < numRows; i++) 
	{
		for (int j = 0; j < numCols; j++) 
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void freeZigZag(char** matrix, int numRows)
{
	for (int i = 0; i < numRows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

//task 05
unsigned countCharOccurances(const char* str, char separator)
{
	if (!str)
	{
		return 0;
	}

	unsigned count = 0;
	while (*str)
	{
		if (*str==separator)
		{
			count++;
		}
		str++;
	}
	return count;
}

unsigned getEndOfToken(const char* str, char separator)
{
	if (!str)
	{
		return 0;
	}
	for (int i = 0; ; i++)
	{
		if (str[i]=='\0'||str[i]==separator)
		{
			return i;
		}
	}
	return -1;
}

void copyNChars(const char* source, char* dest, unsigned n)
{
	if (!source||!dest)
	{
		return;
	}
	for (int i = 0; i < n; i++)
	{
		dest[i] = source[i];
	}
}

char** split(const char* str, char separator)
{
	if (!str)
	{
		return nullptr;
	}

	unsigned resSize = countCharOccurances(str, separator) + 2;
	char** res = new char* [resSize];
	res[resSize - 1] = nullptr;

	unsigned resInd = 0;
	while (*str)
	{
		int sepInd = getEndOfToken(str, separator);

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

void printToken(char** tokens)
{
	while (*tokens)
	{
		std::cout << *tokens << std::endl;
		tokens++;
	}
}

void freeTokens(char** tokens)
{
	for (int i = 0; tokens[i]!=nullptr; i++)
	{
		delete[] tokens[i];
	}
	delete[] tokens;
}

//task 07
int** createTransformedMatrix(int** mtx, int rows, int cols, int& newRows, int& newCols)
{
	if (!mtx)
	{
		return nullptr;
	}
	for (int i = 0; i < rows; i++)
	{
		if (!mtx[i])
		{
			return nullptr;
		}
	}

	//newRows = rows / 2;
	//newCols = cols * 2;

	//int** res = new int* [newRows];
	//int startRow = 0;
	//int endRow = rows - 1;
	//if (rows % 2 != 0)
	//{
	//	newRows += 1;
	//	for (int i = 0; i < newRows - 1; i++)
	//	{
	//		res[i] = new int[newCols];
	//		/*for (int j = 0; j < newCols; j++)
	//		{
	//			res[i][j] = 0;
	//		}*/
	//	}
	//	res[newRows-1] = new int[cols];
	//	for (int i = 0; i < newRows - 1; i++)
	//	{
	//		for (int j = 0; j < cols; j++)
	//		{
	//			if (startRow <= endRow)
	//			{
	//				res[i][j] = mtx[startRow][j];
	//				res[i][cols + j] = mtx[endRow][j];
	//			}
	//		}
	//		startRow++;
	//		endRow--;
	//	}
	//	/*if (rows % 2 != 0)
	//	{*/
	//	int midRow = rows / 2;
	//	for (int i = 0; i < cols; i++)
	//	{
	//		res[newRows - 1][i] = mtx[midRow][i];
	//	}
	//	/*}*/
	//}
	//else
	//{
	//	for (int i = 0; i < newRows; i++)
	//	{
	//		res[i] = new int[newCols];
	//	}
	//	for (int i = 0; i < newRows; i++)
	//	{
	//		for (int j = 0; j < cols; j++)
	//		{
	//			if (startRow <= endRow)
	//			{
	//				res[i][j] = mtx[startRow][j];
	//				res[i][cols + j] = mtx[endRow][j];
	//			}
	//		}
	//		startRow++;
	//		endRow--;
	//	}
	//}
	//return res;
	newRows = rows / 2;
	if (rows % 2 != 0)
	{
		newRows += 1;
	}
	newCols = cols * 2;

	int** res = new int* [newRows];
	for (int i = 0; i < newRows; i++) 
	{
		res[i] = new int[newCols];
		// Инициализация с 0
		/*for (int j = 0; j < newCols; j++) 
		{
			res[i][j] = 0;
		}*/
		/*if (rows%2!=0&&i==newRows-1)
		{
			res[i] = new int[cols];
		}*/
	}

	int startRow = 0;
	int endRow = rows - 1;

	for (int i = 0; i < newRows; i++) 
	{ // Тук е -1, защото последният ред е специален случай
		for (int j = 0; j < cols; j++) 
		{
			res[i][j] = mtx[startRow][j];
			res[i][cols + j] = mtx[endRow][j];
		}
		startRow++;
		endRow--;
	}

	// Ако броят на редовете е нечетен, добавяме реда по средата
	/*if (rows % 2 != 0) 
	{
		int midRow = rows / 2;
		for (int j = 0; j < cols; j++) {
			res[newRows - 1][j] = mtx[midRow][j];
		}
	}*/

	return res;
}
int main()
{
	//01
	/*int i = 2;
	const int rowsCount = 3;
	const int colsCount = 3;
	int** matrix = new int* [rowsCount];

	matrix[0] = new int[colsCount] { 1, 2, 3};
	matrix[1] = new int[colsCount] { 4, 5, 6 };
	matrix[2] = new int[colsCount] { 7, 8, 9 };

	int** res = removeRowByInd(matrix, i, rowsCount, colsCount);
	print(res, rowsCount-1, colsCount);
	free(res, rowsCount-1);*/

	//02
	/*int i = 2;
	const int rowsCount = 3;
	const int colsCount = 3;
	int** mtx = new int* [rowsCount];

	mtx[0] = new int[colsCount] {1, 2, 3};
	mtx[1] = new int[colsCount] {4, 5, 6};
	mtx[2] = new int[colsCount] {7, 8, 9};

	int** res = removeColByInd(mtx, i, rowsCount, colsCount);
	print(res, rowsCount, colsCount - 1);
	free(res, rowsCount);*/

	//03
	/*const int rows = 3;
	const int cols = 2;
	int** mtx = new int* [rows];

	mtx[0] = new int[cols] {1, 3};
	mtx[1] = new int[cols] {4, 6};
	mtx[2] = new int[cols] {7, 9};

	int** res = transposeMatrix(mtx, rows, cols);
	print(res, cols, rows);
	free(res, cols);*/

	//04
	/*const char* str = "PAYPALISHIRING";
	int numRows = 3;

	char** zigzagMatrix = getZigZag(str);
	if (zigzagMatrix) {
		printZigZag(zigzagMatrix, numRows, devideAndRound(std::strlen(str), numRows));
		freeZigZag(zigzagMatrix, numRows);
	}*/

	//05
	char** res = split("Hello:my:name:is", ':');

	printToken(res);

	freeTokens(res);

	//07
	int originalRows = 5;
	int originalCols = 2;

	// Инициализация на оригиналната матрица
	int** originalMatrix = new int* [originalRows];
	originalMatrix[0] = new int[originalCols] {0, 1};
	originalMatrix[1] = new int[originalCols] {0, 2};
	originalMatrix[2] = new int[originalCols] {1, 4};
	originalMatrix[3] = new int[originalCols] {1, 5};
	originalMatrix[4] = new int[originalCols] {2, 3};
	/*originalMatrix[5] = new int[originalCols] {2, 3};*/
	int newRows, newCols;
	int** transformedMatrix = createTransformedMatrix(originalMatrix, originalRows, originalCols, newRows, newCols);

	print(transformedMatrix, newRows, newCols);

	// Освобождаване на паметта
	free(originalMatrix, originalRows);
	free(transformedMatrix, newRows);
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
