// pract 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//task 01
unsigned myStrlen(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}

void addCharToWord(const char* str, char* res, char sym, int ind)
{
	if (!str||!res)
	{
		return;
	}

	int counter = 0;
	while (*str)
	{
		if (counter==ind)
		{
			*res = sym;
			res++;
		}
		*res = *str;
		counter++;
		str++;
		res++;
	}
	*res = '\0';
}

//task 02
void createStringFromSymbols(const char* source, char* dest)
{
	if (!source||!dest)
	{
		return;
	}

	int sourceLen = myStrlen(source);
	while (*source)
	{
		char currentSymbol = *source;
		source++;
		int index = *source - '0';
		dest[index] = currentSymbol;
		source++;
	}
	dest += (sourceLen / 2);
	*dest = '\0';
}

//04
int countSymbol(const char* str, char sym)
{
	if (!str)
	{
		return -1;
	}

	int count = 0;
	while (*str)
	{
		if (*str==sym)
		{
			count++;
		}
		str++;
	}
	return count;
}
void removeSymbolFromStr(const char* source, char* res, char sym)
{
	if (!source || !res)
	{
		return;
	}

	while (*source)
	{
		if (*source!=sym)
		{
			*res = *source;
			res++;
		}
		source++;
	}
	*res = '\0';
}

//05
bool isSymbolInString(const char* str, char ch)
{
	if (!str)
	{
		return false;
	}

	while (*str)
	{
		if (*str==ch)
		{
			return true;
		}
		str++;
	}
	return false;
}

void createStrByDiffs(const char* str1, const char* str2, char* res)
{
	if (!str1||!str2||!res)
	{
		return;
	}

	const char* originalStr1 = str1;
	const char* originalStr2 = str2;
	while (*str1)
	{
		if (!(isSymbolInString(str2,*str1)))
		{
			*res = *str1;
			res++;
		}
		str1++;
	}
	str1 = originalStr1;
	str2 = originalStr2;
	while (*str2)
	{
		if (!(isSymbolInString(str1, *str2)))
		{
			*res = *str2;
			res++;
		}
		str2++;
	}
	*res = '\0';
}

//task 06
char toUpper(char ch)
{
	if (ch>='a'&&ch<'z')
	{
		return ch - ('a' - 'A');
	}
	return ch;
}
void upperFirstLetters(char* str)
{
	if (!str)
	{
		return;
	}
	str[0] = toUpper(str[0]);
	str++;
	while (*str)
	{
		if (*str==' ')
		{
			str++;
			if (*str)
			{
				*str = toUpper(*str);
			}
		}
		str++;
	}

}

//task 03
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
char getStringFromDigit(unsigned digit)
{
	return digit + '0';
}
int countRepetitionsOfDigit(const char* str, unsigned digit)
{
	if (!str)
	{
		return -1;
	}

	int count = 0;
	char ch = getStringFromDigit(digit);
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

int getCountOfAllDifferentDigits(const char* str)
{
	if (!str)
	{
		return -1;
	}

	int count = 0;
	for (unsigned digit = 0; digit <= 9; digit++)
	{
		if (countRepetitionsOfDigit(str, digit) > 0) 
		{
			count++;
		}
	}
	return count;
}

void getResult(const char* str, char* result)
{
	if (!str||!result)
	{
		return;
	}

	size_t diff = getCountOfAllDifferentDigits(str);
	size_t resultLen = 4 * diff+1;
	char* tempResult = new char[resultLen];

	int resInd = 0;
	for (int i = 0; i <= 9 ; i++)
	{
		int curr = countRepetitionsOfDigit(str, i);
		if (curr > 0)
		{
			tempResult[resInd++] = getStringFromDigit(curr);
			tempResult[resInd++] = 'x';
			tempResult[resInd++] = getStringFromDigit(i);
			tempResult[resInd++] = ',';
		}
	}
	if (resInd>0)
	{
		tempResult[resInd-1] = '\0';
	}
	else
	{
		tempResult[resInd] = '\0';
	}

	myStrcpy(result, tempResult);
	delete[] tempResult;
}
int main()
{
	//01
	/*char str[] = "Hello,y friend!";
	char* res = new char[myStrlen(str) + 2];
	addCharToWord(str, res, 'm', 6);
	std::cout << res << std::endl;*/

	//02
	/*char str[] = "a0b234c1d3";
	char* res = new char[myStrlen(str) / 2 +1];
	createStringFromSymbols(str, res);
	std::cout << res << std::endl;*/

	//04
	/*char str[] = "Hello, my friend!";
	char res[100];
	removeSymbolFromStr(str, res, 'e');
	std::cout << res << std::endl;*/

	//05
	/*char str1[] = "abcde";
	char str2[] = "acdef";
	char res[100];
	createStrByDiffs(str1, str2, res);
	std::cout << res << std::endl;*/

	//06
	//char str[] = "hello, my friend!";
	//upperFirstLetters(str);
	//std::cout << str;

	//03
	char str[] = "4231148";
	char res[100];
	getResult(str, res);
	std::cout << res;
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
