// pract 11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#pragma warning( disable : 4996)
void inputArr(int* arr, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		std::cin >> arr[i];
	}
}

void printArr(const int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}


//task 01
void printArrBackwards(const int* arr, size_t len)
{
	for (int i = len-1; i >= 0; i--)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout<<std::endl;
}

//task 02
bool isDevisable(int num1, int num2)
{
	if (num1%num2==0)
	{
		return true;
	}
	return false;
}
int countDevisableNums(const int* arr, int num)
{
	if (!arr)
	{
		return -1;
	}
	int count=0;
	while (*arr)
	{
		if (isDevisable(*arr,num))
		{
			count++;
		}
		arr++;
	}
	return count;
}

int* getDivasableNumsArr(const int* arr1, int len1, const int* arr2,int len2, int num)
{
	if (!arr1||!arr2)
	{
		return nullptr;
	}
	int divNumsArr1Count = countDevisableNums(arr1, num);
	int divNumsArr2Count = countDevisableNums(arr2, num);
	int resLen = divNumsArr1Count + divNumsArr2Count;
	int* res = new int[resLen];

	int resInd = 0;
	/*while (*arr1)
	{
		if (isDevisable(*arr1, num))
		{
			res[resInd] = *arr1;
			resInd++;
		}
		arr1++;
	}*/
	for (size_t i = 0; i < len1; i++)
	{
		if (isDevisable(arr1[i], num))
		{
			res[resInd] = arr1[i];
			resInd++;
		}
	}

	for (size_t i = 0; i < len2; i++)
	{
		if (isDevisable(arr2[i],num))
		{
			res[resInd] = arr2[i];
			resInd++;
		}
	}

	/*while (*arr2)
	{
		if (isDevisable(*arr2,num))
		{
			res[resInd] = *arr2;
			resInd++;
		}
		arr2++;
	}*/
	/*res -= resLen;*/
	return res;
}

//task 03
void moveRight(int* arr, size_t size, int k)
{
	if (!arr||size==0)
	{
		return;
	}

	k = k % size;
	if (k == 0)
	{
		return;
	}
	int* temp = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		temp[(i + k) % size] = arr[i];
	}
	
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = temp[i];
	}

	delete[] temp;
}

//task 04
bool isDevisable1(int num1, int num2)
{
	if (num2==0)
	{
		return false;
	}
	if (num1%num2==0)
	{
		return true;
	}
	return false;
}
int countDevisableByNeighbours(const int* arr, size_t size)
{
	if (!arr||size==0)
	{
		return -1;
	}

	unsigned count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if ((i>0 && isDevisable1(arr[i],arr[i-1]))||(i<size-1 && isDevisable1(arr[i],arr[i+1])))
		{
			count++;
		}
	}
	return count;
}

int* getArrOfDevisable(const int* arr, size_t size)
{
	if (!arr||size==0)
	{
		return nullptr;
	}

	int lenRes = countDevisableByNeighbours(arr, size);
	if (lenRes==0)
	{
		return nullptr;
	}
	int* res = new int[lenRes];

	unsigned resInd = 0;
	for (size_t i = 0; i < size; i++)
	{
		if ((i>0 && isDevisable(arr[i],arr[i-1]))||(i<size-1 && isDevisable(arr[i],arr[i+1])))
		{
			res[resInd] = arr[i];
			resInd++;
		}
	}
	return res;
}

//task 05
bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
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

unsigned countLower(const char* str)
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

unsigned countUpper(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned count = 0;
	while (*str)
	{
		if (isUpper(*str))
		{
			count++;
		}
		str++;
	}
	return count;
}

char* concatStr(const char* str1, const char* str2)
{
	if (!str1 || !str2)
	{
		return nullptr;
	}

	unsigned lowerCount = countLower(str1);
	unsigned upperCount = countUpper(str2);
	unsigned len = lowerCount + upperCount;
	char* res = new char[len + 1];

	res[len] = '\0';
	
	unsigned resInd = 0;
	while (*str1)
	{
		if (isLower(*str1))
		{
			res[resInd] = *str1;
			resInd++;
		}
		str1++;
	}

	while (*str2)
	{
		if (isUpper(*str2))
		{
			res[resInd] = *str2;
			resInd++;
		}
		str2++;
	}

	return res;
}

//task 06
unsigned countRepetitions(const char* str, char ch)
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

bool isRepeting(const char* str, char ch)
{
	if (!str)
	{
		return false;
	}

	if (countRepetitions(str, ch)>1)
	{
		return true;
	}
	return false;
}

unsigned countAllRepetitions(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned countAll = 0;
	while (*str)
	{
		unsigned tempCount = 0;
		tempCount = countRepetitions(str, *str);
		if (tempCount > 1)
		{
			countAll += tempCount;
		}
		str++;
	}
	return countAll;
}

bool isUniqueInRes(const char* res, char ch) 
{
	while (*res) 
	{
		if (*res == ch) 
		{
			return false;
		}
		res++;
	}
	return true;
}

char* removeRepetitions(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	/*unsigned repCount = countAllRepetitions(str);
	unsigned resLen = myStrlen(str) - repCount;*/

	char* res = new char[myStrlen(str) + 1];
	res[myStrlen(str)] = '\0';
	int resInd = 0;
	while (*str)
	{
		if (/*isUniqueInRes(res,*str)&&*/countRepetitions(str,*str)==1)
		{
			res[resInd] = *str;
			resInd++;
		}
		str++;
	}
	return res;
}

//task 07
void addSymbols(char* str, int* pos, int size, char sym)
{
	if (!str||!pos)
	{
		return;
	}

	int tempLen = myStrlen(str) + size;
	char* temp = new char[tempLen + 1];
	temp[tempLen] = '\0';

	int tempInd = 0;
	int posInd = 0;
	int strInd = 0;
	/*while (*str)
	{
		if (strInd==pos[posInd])
		{
			temp[tempInd] = sym;
			tempInd++;
			posInd++;
		}
		else
		{
			temp[tempInd] = *str;
			tempInd++;
			strInd++;
		}
		str++;
	}*/

	while (tempInd<tempLen)
	{
		if (posInd<size&&strInd==pos[posInd])
		{
			temp[tempInd] = sym;
			tempInd++;
			posInd++;
		}
		else
		{
			temp[tempInd] = str[strInd];
			tempInd++;
			strInd++;
		}
	}
	strcpy(str, temp);
	delete[] temp;
}

//task 08
unsigned countLettersInFirstWord(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned count = 0;
	while (*str)
	{
		if (*str==' ')
		{
			break;
		}
		count++;
		str++;
	}
	return count;
}

unsigned lastWordLetterCount(const char* str)
{
	if (!str)
	{
		return 0;
	}

	int size = myStrlen(str);
	str += size - 1;
	unsigned count = 0;
	while (*str)
	{
		if (*str==' ')
		{
			break;
		}
		count++;
		str--;
	}
	return count;
}

char* concatFirstAndLastWord(const char* str)
{
	if (!str)
	{
		return nullptr;
	}
	unsigned lenStr = myStrlen(str);
	unsigned firstWordLetters = countLettersInFirstWord(str);
	unsigned lastWordLetters = lastWordLetterCount(str);
	unsigned resLen = firstWordLetters + lastWordLetters+1;
	char* res = new char[resLen + 1];
	res[resLen] = '\0';
	unsigned resInd = 0;
	for (size_t i = 0; i < firstWordLetters; i++)
	{
		res[resInd] = str[i];
		resInd++;
	}
	res[resInd] = ' ';
	resInd++;
	for (size_t i = lenStr-lastWordLetters; i < lenStr; i++)
	{
		res[resInd] = str[i];
		resInd++;
	}
	return res;
}
int main()
{
	//01
	/*int n;
	std::cin >> n;
	int* arr = new int[n];
	inputArr(arr, n);
	printArrBackwards(arr, n);
	delete[] arr;*/
	//02
	/*int arr1[4] = { 2,4,5,8 };
	int arr2[5] = { 3,16,7,9,10 };
	int size = countDevisableNums(arr1, 2) + countDevisableNums(arr2, 2);
	int* res = getDivasableNumsArr(arr1,4, arr2,5, 2);
	printArr(res, size);*/

	/*int ptr1[] = { 2, 4, 5, 8 };
	int* ptrOne = ptr1;

	int ptr2[] = { 3, 16, 7 ,9, 10 };
	int* ptrTwo = ptr2;

	int* ptr = getDivasableNumsArr(ptrOne, 4, ptrTwo, 5, 2);

	for (size_t i = 0; i < 5; i++)
	{
		std::cout << ptr[i] << " ";
	}*/

	//task 03
	/*int arr[] = { 1,2,3,4,5 };
	moveRight(arr, 5, 2);
	printArr(arr, 5);*/

	//04
	/*int arr[] = { 5,10,20,4,2,7 };
	int* res = getArrOfDevisable(arr, 6);
	printArr(res, 4);*/

	//05
	/*char arr1[] = "abcAGHp";
	char arr2[] = "mnAHGT5saP";
	char* res = concatStr(arr1, arr2);
	std::cout << res << std::endl;*/

	//06
	//char str1[] = "aklahk3g*5ggkkks";
	//char* res = removeRepetitions(str1);
	//std::cout << res << std::endl;

	//07
	//char inputStr[] = "Hi here nice o mee you.";


	//int positions[] = { 3, 13, 18 };
	//char symbol = 't';

	//addSymbols(inputStr, positions, 3, symbol);

	//std::cout << "Modified string: " << inputStr << std::endl;

	//// Освобождаваме паметта на крайния низ
	//delete[] inputStr;

	//08
	char str[] = "Hello hi hey";
	char* newStr = concatFirstAndLastWord(str);
	std::cout << newStr << std::endl;
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
