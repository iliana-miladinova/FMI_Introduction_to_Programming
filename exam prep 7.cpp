// exam prep 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//exam-2021/2022
//task 07
unsigned countWords(const char* str)
{
    int count = 0;
	int wordLen = 0;
	for (int i = 0; str[i]!='\0'; i++)
	{
		char ch = str[i];
		if (ch==' '||ch=='\t')
		{
			if (wordLen>0)
			{
				count++;
				wordLen = 0;
			}
		}

		else
		{
			wordLen++;
		}
	}
	if (wordLen>0)
	{
		count++;
	}

	return count;
}

unsigned countSymbolsInWord(const char* str, int wordInd)
{
	int count = 0;
	int wordLen = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		char ch = str[i];
		if (ch == ' ' || ch == '\t')
		{
			if (wordLen > 0)
			{
				count++;
				if (count==wordInd)
				{
					return wordLen;
				}
				else
				{
					wordLen = 0;
				}
			}
		}

		else
		{
			wordLen++;
		}
	}
	if (wordLen > 0)
	{
		count++;
		if (count==wordInd)
		{
			return wordLen;
		}
	}

	return 0;
}

char** createWordMatrix(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	unsigned wordsCount = countWords(str);
	char** words = new char* [wordsCount];
	int wordInd = 0;
	for (int i = 0; i < wordsCount; i++)
	{
		int wordLen = countSymbolsInWord(str, i + 1);
		words[i] = new char[wordLen+1]; // +1 за \0
	}
	int lenInd = 0;
	for (int i = 0; str[i]!='\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			words[wordInd][lenInd] = str[i];
			lenInd++;
		}
		else if(lenInd>0)
		{
			words[wordInd][lenInd] = '\0';// Добавяме \0 в края на думата
			lenInd = 0;
			wordInd++;
		}
	}
	if (lenInd>0)
	{
		words[wordInd][lenInd] = '\0';// Завършваме последната дума
	}
	return words;
}

void printMatrix(char** words, int wordsCount)
{
	for (int i = 0; i < wordsCount; i++)
	{
		std::cout << words[i] << std::endl;
	}
}

bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

char makeUpper(char ch)
{
	if (isLower(ch))
	{
		return ch - ('a' - 'A');
	}
	return ch;
}

char makeLower(char ch)
{
	if (isUpper)
	{
		return ch + ('a' - 'A');
	}
	return ch;
}

void freeMatrix(char** matrix, unsigned wordsCount)
{
	for (int i = 0; i < wordsCount; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void myStrcpy(const char* source, char* dest)
{
	if (!source||!dest)
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
char* getWord(const char* str, int k)
{
	if (!str)
	{
		return nullptr;
	}

	unsigned wordsCount = countWords(str);

	if (wordsCount<k||k<=0 || wordsCount==0)
	{
		const char* answer = "Wrong number";
		char* wrongNum = new char[strlen(answer) + 1];
		myStrcpy(answer, wrongNum);
		return wrongNum;
	}

	char** words = createWordMatrix(str);
	unsigned resLen = countSymbolsInWord(str, k);
	char* result = new char[resLen + 1];
	for (int i = 0; i < resLen; i++)
	{
		if (isLower(words[k-1][i]))
		{
			result[i] = makeUpper(words[k - 1][i]);
		}
		else if (isUpper(words[k-1][i]))
		{
			result[i]=makeLower(words[k-1][i]);
		}
		else
		{
			result[i] = words[k - 1][i];
		}
	}
	result[resLen] = '\0';

	freeMatrix(words, wordsCount);
	return result;
}

//2 nachin
char* getWord1(const char* str, int k)
{
	if (!str || k<=0)
	{
		return nullptr;
	}

	int start = -1;
	int end = -1;
	int wordCount = 0;
	for (int i = 0; str[i]!='\0'; i++)
	{
		char ch = str[i];
		if (ch==' '||ch=='\t')
		{
			if (start!=-1)
			{
				wordCount++;
				if (wordCount==k)
				{
					end = i;
					break;
				}
				start = -1;
			}
		}
		else
		{
			if (start==-1)
			{
				start = i;
			}
		}
	}

	if (start!=-1)
	{
		wordCount++;
		if (wordCount==k)
		{
			end = strlen(str);
		}
	}

	if (wordCount<k||start==-1)
	{
		const char* answer = "Wrong number";
		char* wrongNum = new char[strlen(answer) + 1];
		myStrcpy(answer, wrongNum);
		return wrongNum;
	}
	int len = end - start;
	char* res = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		if (isLower(str[start+i]))
		{
			res[i] = makeUpper(str[start + i]);
		}
		else if(isUpper(str[start+i]))
		{
			res[i] = makeLower(str[start + i]);
		}
		else
		{
			res[i] = str[start + i];
		}
	}
	res[len] = '\0';
	return res;
}

//task 08
int maxWord(const char* str)
{
	if (!str)
	{
		return -1;
	}

	int maxWordLen = 0;
	int currWordLen = 0;
	int currCountLower = 0;
	int maxWordLower = 0;
	for (int i = 0; str[i]!='\0'; i++)
	{
		char ch = str[i];
		if (ch==' '||ch=='\t')
		{
			if (currWordLen>0)
			{
				if (currWordLen>maxWordLen)
				{
					maxWordLen = currWordLen;
					maxWordLower = currCountLower;
				}
				currWordLen = 0;
				currCountLower = 0;
			}
		}
		else
		{
			currWordLen++;
			if (isLower(ch))
			{
				currCountLower++;
			}
		}
	}
	if (currWordLen>0)
	{
		if (currWordLen>maxWordLen)
		{
			maxWordLen = currWordLen;
			maxWordLower = currCountLower;
		}
	}

	return maxWordLen * maxWordLower;
}

//09
void changeSymbolsInWord(char* res, int startInd, int endInd)
{
	for (int i = startInd; i < endInd; i++)
	{
		res[i] = '*';
	}
	
}

int skipWord(const char* str, int startInd)
{
	int ind = startInd;
	while (str[ind]!=' '&&str[ind]!='\t'&&str[ind]!='\0')
	{
		ind++;
	}
	return ind;
}

char* changeWord(const char* str, char k)
{
	if (!str)
	{
		return nullptr;
	}

	int len = strlen(str);
	char* res = new char[len + 1];
	bool isStartWord = true;

	for (int i = 0; i <=len ; i++)
	{
		char ch = str[i];
		if (ch==' '||ch=='\t'||ch=='\0')
		{
			res[i] = ch;
			isStartWord = true;
		}
		else if (isStartWord)
		{
			isStartWord = false;
			if (ch == k)
			{
				int endInd = skipWord(str, i);
				changeSymbolsInWord(res,i,endInd);
				i = endInd - 1;
			}
			else
			{
				res[i] = ch;
			}
		}
		else
		{
			res[i] = ch;
		}
	}
	/*res[len] = '\0';*/
	return res;
}


//photo-31.08
//task 01
int findMaxInArray(const int* arr, int M)
{
	int max = arr[0];
	for (int i = 0; i < M; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}

void swap(int& n1, int& n2)
{
	int temp = n1;
	n1 = n2;
	n2 = temp;
}
void convertMax(int* arr, int M)
{
	if (!arr)
	{
		return;
	}

	int max = findMaxInArray(arr, M);
	int swapsNeeded = M / 2;
	for (int i = 0; i < swapsNeeded; i++)
	{
		swap(arr[i], arr[M - 1 - i]);
	}

	for (int i = 0; i < M; i++)
	{
		if (arr[i]!=max)
		{
			arr[i] += max;
		}
	}
}

void printArr(const int* arr, int M)
{
	for (int i = 0; i < M; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

//task 02
int* cntWords(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	int* res = new int[2] {0};

	int countLen = 0;
	int countUpperChars = 0;
	int countLowerChars = 0;
	for (int i = 0; str[i]!='\0'; i++)
	{
		char ch = str[i];
		if (ch == ' ' || ch == '\t')
		{
			if (countLen > 0)
			{
				if (countLowerChars == countLen)
				{
					res[0]++;
				}
				else if (countUpperChars == countLen)
				{
					res[1]++;
				}
				countLen = 0;
				countLowerChars = 0;
				countUpperChars = 0;
			}
		}
		else
		{
			countLen++;
			if (isUpper(ch))
			{
				countUpperChars++;
			}
			else if (isLower(ch))
			{
				countLowerChars++;
			}
		}
		
	}

	if (countLen>0)
	{
		if (countLowerChars==countLen)
		{
			res[0]++;
		}
		else if (countUpperChars==countLen)
		{
			res[1]++;
		}
	}

	return res;
}

//task 03
//long convertNumber(const char* num)
//{
//	if (!num)
//	{
//		return -1;
//	}
//
//	char max = '\0';
//	const char* start = num;
//	while (*num)
//	{
//		if (*num>max)
//		{
//			max = *num;
//		}
//		num++;
//	}
//	
//	num=start;
//	char secondMax = '\0';
//	while (*num)
//	{
//		if (*num>secondMax&&max>*num)
//		{
//			secondMax = *num;
//		}
//		num++;
//	}
//	
//	num = start;
//	char thirdMax = '\0';
//	while (*num)
//	{
//		if (*num>thirdMax&&secondMax>*num)
//		{
//			thirdMax = *num;
//		}
//		num++;
//	}
//	int maxNum = max;
//	int secondNum = secondMax;
//	int thirdNum = thirdMax;
//	return max + secondMax + thirdMax;
//}

//2 nachin
long convertNumber1(const char* num)
{
	if (!num)
	{
		return -1;
	}

	char max1 = num[0], max2 = num[0], max3 = num[0];
	while (*num)
	{
		if (*num>max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = *num;
		}
		else if (*num>max2)
		{
			max3 = max2;
			max2 = *num;
		}
		else if (*num>max3)
		{
			max3 = *num;
		}
		num++;
	}
	return max1 + max2 + max3;
}

//2020
//task 01
int largestSeq(const int* arr, int N)
{
	if (!arr)
	{
		return -1;
	}

	int currSeqLen = 0;
	int maxSeqLen = 0;
	int currSum = 0;
	int maxSum = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i]%2==0)
		{
			currSeqLen++;
			currSum += arr[i];
		}
		else
		{
			if (currSeqLen>maxSeqLen)
			{
				maxSeqLen = currSeqLen;
				maxSum = currSum;
			}
			currSeqLen = 0;
			currSum = 0;
		}
	}
	return maxSum;
}
int main()
{
    //task 07
	/*std::cout << countSymbolsInWord("this is a teSt string", 5) << std::endl;;
	char** word = createWordMatrix("this is a teSt string");
	printMatrix(word, 5);*/
	//char* res = getWord("s", 5);
	//std::cout << res;
	//delete[] res;
	/*char* res = getWord1("this is a teSt string", 4);
	std::cout << res;
	delete[] res;*/
	
	//task 08
	/*std::cout << maxWord("This is aNothEr string");*/

	//task 09
	/*char* res = changeWord("This is a test Tstring", 't');
	std::cout << res;
	delete[] res;*/

	//task 01
	/*int arr[7] = { 11,5,2,27,4,8,2 };
	convertMax(arr, 7);
	printArr(arr, 7);*/

	//task 02
	/*const char arr[] = "THIS IS an exAMple STRING F&OR this exercise";
	int* res = cntWords(arr);
	printArr(res, 2);
	delete[] res;*/

	//task 03
	/*const char* num = "ABBAcdakwiw";
	std::cout << convertNumber(num);*/

	//01
	int arr[12] = { 2, 4, 3, 11, 12, 168, 144, 5, 9, 62, 98, 1 };
	std::cout << largestSeq(arr, 12);
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
