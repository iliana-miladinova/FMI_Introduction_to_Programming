// exam prep 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//exam 2020
//task 06
unsigned myStrlen(const char* str)
{
	if (!str)
	{
		return 0;
	}
	int len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}

void myStrcpy(const char* source, char* dest)
{
	if (!source || !dest)
	{
		return;
	}
	while (*source)
	{
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
}

void myStrcat(char* first, const char* second)
{
	if (!first||!second)
	{
		return;
	}
	size_t firstLen = myStrlen(first);
	first += firstLen;
	myStrcpy(second, first);
}

char getCharFromDig(int dig)
{
	if (dig<0||dig>9)
	{
		return '\0';
	}
	return dig + '0';
}

unsigned getNumLength(unsigned num)
{
	if (num==0)
	{
		return 1;
	}

	unsigned len = 0;
	while (num!=0)
	{
		len++;
		num /= 10;

	}
	return len;
}

void toString(int num, char* str)
{
	unsigned len = getNumLength(num);
	for (int i = len-1; i >= 0; i--)
	{
		str[i] = getCharFromDig(num % 10);
		num /= 10;
	}
	str[len] = '\0';
}

char* GetWord(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	int countStartsWithA = 0;
	int countWord = 0;
	int currWordLen = 0;
	for (int i = 0; str[i]!='\0'; i++)
	{
		char ch = str[i];
		if (ch==' '||ch=='\t')
		{
			if (currWordLen>0)
			{
				countWord++;
				currWordLen = 0;
			}
		}
		else
		{
			if (currWordLen==0)
			{
				if (ch=='a'||ch=='A')
				{
					countStartsWithA++;
				}
			}
			currWordLen++;
		}
	}
	if (currWordLen>0)
	{
		countWord++;
	}
	unsigned aLen = getNumLength(countStartsWithA);
	unsigned wordsCountLen = getNumLength(countWord);
	unsigned resLen = aLen + wordsCountLen + 1;
	char* res = new char[resLen+1];
	toString(countStartsWithA, res);
	myStrcat(res, ",");
	toString(countWord, res + strlen(res)); //Тази функция конвертира числото countWord (общия брой на думите) в низ и го записва точно след запетаята, която добавихме в предишната стъпка.
	//countWord е общият брой на думите в низа.
	//strlen(res) връща дължината на текущия низ res.Например, ако res съдържа "4 ", тогава strlen(res) ще върне 2.
	//res + strlen(res) сочи към мястото след интервала в низа, където искаме да запишем countWord.
	//След този ред, ако countWord е 10, res ще съдържа "4, 10\0".

	return res;
}


//07
unsigned countDigits(long N)
{
	if (N==0)
	{
		return 1;
	}
	unsigned count = 0;
	while (N!=0)
	{
		count++;
		N /= 10;
	}
	return count;
}

int* makeArrFromNum(long num)
{
	unsigned len = countDigits(num);
	int* digits = new int[len];
	int digitInd = 0;
	if (num==0)
	{
		digits[digitInd] = num;
	}
	else
	{
		while (num != 0)
		{
			digits[digitInd] = num % 10;
			digitInd++;
			num /= 10;
		}
	}
	return digits;
}
void swap(int& n1, int& n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}
void selectionSort(int* arr, size_t len)
{
	for (int i = 0; i < len-1; i++)
	{
		int minElInd = i;
		for (int j = i+1; j < len; j++)
		{
			if (arr[j]<arr[minElInd])
			{
				minElInd = j;
			}
		}
		if (minElInd != i)
		{
			swap(arr[i], arr[minElInd]);
		}
	}
}

//unsigned countRepeatingDigits(const int* arr, size_t len, int dig)
//{
//	unsigned count = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i]==dig)
//		{
//			count++;
//		}
//	}
//	return count;
//}
int AnalyzeNum(long N)
{
	unsigned len = countDigits(N);
	int* digits = makeArrFromNum(N);

	// Сортираме цифрите по възходящ ред
	selectionSort(digits, len);

	// Проверяваме дали има средна цифра
	int mid = 0;
	int midInd = 0;
	if (len%2==0)
	{
		return -1;
	}
	else
	{
		mid = digits[len / 2];
		midInd = len / 2;
	}

	int countSmaller = 0;
	for (int i = 0; i < midInd ; i++)
	{
		if (digits[i]!=mid && (i==0|| digits[i]!=digits[i-1]))
		{
			countSmaller++;
		}
	}

	int countBigger = 0;
	for (int i = midInd+1; i < len; i++)
	{
		if (digits[i]!=mid && (i==midInd+1||digits[i]!=digits[i-1]))
		{
			countBigger++;
		}
	}

	delete[] digits;
	if (countSmaller==countBigger)
	{
		return mid;
	}
	// Ако няма такава цифра, връщаме -1
	return -1;
}

//task 08
void swap(long& n1, long& n2)
{
	long temp = n1;
	n1 = n2;
	n2 = temp;
}

void ConvertArray(long* arr, long S, long E)
{
	if (!arr|| S<0 || S>E ||E<0)
	{
		return;
	}

	int countSwaps = (E - S + 1) / 2;
	int currS = S;
	int currE = E;
	for (int i = 0; i < countSwaps; i++)
	{
		swap(arr[currS], arr[currE]);
		currS++;
		currE--;
	}

}

void printArr(const long* arr, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

//task 09
int findElement(const long* arr, int l)
{
	if (!arr)
	{
		return -1;
	}

	
	
	for (int i = l-2; i >= 1; i--)
	{
		double average = (arr[i - 1] + arr[i + 1]) / 2;
		if (arr[i]>average)
		{
			return i;
		}
	}
	if (arr[l-1]>arr[l-2])
	{
		return l - 1;
	}
	else if (arr[0]>arr[1])
	{
		return 0;
	}
	return -1;
}

//task 10
constexpr size_t ARRAYS_COUNT = 2;
void copyArr(const int* source, int* dest, int m)
{
	if (!source||!dest)
	{
		return;
	}
	for (int i = 0; i < m; i++)
	{
		dest[i] = source[i];
	}
}
int** mergearrays(const int* arr1, const int* arr2, int m)
{
	if (!arr1||!arr2||m==0)
	{
		return nullptr;
	}

	int** res = new int* [ARRAYS_COUNT];
	res[0] = new int[m];
	res[1] = new int[m];
	copyArr(arr1, res[0], m);
	copyArr(arr2, res[1], m);
	
	return res;
}

void print(int** res, int m)
{
	for (int i = 0; i < 2; i++)
	{
		std::cout << '{';
		for (int j = 0; j < m; j++)
		{
			std::cout << res[i][j];
			if (j<m-1)
			{
				std::cout << ',';
			}
		}
		std::cout << '}';
		if (i < 1)
		{
			std::cout << ',';
		}
	}
}

//example tasks for exam from moodle
//task 1
int* mergeAndSortArray(const int* arr1, size_t size1, const int* arr2, size_t size2)
{
	if (!arr1||!arr2)
	{
		return nullptr;
	}

	size_t resSize = size1 + size2;
	int* res = new int[resSize];

	int arr1Ind = 0;
	int arr2Ind = 0;
	int resInd = 0;

	while (arr1Ind<size1 && arr2Ind<size2)
	{
		if (arr1[arr1Ind]<=arr2[arr2Ind])
		{
			res[resInd] = arr1[arr1Ind];
			arr1Ind++;
		}
		else
		{
			res[resInd] = arr2[arr2Ind];
			arr2Ind++;
		}
		resInd++;
	}

	while (arr1Ind<size1)
	{
		res[resInd] = arr1[arr1Ind];
		resInd++;
		arr1Ind++;
	}

	while (arr2Ind<size2)
	{
		res[resInd] = arr2[arr2Ind];
		resInd++;
		arr2Ind++;
	}

	return res;
}

void printArray(const int* arr, size_t size)
{
	std::cout << "{ ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
		if (i<size-1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "}";
}

//task 03
constexpr size_t MAX_ROWS = 25;
constexpr size_t MAX_COLS = 80;

char** createMatrix()
{
	char** mtx = new char* [MAX_ROWS];
	for (int i = 0; i < MAX_ROWS; i++)
	{
		mtx[i] = new char[MAX_COLS];
	}
	return mtx;
}

void initMatrix(char** mtx)
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			mtx[i][j] = ' ';
		}
	}
}
char** drawRectangle(int N, int M, char ch)
{
	char** mtx = createMatrix();
	initMatrix(mtx);

	int startIndRows = (MAX_ROWS - N) / 2;
	/*int endIndRows = startIndRows + N;*/

	int startIndCols = (MAX_COLS - M) / 2;
	//int endIndCols = startIndCols + M;

	/*for (int i = startIndRows; i < endIndRows; i++)
	{
		for (int j = startIndCols; j < endIndCols; j++)
		{
			mtx[i][j] = ch;
		}
	}*/
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			mtx[startIndRows + i][startIndCols + j] = ch;
		}
	}

	return mtx;
}

void printMatrix(char** mtx)
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			std::cout << mtx[i][j];
		}
		std::cout << std::endl;
	}
}

void free(char** mtx)
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		delete[] mtx[i];
	}
	delete[] mtx;
}

//04
int getSumAboveMainDiagonal(int** arr, size_t N)
{
	if (!arr||N==0)
	{
		return -1;
	}
	for (int i = 0; i < N; i++)
	{
		if (!arr[i])
		{
			return -1;
		}
	}

	int sum = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}

//05
void transposeMatrix(int** mtx, size_t N)
{
	if (!mtx||N==0)
	{
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (!mtx[i])
		{
			return;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = /*0*/ i+1; j < N; j++)
		{
			/*if (i!=j)
			{*/
				int temp = mtx[i][j];
				mtx[i][j] = mtx[j][i];
				mtx[j][i] = temp;
			/*}*/
		}
	}
}

void printMtx(int** mtx, size_t N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << mtx[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void free(int** mtx, size_t N)
{
	for (int i = 0; i < N; i++)
	{
		delete[] mtx[i];
	}
	delete[] mtx;
}
int main()
{
    //05
	//const char str[] = "It took      about      an hour to                  answer all the questions.";
	//char* res = GetWord(str);
	//std::cout << res;
	//delete[] res;

	//06
	//std::cout << AnalyzeNum(314) << std::endl;       // Output: 3
	//std::cout << AnalyzeNum(442) << std::endl;       // Output: -1
	//std::cout << AnalyzeNum(5462141) << std::endl;   // Output: 4

	//08
	/*long arr[8] = { 4,5,6,7,8,9,0,1 };*/
	/*ConvertArray(arr, 2, 5);
	printArr(arr, 8);*/

	//09
	//long arr[6] = { 2,3,17,8,19,9 };
	//std::cout << findElement(arr, 6);

	//10
	/*int arr1[5] = { 3,5,11,2,9 };
	int arr2[5] = { 1,4,32,71,5 };
	int** res = mergearrays(arr1, arr2, 5);
	print(res, 5);*/

	//01
	/*int arr1[4] = { 1,3,10,16 };
	int arr2[7] = { 2,8,9,20,32,48,53 };
	int* res = mergeAndSortArray(arr1, 4, arr2, 7);
	printArray(res, 11);
	delete[] res;*/

	//03
	///*char** draw=drawRectangle(5, 8, '*');
	//printMatrix(draw);
	//free(draw);*/

	//04
	/*int** mtx = new int* [4];
	mtx[0] = new int[4] {0, 1, 2, 3};
	mtx[1] = new int[4] {4, 5, 6, 7};
	mtx[2] = new int[4] {8, 9, 10, 11};
	mtx[3] = new int[4] {12, 13, 14, 15};
	std::cout << getSumAboveMainDiagonal(mtx, 4);*/

	//05
	int** mtx = new int* [3];
	mtx[0] = new int[3] {0, 1, 2};
	mtx[1] = new int[3] {3, 4, 5};
	mtx[2] = new int[3] {6, 7, 8};
	transposeMatrix(mtx, 3);
	printMtx(mtx, 3);
	free(mtx, 3);
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
