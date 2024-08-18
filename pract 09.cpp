// pract 09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
constexpr size_t MAX_SIZE = 3;

// task 01
int findSmallestElement(const int mtx[][MAX_SIZE], size_t size1, size_t size2)
{
	int min = mtx[0][0];
	for (size_t i = 0; i < size1; i++)
	{
		for (size_t j = 0; j < size2; j++)
		{
			if (mtx[i][j]<min)
			{
				min = mtx[i][j];
			}
		}
	}
	return min;
}

void printDiagonals(const int mtx[][MAX_SIZE], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << mtx[i][i] << ' ';
	}
	std::cout << std::endl;

	for (size_t i = 0; i < size; i++)
	{
		std::cout << mtx[i][size - 1 - i]<<' ';
	}
	std::cout << std::endl;
}

void printZigZag(const int mtx[][MAX_SIZE], size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (i%2==0)
			{
				std::cout << mtx[i][j] << ' ';
			}
			else
			{
				std::cout << mtx[i][m - j - 1] << ' ';
			}
		}
		std::cout<<std::endl;
	}
}

//task 04
bool isTrinagularMatrix(const int mtx[][MAX_SIZE], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (mtx[i][j]!=0)
			{
				return false;
			}
		}
	}
	return true;
}

//task 05
void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void transposeMatrix(int mtx[][MAX_SIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			int temp = mtx[i][j];
			mtx[i][j] = mtx[j][i];
			mtx[j][i] = temp;
		}
	}
}

void printMatrix(const int mtx[][MAX_SIZE], int n, int m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			std::cout << mtx[i][j] << ' ';
		}
		std::cout<<std::endl;
	}
}

//task 06
constexpr size_t MAX_SIZE1 = 4;
int getSumOfRow(const int mtx[][MAX_SIZE1], size_t cols, int row)
{
	int sum = 0;
	for (size_t i = 0; i < cols; i++)
	{
		sum += mtx[row][i];
	}
	return sum;
}

int getSumOfAllRows(const int mtx[][MAX_SIZE1], size_t rows, size_t cols)
{
	int sum = 0;
	for (size_t i = 0; i < rows; i++)
	{
		sum += getSumOfRow(mtx, cols, i);
	}
	return sum;
}

int getSumOfCol(const int mtx[][MAX_SIZE1], size_t rows, int col)
{
	int sum = 0;
	for (size_t i = 0; i < rows; i++)
	{
		sum += mtx[i][col];
	}
	return sum;
}

int getSumOfAllCols(const int mtx[][MAX_SIZE1], size_t rows, size_t cols)
{
	int sum = 0;
	for (size_t i = 0; i < cols; i++)
	{
		sum += getSumOfCol(mtx, rows, i);
	}
	return sum;
}

int getSumOfMainDiagonal(const int mtx[][MAX_SIZE1], size_t size)
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += mtx[i][i];
	}
	return sum;
}

int getSumSecondaryDiagonal(const int mtx[][MAX_SIZE1], size_t size)
{
	int sum=0;
	for (size_t i = 0; i < size; i++)
	{
		sum += mtx[i][size - 1 - i];
	}
	return sum;
}

bool isMagicSquare(const int mtx[][MAX_SIZE1], size_t size)
{
	int sumOfRowZero = getSumOfRow(mtx, size, 0);
	int sumOfAllRows = getSumOfAllRows(mtx, size, size);
	if (sumOfRowZero!=sumOfAllRows/size)
	{
		return false;
	}
	int sumOfColZero = getSumOfCol(mtx, size, 0);
	int sumOfAllCols = getSumOfAllCols(mtx, size, size);
	if (sumOfColZero!=sumOfAllCols/size)
	{
		return false;
	}
	int sumOfMainDiagonal = getSumOfMainDiagonal(mtx, size);
	int sumOfSecondaryDiagonal = getSumSecondaryDiagonal(mtx, size);
	if (sumOfRowZero==sumOfColZero&&sumOfColZero==sumOfMainDiagonal&&sumOfMainDiagonal==sumOfSecondaryDiagonal)
	{
		return true;
	}
	return false;
}

//2 nachin
bool isMagicSquare2(const int mtx[][MAX_SIZE1], size_t size)
{
	int targetSum = getSumOfRow(mtx, size, 0);

	for (size_t i = 1; i < size; i++)
	{
		if (getSumOfRow(mtx, size, i) != targetSum)
		{
			return false;
		}
	}

	for (size_t i = 0; i < size; i++)
	{
		if (getSumOfCol(mtx, size, i) != targetSum)
		{
			return false;
		}
	}

	if (getSumOfMainDiagonal(mtx, size) != targetSum || getSumSecondaryDiagonal(mtx, size) != targetSum)
	{
		return false;
	}

	return true;
}

//task 06
void sumMatrices(int mtx1[][MAX_SIZE], const int mtx2[][MAX_SIZE], int n1, int m1, int n2, int m2)
{
	if (n1!=n2||m1!=m2)
	{
		return;
	}
	for (size_t i = 0; i < n1; i++)
	{
		for (size_t j = 0; j < m1; j++)
		{
			mtx1[i][j] += mtx2[i][j];
		}
	}
}

void multiplyMatrixByScalar(int mtx[][MAX_SIZE], int n, int m, int scalar)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			mtx[i][j] *= scalar;
		}
	}
}

//task 09
void printTopRow(const int mtx[][MAX_SIZE], int startCol, int endCol, int currentRow)
{
	for (int i = startCol; i <= endCol; i++)
	{
		std::cout << mtx[currentRow][i] << ' ';
	}
}

void printRightCol(const int mtx[][MAX_SIZE], int startRow, int endRow, int currentCol)
{
	for (int i = startRow; i <= endRow; i++)
	{
		std::cout << mtx[i][currentCol] << ' ';
	}
}

void printBottomRow(const int mtx[][MAX_SIZE], int startCol, int endCol, int currentRow)
{
	for (int i = startCol; i >= endCol; i--)
	{
		std::cout << mtx[currentRow][i] << ' ';
	}
}

void printLeftCol(const int mtx[][MAX_SIZE], int startRow, int endRow, int currentCol)
{
	for (int i = startRow; i >= endRow; i--)
	{
		std::cout << mtx[i][currentCol] << ' ';
	}
}
 
void printSpirally(const int mtx[][MAX_SIZE], size_t rows, size_t cols)
{
	int top = 0;
	int bottom = rows - 1;
	int left = 0;
	int right = cols - 1;
	while (top<=bottom&&left<=right)
	{
		printTopRow(mtx, left, right, top);
		top++;
		if (top>bottom)
		{
			break;
		}

		printRightCol(mtx, top, bottom, right);
		right--;
		if (left>right)
		{
			break;
		}

		printBottomRow(mtx, right, left, bottom);
		bottom--;
		if (top>bottom)
		{
			break;
		}

		printLeftCol(mtx, bottom, top, left);
		left++;
	}
}

//task 10
void turnMatrixRight(const int mtx[][MAX_SIZE], int res[][MAX_SIZE], size_t rows, size_t cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			/*res[i][cols - j - 1] = mtx[j][i];*/
			res[i][j] = mtx[cols - j - 1][i];
		}
	}
}
int main()
{
    
	int mtx[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	//01
	//std::cout << findSmallestElement(mtx, 3, 3) << std::endl;
	//std::cout << std::endl;
	////02
	//printDiagonals(mtx, 3);
	//std::cout << std::endl;
	////03
	//printZigZag(mtx, 3, 3);
	//std::cout << std::endl;
	////04
	//int mtx1[3][3]{ {5,1,5},{0,5,9},{0,0,7} };
	//std::cout << isTrinagularMatrix(mtx1, 3) << std::endl;
	//std::cout << std::endl;
	////05
	//transposeMatrix(mtx, 3);
	//printMatrix(mtx, 3, 3);
	//std::cout << std::endl;
	////06
	//int mtx2[4][4]={ {16,3,2,13},{5,10,11,8},{9,6,7,12},{4,15,14,1} };
	//std::cout << isMagicSquare(mtx2, 4) << std::endl;
	//std::cout << std::endl;
	////07
	//int matrix1[2][3] = { {1,2,3}, {4,5,6} };
	///*int matrix2[2][3] = { { 5,6,7 }, {8,9,10} };
	//sumMatrices(matrix1, matrix2, 2, 3, 2,3);
	//printMatrix(matrix1, 2, 3);*/
	///*std::cout << std::endl;*/
	//multiplyMatrixByScalar(matrix1, 2, 3, 3);
	//printMatrix(matrix1, 2, 3);
	//std::cout << std::endl;
	//09
	/*printSpirally(mtx, 3, 3);
	std::cout << std::endl;*/
	//10
	int res[3][3];
	turnMatrixRight(mtx, res, 3, 3);
	printMatrix(res, 3, 3);
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
