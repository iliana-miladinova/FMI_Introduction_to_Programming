// seminar 09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//tic tac toe
const size_t N = 3;
const unsigned PLAYERS_COUNT = 2;
const unsigned LINE_LENGTH = 3;
const char EMPTRY_FIELD = ' ';

void init(char field[][N], char ch)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			field[i][j] = ch;
		}
	}
}

void print(const char field[][N])
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			std::cout << '[' << field[i][j] << ']';
		}
		std::cout<<std::endl;
	}
}

bool areValidIndices(int x, int y)
{
	return x >= 0 && y >= 0 && x < N && y < N;
}

void input(char field[][N], int& x, int& y)
{
	std::cin >> x >> y;
	while (!areValidIndices(x,y)||field[x][y]!=EMPTRY_FIELD)
	{
		std::cin >> x >> y;
	}
}

int getConsecutiveDirection(const char field[][N], int row, int col, int rowMove, int colMove)
{
	char ch = field[row][col];

	int count = 0;
	while (areValidIndices(row,col) && field[row][col]==ch)
	{
		count++;
		row += rowMove;
		col += colMove;
	}
	return count;
}

unsigned getConsecutiveLine(const char field[][N], int row, int col, int rowMove, int colMove)
{
	return  getConsecutiveDirection(field, row, col, rowMove, colMove) +
		  getConsecutiveDirection(field, row, col, -rowMove, -colMove) - 1;
}

bool isWinningMove(const char field[][N], int row, int col)
{
	return  getConsecutiveLine(field, row, col, 0, 1) >= LINE_LENGTH || //horizontal
		getConsecutiveLine(field, row, col, 1, 0) >= LINE_LENGTH || //vertical
		getConsecutiveLine(field, row, col, 1, 1) >= LINE_LENGTH || //main diagonal
		getConsecutiveLine(field, row, col, 1, -1) >= LINE_LENGTH;   //anti diagonal

}

//linear equationSolver
constexpr size_t n = 2;
void printMatrix(const double matrix[][n+1], size_t rows, size_t cols)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout<<std::endl;
	}
}

void devideBy(double arr[], size_t size, double by)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] /= by;
	}
}

void substract(double first[], const double second[], double coef, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		first[i] -= coef * second[i];
	}
}

void makeAllZero(double matrix[][n+1], size_t rows, size_t cols, int currRow)
{
	for (size_t i = 0; i < rows; i++)
	{
		if (i!=currRow)
		{
			substract(matrix[i], matrix[currRow], matrix[i][currRow], cols);
		}
	}
}

void gauss(double matrix[][n+1], size_t n, double res[])
{
	size_t rows = n;
	size_t cols = n + 1;
	for (size_t i = 0; i < rows; i++)
	{
		devideBy(matrix[i], cols, matrix[i][i]);
		makeAllZero(matrix, rows, cols, i);
	}
	for (size_t i = 0; i < rows; i++)
	{
		res[i] = matrix[i][cols - 1];
	}
}

//task 01
void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}
const size_t MAX_SIZE = 3;
void transposeMatrix(int matrix[][MAX_SIZE], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i+1; j < size; j++)
		{
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}

void print(int matrix[][MAX_SIZE])
{
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		for (size_t j = 0; j < MAX_SIZE; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout<<std::endl;
	}
}

//task 02
bool isReflexive(const int mtx[][MAX_SIZE], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (mtx[i][i]!=1)
		{
			return false;
		}
	}
	return true;
}

bool isSymetric(const int mtx[][MAX_SIZE], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (mtx[i][j]!=mtx[j][i])
			{
				return false;
			}
		}
	}
	return true;
}

bool isTransitive(const int mtx[][MAX_SIZE], int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (mtx[i][j]==1)
			{
				for (size_t k = 0; k < size; k++)
				{
					if (mtx[j][k]==1&&mtx[i][k]!=1)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

bool isEquivalentRelation(const int mtx[][MAX_SIZE], int size)
{
	return isReflexive(mtx, size) && isSymetric(mtx, size) && isTransitive(mtx, size);
}

//task 03

const size_t MAX_SIZE1 = 2;
int getSumOfProducts(const int mtx1[][MAX_SIZE], const int mtx2[][MAX_SIZE1], int size, int row, int col)
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += mtx1[row][i] * mtx2[i][col];
	}
	return sum;
}

void multiplyMatrices(const int mtx1[][MAX_SIZE], const int mtx2[][MAX_SIZE1], int res[][MAX_SIZE1], int N, int M, int K)
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			res[i][j] = getSumOfProducts(mtx1, mtx2, M, i, j);
		}
	}
}

int main()
{
	//tic tac toe
	/*char field[N][N];
	init(field, EMPTRY_FIELD);
	print(field);

	bool isWinner = false;
	for (size_t i = 0, currPlayer=0; i < N*N, !(isWinner); i++, currPlayer=(currPlayer+1)%PLAYERS_COUNT)
	{
		int row, col;
		input(field, row, col);
		field[row][col] = 'A' + currPlayer;
		print(field);
		isWinner = isWinningMove(field, row, col);
	}
	std::cout << (isWinner ? "Winner!" : "Draw!") << std::endl;*/

	//linear equation solver
	/*constexpr size_t rows = n;
	constexpr size_t cols = n+1;
	double m[rows][cols] = { {2,6,40},
							{4,1,14} };
	double res[rows];
	gauss(m, rows, res);
	for (size_t i = 0; i < rows; i++)
	{
		std::cout << res[i] << ' ';
	}*/

	//task 01
	/*size_t size = 3;
	int m[MAX_SIZE][MAX_SIZE] = { {1,2,3},{4,5,6},{7,8,9} };
	transposeMatrix(m, size);
	print(m);*/

	//02
	/*const size_t size = 3;
	int mtx[MAX_SIZE][MAX_SIZE] = { {1,1,0},
									{1,1,0},
									{0,0,1} };
	std::cout << isEquivalentRelation(mtx, size);*/

	//03
	int mtx1[2][MAX_SIZE] = { {1,2,3},{4,5,6} };
	int mtx2[3][MAX_SIZE1] = { {7,8},{9,10},{11,12} };
	int res[2][MAX_SIZE1];
	multiplyMatrices(mtx1, mtx2, res, 2, 3, 2);
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			std::cout << res[i][j] << ' ';
		}
		std::cout<<std::endl;
	}
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
