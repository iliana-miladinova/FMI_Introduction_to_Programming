// exam prep 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//exam 2019
//task 04

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool isHour(int num)
{
	return num >= 0 && num < 24;
}

bool isMin(int num)
{
	return num >= 0 && num < 60;
}

bool isSec(int num)
{
	return num >= 0 && num < 60;
}

int getNumFromChar(char ch)
{
	return ch - '0';
}
int checkTimeStr(const char* str)
{
	if (!str)
	{
		return -1;
	}

	int timeLen = strlen(str);
	if (timeLen!=8)
	{
		return -1;
	}

	if (str[2]!=':'||str[5]!=':')
	{
		return -1;
	}

	for (int i = 0; i < timeLen; i++)
	{
		if (i==2||i==5)
		{
			continue;
		}
		else if (!isDigit(str[i]))
		{
			return false;
		}
	}

	int hours = getNumFromChar(str[0]) * 10 + getNumFromChar(str[1]);
	int mins = getNumFromChar(str[3]) * 10 + getNumFromChar(str[4]);
	int sec = getNumFromChar(str[6]) * 10 + getNumFromChar(str[7]);
	if (!isHour(hours)||!isMin(mins)||!isSec(sec))
	{
		return -1;
	}

	return 0;
}

//task 05
constexpr size_t MAX_CHARS_IN_ASCII = 256;

//unsigned countSymbolRepetition(const char* str, char ch)
//{
//	if (!str)
//	{
//		return 0;
//	}
//	unsigned count = 0;
//	while (*str)
//	{
//		if (*str==ch)
//		{
//			count++;
//		}
//		str++;
//	}
//	return count;
//}
//bool isSymbolMoreThanOnce(const char* str, char ch)
//{
//	if (!str)
//	{
//		return false;
//	}
//
//	if (countSymbolRepetition(str,ch)>1)
//	{
//		return true;
//	}
//	return false;
//}

char* checkStr(const char* str)
{
	if (!str)
	{
		return 0;
	}

	int freq[MAX_CHARS_IN_ASCII] = { 0 };

	for (int i = 0; str[i]!=0; i++)
	{
		freq[str[i]]++;
	}

	int repetingSymbolsCount = 0;
	for (int i = 0; i < 256; i++)
	{
		if (freq[i]>1)
		{
			repetingSymbolsCount++;
		}
	}

	char* res = new char[repetingSymbolsCount+1];
	int resInd = 0;

	bool alreadyCounted[MAX_CHARS_IN_ASCII] = { false };
	while (*str)
	{
		if (freq[*str]>1 && !alreadyCounted[*str])
		{
			res[resInd] = *str;
			resInd++;
			alreadyCounted[*str] = true;
		}
		str++;
	}

	res[resInd] = '\0';
	return res;
}

//task 06
unsigned getNumLen(long num)
{
	unsigned len = 0;
	while (num!=0)
	{
		len++;
		num /= 10;
	}
	return len;
}

void removeLastDig(long& num)
{
	num /= 10;
}

long myAbs(long num)
{
	if (num>=0)
	{
		return num;
	}
	return -num;
}
int numCalc(long num, int k, int l)
{
	num = myAbs(num);
	unsigned numLen = getNumLen(num);
	if (numLen<k||numLen<l || l<=0 ||k<=0)
	{
		return -1;
	}
	unsigned ind = numLen;

	int digK = 0;
	int digL = 0;
	while (num!=0&&ind>0)
	{
		/*if (ind!=k && ind!=l)
		{
			removeLastDig(num);
		}*/
		/*else */if (ind==k)
		{
			digK = num % 10;
			/*removeLastDig(num);*/
		}
		else if (ind==l)
		{
			digL = num % 10;
			/*removeLastDig(num);*/
		}
		removeLastDig(num);
		ind--;
	}

	return digK + digL;
}

//task 07
int AnalyzeArray(const int* arr, int l)
{
	if (!arr||l<2)
	{
		return -1;
	}

	int sum1 = arr[0];
	int sum2 = 0;
	for (int i = 1; i < l; i++)
	{
		sum2 += arr[i];
	}

	for (int i = 1; i < l-1; i++)
	{
		if (sum1==sum2)
		{
			return 1;
		}
		else
		{
			sum1 += arr[i];
			sum2 -= arr[i];
		}
	}
	return 0;
}

//2 nachin
int AnalyzeArray1(const int* arr, int l)
{
	if (!arr||l<=0)
	{
		return -1;
	}

	int totalSum = 0;
	for (int i = 0; i < l; i++)
	{
		totalSum += arr[i];
	}

	if (totalSum%2!=0)
	{
		return 0;
	}

	int halfSum = totalSum / 2;
	int currSum = 0;

	for (int i = 0; i < l; i++)
	{
		currSum += arr[i];
		if (currSum==halfSum)
		{
			return 1;
		}
	}

	return 0;
}

//task 08
//constexpr size_t MAX_WORDS = 100;
//constexpr size_t MAX_LEN_WORD = 50;
//
//char words[MAX_WORDS][MAX_LEN_WORD];
//int totalWords = 0;
//void toLowerCase(char* str)
//{
//	if (!str)
//	{
//		return;
//	}
//
//	while (*str)
//	{
//		if (*str>='A'&&*str<='Z')
//		{
//			*str = *str + ('a' - 'A');
//		}
//		str++;
//	}
//}
//
//char toLower(char ch)
//{
//	return ch + ('a' - 'A');
//}
//bool areWordsTheSame(const char* word1, const char* word2)
//{
//	if (!word1||!word2)
//	{
//		return false;
//	}
//
//
//	while (*word1&&*word2)
//	{
//		if (toLower(*word1)!=tolower(*word2))
//		{
//			return false;
//		}
//		word1++;
//		word2++;
//	}
//	return *word1 == '\0' && *word2 == '\0';
//}
//
//void addWord(const char* word)
//{
//	if (!word)
//	{
//		return;
//	}
//
//	int ind = 0;
//	int wordLen = strlen(word);
//	int wordInd = wordLen - 1;
//	while (word[ind]!='\0'&&ind<MAX_LEN_WORD-1 && wordInd>0)
//	{
//		words[totalWords][ind] = word[wordInd];
//		ind++;
//		wordInd--;
//	}
//	words[totalWords][ind] = '\0';
//	totalWords++;
//}
//
//void processString(const char* str)
//{
//	if (!str)
//	{
//		return;
//	}
//
//	char word[MAX_LEN_WORD];
//
//
//	size_t len = strlen(str);
//	int ind = 0;
//	for (int i = len-1 ; i >= 0; i--)
//	{
//		char ch = str[i];
//		if (ch==' '||ch=='\t' ||ch=='.'||ch==','||ch=='?'||ch=='!'||ch==';'||ch==':')
//		{
//			if (ind>0)
//			{
//				word[ind] = '\0';
//				addWord(word);
//				ind++;
//			}
//		}
//		else
//		{
//			word[ind] = toLower(ch);
//			ind++;
//		}
//
//	}
//
//}
//
//bool doExist(const char* symbols, const char* word)
//{
//	processString(symbols);
//	for (int i = 0; i < totalWords; i++)
//	{
//		if (areWordsTheSame(words[i],word))
//		{
//			return true;
//		}
//	}
//	return false;
//}

void toLower(char& ch)
{
	ch=ch + ('a' - 'A');
}

bool isAlphaNum(char ch)
{
	return (ch >= '0' && ch <= '9') ||
		(ch >= 'a' && ch <= 'z') ||
		(ch >= 'A' && ch <= 'Z');
}
bool doExist(char* symbols, char* word)
{
	if (!symbols||!word)
	{
		return false;
	}

	size_t wordLen = strlen(word);
	size_t symbolLen = strlen(symbols);

	size_t wordInd = 0;
	for (int i = symbolLen-1; i >= 0; i--)
	{
		if (isAlphaNum(symbols[i]))
		{
			char ch = symbols[i];
			if (ch>='A'&&ch<='Z')
			{
				toLower(ch);
			}
			if (ch==word[wordInd])
			{
				wordInd++;
				if (wordInd==wordLen)
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
int** createMatrix(int rows)
{
	int** mtx = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		/*int cols;
		std::cin >> cols;*/
		mtx[i] = new int[rows];
		for (int j = 0; j < rows; j++)
		{
			std::cin >> mtx[i][j];
		}
		/*mtx[1][0] = cols;*/
	}
	return mtx;
}
double getSumMainDiagonal(int** matr, int m)
{
	if (!matr||m==0)
	{
		return -1;
	}
	for (int i = 0; i < m; i++)
	{
		if (!matr[i])
		{
			return -1;
		}
	}

	double sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += matr[i][i];
	}
	return sum;
}

double getSumSecondaryDiagonal(int** matr, int m)
{
	if (!matr||m==0)
	{
		return -1;
	}
	for (int i = 0; i < m; i++)
	{
		if (!matr[i])
		{
			return -1;
		}
	}

	double sum = 0;
	for (int i = 0; i < m; i++)
	{
		sum += matr[i][m - i - 1];
	}
	return sum;
}
double calculateMatrix(int** matr, int m)
{
	if (!matr||m==0)
	{
		return -1;
	}
	for (int i = 0; i < m; i++)
	{
		if (!matr[i])
		{
			return -1;
		}
	}

	double sumMain = getSumMainDiagonal(matr, m);
	double sumSecondary = getSumSecondaryDiagonal(matr, m);

	double finalSum = sumMain + sumSecondary;
	if (m%2!=0)
	{
		finalSum -= matr[m / 2][m / 2];
	}
	return finalSum;

}

//task 10
void myStrcpy(const char* source, char* dest)
{
	if (!source||!dest)
	{
		return;
	}

	while (*source)
	{
		*dest = *source;
		source++;
		dest++;
	}
	*dest = '\0';
}
char* GetWord(char* str)
{
	if (!str)
	{
		return nullptr;
	}

	char* maxWord = nullptr;
	unsigned maxLen = 0;

	/*char* currWord = nullptr;*/
	unsigned currLen = 0;

	char tempBuff[100]; //Временен буфер за текущата дума

	unsigned strLen = strlen(str);
	for (int i=0; i<=strLen ; i++) // za da broim i \0
	{
		char ch = str[i];
		if (ch==' '||ch=='\t'||ch=='\0')
		{
			if (currLen>0)
			{
				tempBuff[currLen] = '\0';
				if (currLen>maxLen)
				{
					maxLen = currLen;
					delete[] maxWord;
					maxWord = new char[maxLen + 1];
					myStrcpy(tempBuff, maxWord);
					/*maxLen = currLen;*/
				}
				currLen = 0;
			}
		}
		else
		{
			//if (currLen == 0) 
			//{
			//	currWord = &str[i]; // Запомняме началото на новата дума
			//}
			//currLen++;

			//sizeof(tempBuff): Това е размерът на масива tempBuff, който в този случай е 100 байта. Тъй като tempBuff е масив от символи (char), sizeof(tempBuff) връща броя на символите, които масивът може да съдържа, тоест 100.

			//-1: В нашата програма добавяме един допълнителен символ за терминиране на низ('\0'), така че в действителност можем да използваме само 99 символа за самата дума.Следователно, за да избегнем запис на извън границите на масива, проверката е currLen < sizeof(tempBuff) - 1.

				//Пример :
				//Ако tempBuff е масив от 100 символа, и currLen е 99, тогава индексът currLen е 99, което е валиден индекс в масива, но ако записваме в tempBuff[99], трябва да оставим последния индекс(100 - ти) за терминиращия символ '\0'.
			if (currLen<sizeof(tempBuff)-1)
			{
				tempBuff[currLen] = ch;
				currLen++;
			}
		}
	}

	return maxWord;
}
int main()
{
    //04
	/*const char* t1 = "12:30:45";
	std::cout << checkTimeStr(t1);*/

	//05
	/*const char* res = checkStr("asdfgajk");
	std::cout << res;
	delete[] res;*/

	//06
	/*std::cout << numCalc(1234567, 5, 2);*/

	//07
	/*int arr[6] = { 1, 6, 1, 0, 5, 199 };
	std::cout << AnalyzeArray1(arr, 6);*/

	//08
	//char str[100];
	//char word[50];
	//std::cout << "Enter symbols: ";
	//std::cin.getline(str, 100); // Въвеждаме символния низ (включително интервали)

	//std::cout << "Enter word: ";
	//std::cin >> word;

	//std::cout << doExist(str, word);

	//09
	/*int** matr = createMatrix(3);
	std::cout << calculateMatrix(matr, 3);*/

	char str[] = "I will love you always";
	char* max = GetWord(str);
	std::cout << max;
	delete[] max;
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
