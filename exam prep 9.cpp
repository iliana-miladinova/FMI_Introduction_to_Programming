// exam prep 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//2022-2023 exam 

//task 02
int findIndOfSmallestPositive(const int* arr, size_t len)
{/*
	if (!arr)
	{
		return -1;
	}
	int min = arr[0];
	int minInd = 0;
	for (int i = 1; i < len; i++)
	{
		if (min<0||arr[i]<min)
		{
			min = arr[i];
			minInd = i;
		}
	}
	return minInd;*/
	int index = len; // По подразбиране, ако няма положителни числа
	for (size_t i = 0; i < len; i++) 
	{
		if (arr[i] >= 0) {
			index = i;
			break;
		}
	}
	return index;
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
		if (minElInd!=i)
		{
			std::swap(arr[minElInd], arr[i]);
		}
	}

}

void merge(const int* arr1, size_t len1, const int* arr2, size_t len2, int* res)
{
	unsigned arr1Ind = 0, arr2Ind = 0, resInd = 0;
	while (arr1Ind<len1&&arr2Ind<len2)
	{
		if (arr1[arr1Ind]<=arr2[arr2Ind])
		{
			res[resInd++] = arr1[arr1Ind++];
		}
		else
		{
			res[resInd++] = arr2[arr2Ind++];
		}
	}

	while (arr1Ind<len1)
	{
		res[resInd++] = arr1[arr1Ind++];
	}
	while (arr2Ind<len2)
	{
		res[resInd++] = arr2[arr2Ind++];
	}
}

int getBound(const int* arr, size_t len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i]>arr[i+1])
		{
			return i + 1;
		}
	}
	return -1;
}
void squareArr(int* arr, size_t len)
{
	if (!arr)
	{
		return;
	}

	int smallestPositiveIndex = findIndOfSmallestPositive(arr, len);
	for (int i = 0; i < len; i++)
	{
		arr[i] *= arr[i];
	}
	/*selectionSort(arr, len);*/
	
	/*for (int i = 0; i < smallestPositiveIndex-1; i++)
	{
		if (arr[i]<arr[i+1])
		{
			std::swap(arr[i], arr[i + 1]);
		}
	}*/

	int secondArrInd = getBound(arr, len);
	if (secondArrInd==-1)
	{
		return;
	}

	int* temp = new int[len];
	merge(arr, secondArrInd, arr + secondArrInd, len - secondArrInd, temp);
	for (int i = 0; i < len; i++)
	{
		arr[i] = temp[i];
	}
	delete[] temp;
}

//task 03
void swap(unsigned int& num1, unsigned int& num2)
{
	unsigned int temp = num1;
	num1 = num2;
	num2 = temp;
}
unsigned int gcdOfTwoNum(unsigned int n1, unsigned int n2)
{
	if (n2>n1)
	{
		swap(n1, n2);
	}

	while (n2!=0)
	{
		unsigned int mod = n1 % n2;
		n1 = n2;
		n2 = mod;
	}
	return n1;
}

unsigned int getGCD(const unsigned int* arr, size_t len)
{
	if (!arr||len==0)
	{
		return 0;
	}
	if (len==1)
	{
		return arr[0];
	}

	unsigned int gcd = gcdOfTwoNum(arr[0], arr[1]);
	for (int i = 2; i < len; i++)
	{
		gcd = gcdOfTwoNum(gcd, arr[i]);
	}
	return gcd;
}

//task 05
int countDigits(long N)
{
	if (N==0)
	{
		return 1;
	}
	int count = 0;
	while (N!=0)
	{
		count++;
		N /= 10;
	}
	return count;
}
int power(int num, int k)
{
	int res = 1;
	for (int i = 0; i < k; i++)
	{
		res *= num;
	}
	return res;
}
int getNthDigit(long N, int pos)
{
	int digitsCount = countDigits(N);
	/*int div = 1;
	for (int i = 0; i < digitsCount-pos; i++)
	{
		div *= 10;
	}*/
	int div = power(10, digitsCount - pos);
	int shiftedNum = (N / div) % 10;
	return shiftedNum;
}

long setDigit(long N, int pos, int digit)
{
	int digitsCount = countDigits(N);
	int currDigAtPos = getNthDigit(N, pos);
	N -= (currDigAtPos * power(10, digitsCount-pos));
	N += (digit * power(10, digitsCount-pos));
	return N;
}

void swapDigits(long& N, unsigned int m, unsigned int l)
{
	int currM = getNthDigit(N, m);
	int currL = getNthDigit(N, l);
	N = setDigit(N, m, currL);
	N = setDigit(N, l, currM);
}

bool isDevisableBy4(long N)
{
	int digitsCount = countDigits(N);
	int lastDigit = getNthDigit(N, digitsCount);
	int secondToLast = getNthDigit(N, digitsCount - 1);
	int lastTwoDigits = secondToLast * 10 + lastDigit;
	int res = lastTwoDigits / 4;
	return (res == 0 || res * 4 == lastTwoDigits);
}

int checkNum(long N, unsigned int m, unsigned int l)
{
	int digitsCount = countDigits(N);
	if (m>digitsCount||l>digitsCount)
	{
		return -1;
	}
	swapDigits(N, m, l);
	return isDevisableBy4(N) ? 1 : 0;

}
//task 06
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

bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

void toLower(char& ch)
{
	ch = ch + ('a' - 'A');
}

bool isNumAlpha(char ch)
{
	return (ch >= 'A' && ch <= 'Z')
		|| (ch >= 'a' && ch <= 'z') ||
		(ch >= '0' && ch <= '9');
}
bool doExist(const char* symbols, const char* word) //ako trybva da sravnyavame samo otdelnite dumi otizrechenie
{
	if (!symbols || !word)
	{
		return false;
	}

	size_t symbolsLen = myStrlen(symbols);
	size_t wordLen = myStrlen(word);
	size_t wordInd = 0;
	size_t symbolsWordLen = 0;
	for (int i = symbolsLen - 1; i >= 0; i--)
	{
		char ch = symbols[i];
		if (!isNumAlpha(ch))
		{
			if (wordInd > 0)
			{
				if (wordInd == symbolsWordLen)
				{
					return true;
				}
				wordInd = 0;
			}
			symbolsWordLen = 0;


		}
		else
		{
			if (isUpper(ch))
			{
				toLower(ch);
			}
			if (ch == word[wordInd])
			{
				wordInd++;
			}
			else
			{
				wordInd = 0;
			}
			symbolsWordLen++;
		}
	}

	return false;
}

bool doExist1(char* symbols, char* word)//ako sravnyavame i podduma na duma v izrechenie s word
{
	if (!symbols || !word)
	{
		return false;
	}

	size_t wordLen = strlen(word);
	size_t symbolLen = strlen(symbols);

	size_t wordInd = 0;
	for (int i = symbolLen - 1; i >= 0; i--)
	{
		if (isNumAlpha(symbols[i]))
		{
			char ch = symbols[i];
			if (ch >= 'A' && ch <= 'Z')
			{
				toLower(ch);
			}
			if (ch == word[wordInd])
			{
				wordInd++;
				if (wordInd == wordLen)
				{
					return true;
				}
			}
			else
			{
				wordInd = 0;
			}
		}
		else
		{
			wordInd = 0;
		}
	}
	return false;
}

//task 09
unsigned countDigitsInNum(unsigned short int num)
{
	if (num == 0)
	{
		return 1;
	}
	unsigned count = 0;
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return count;
}

unsigned short int clearBit(unsigned short int num, int ind)
{
	unsigned int short mask = 1;
	mask <<= ind;
	mask = ~mask;
	return num & mask;
}
unsigned short int reverseBitwise(unsigned short int num)
{
	unsigned short int res = 0;
	for (int i = 0; i < 16; i++)
	{
		unsigned short int mask = 1 << i;
		unsigned short int currRes = num & mask;//poluchavame kakav e bita na poziciya i
		currRes >>= i; //poluchavame 0 ili 1 spored tova kakav e bita na poziciya i
		currRes <<= (15 - i); //bluskame 0 ili 1 na naj-lyavata svobodna poziciya
		res |= currRes;//poluchavame resultata
	}

	return res;
}

//2 nachin
unsigned short int reverseBitwise1(unsigned short int n) 
{
	unsigned short int result = 0;

	for (int i = 0; i < 16; i++) 
	{
		// Вземаме i-тия бит на n и го местим на противоположната позиция
		if (n & (1 << i)) {
			result |= 1 << (15 - i);
		}
	}

	return result;
}


void printArr(const int* arr, size_t len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

//tasks from internet 
// task 01
////Напишете функция int smallestNumber(int N), която приема цяло число N и връща 
// най-малкото възможно число, което може да се образува чрез пренареждане на цифрите на N.
//
//Пример:
//
//Вход: 41352
//Изход : 12345
int findIndexOfFirstDigitDifferentThanZero(const int* arr, size_t len)
{
	if (!arr)
	{
		return -1;
	}
	for (int i = 0; i < len; i++)
	{
		if (arr[i]!=0)
		{
			return i;
		}
	}
	return -1;
}
int smallestNumber(int N)
{
	if (N<=9)
	{
		return N;
	}

	int len = countDigits(N);
	int* arrDigits = new int[len];
	int arrInd = 0;
	while (N!=0)
	{
		arrDigits[arrInd++] = N % 10;
		N /= 10;
	}

	selectionSort(arrDigits, len);
	int res = 0;
	int firstIndexDiffThanZero = findIndexOfFirstDigitDifferentThanZero(arrDigits, len);
	if (firstIndexDiffThanZero != 0)
	{
		std::swap(arrDigits[0], arrDigits[firstIndexDiffThanZero]);
	}
	for (int i = 0; i < len; i++)
	{
		res = res * 10 + arrDigits[i];
	}
	delete[] arrDigits;
	return res;
}

//task 02
//Напишете функция int reduceToZero(int N), която приема цяло число N и 
// връща броя на стъпките, необходими за намаляване на N до 0, 
// като в една стъпка можете или да извадите 1, или да разделите на 2, ако числото е четно.
//
//Пример:
//
//Вход: 14
//Изход : 6 (14 → 7 → 6 → 3 → 2 → 1 → 0)

int reduceToZero(int N)
{
	if (N==0)
	{
		return 0;
	}

	int count = 0;
	while (N!=0)
	{
		if (N%2==0)
		{
			count++;
			N /= 2;
		}
		else
		{
			count++;
			N -= 1;
		}
	}
	return count;
}

//task 03
//Задача: Напишете функция bool hasPairWithSum(const int* arr, size_t len, int target), 
//която проверява дали в масив arr с len цели числа съществува двойка от елементи, 
//чиято сума е равна на target.
//unsigned countDifferentNumsInArray(int* arr, size_t len, int target)
//{
//	selectionSort(arr, len);
//	int count = 0;
//	int duplicateCount=0;
//	for (int i = 0; i < len-1; i++)
//	{
//		if (i==0||arr[i]!=arr[i-1])
//		{
//			count++;
//		}
//		else
//		{
//			duplicateCount++;
//		}
//	}
//
//}

bool isInArray(const int* arr, size_t len, int complement)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i]==complement)
		{
			return true;
		}
	}
	return false;
}
bool hasPairsWithSum(const int* arr, size_t len, int target)
{
	if (!arr||len<2)
	{
		return false;
	}

	int* sorted = new int[len];
	for (int i = 0; i < len; i++)
	{
		sorted[i] = arr[i];
	}
	selectionSort(sorted, len);

	int left = 0;
	int right = len - 1;
	while (left<right)
	{
		int sum = arr[left] + arr[right];
		if (sum==target)
		{
			delete[] sorted;
			return true;
		}
		else if (sum<target)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	return false;
}
int main()
{
    //02
	/*int arr[6] = { -8,-3,0,1,6,8 };
	squareArr(arr, 6);
	printArr(arr, 6);*/
	//03
	//unsigned int arr[3];
	//for (int i = 0; i < 3; i++)
	//{
	//	std::cin >> arr[i];
	//}
	//std::cout << getGCD(arr, 3);

	//05
	/*std::cout << checkNum(123456,3,5);*/
	//06
	/*const char str[] = "I left you there";
	const char word[] = " uo";
	std::cout << doExist(str, word);*/

	//09
	/*std::cout << reverseBitwise(12);*/

	//tasks from internet 
	// task 01
	/*std::cout << smallestNumber(41352);*/

	//task 02
	/*std::cout << reduceToZero(14);*/

	//task 02
	int arr[5] = { 1,4,5,6,8 };
	std::cout << hasPairsWithSum(arr, 5, 10);
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
