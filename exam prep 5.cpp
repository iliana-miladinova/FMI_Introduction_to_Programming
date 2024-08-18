
// exam prep 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//example tasks from moodle - pdf
//task 01

double myAbs(double num)
{
	if (num<0)
	{
		return -num;
	}
	return num;
}

double sqrt_a(double a, double eps)
{
	if (a==0)
	{
		return 0;
	}

	double xK = a;
	double xKplus1;
	do
	{
		double div = a / xK;
		double mult = xK + div;
		xKplus1 = 0.5 * mult;
		if (myAbs(xKplus1-xK)<eps)
		{
			break;
		}
		xK = xKplus1;
	} while (true);

	//double xK = a;
	//double div = a / xK;
	//double mult = xK + div;
	//double xKplus1 = 0.5 * mult;

	//while (myAbs(xKplus1-xK)>=eps)
	//{
	//	xK = xKplus1;
	//	div = a / xK;
	//	mult = xK + div;
	//	xKplus1 = 0.5 * mult;
	//	
	//}
	return xKplus1;
}

//02
bool isLower(char ch)
{
	return ch >= 'a' && ch <= 'z';
}

bool isUpper(char ch)
{
	return ch >= 'A' && ch <= 'Z';
}

void makeLower(char& ch)
{
	if (isUpper(ch))
	{
		ch = ch + ('a' - 'A');
	}
	return;
}

void makeUpper(char& ch)
{
	if (isLower(ch))
	{
		ch = ch - ('a' - 'A');
	}
	return;
}

void Revert(char* str)
{
	if (!str)
	{
		return;
	}

	while (*str)
	{
		if (isLower(*str))
		{
			makeUpper(*str);
		}
		else if (isUpper(*str))
		{
			makeLower(*str);
		}
		str++;
	}

}

//task 03
bool isDigit(char dig)
{
	return dig >= '0' && dig <= '9';
}

int getDigFromChar(char ch)
{
	if (isDigit(ch))
	{
		return ch - '0';
	}
	return -1;
}

bool isLeap(int year)
{
	if (year%4==0)
	{
		if (year%100==0)
		{
			if (year%400==0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	return false;
}

int getMonthFromDate(const char* date)
{
	return getDigFromChar(date[3]) * 10 + getDigFromChar(date[4]);
}

int getDayFromDate(const char* date)
{
	return getDigFromChar(date[0]) * 10 + getDigFromChar(date[1]);
}

int getYearFromDate(const char* date)
{
	return getDigFromChar(date[6]) * 1000 + getDigFromChar(date[7]) * 100 + getDigFromChar(date[8]) * 10 + getDigFromChar(date[9]);
}
bool CheckDate(const char* date)
{
	if (!date)
	{
		return false;
	}

	if (date[2]!='.'||date[5]!='.')
	{
		return false;
	}

	int lenDate = strlen(date);
	if (lenDate!=10)
	{
		return false;
	}

	for (int i = 0; date[i]!='\0'; i++)
	{
		if (i==2||i==5)
		{
			continue;
		}
		else if (!isDigit(date[i]))
		{
			return false;
		}
	}

	int day = getDayFromDate(date);
	int month = getMonthFromDate(date);
	int year = getYearFromDate(date);
	if (month<=0 || month>12)
	{
		return false;
	}
	if (day<=0)
	{
		return false;
	}
	if (year<=0)
	{
		return false;
	}
	/*if (month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		if (day>31)
		{
			return false;
		}
	}*/
	// Проверка на броя на дните в месеца
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day>31)
		{
			return false;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day>30)
		{
			return false;
		}
		break;
	case 2:
		if (isLeap(year))
		{
			if (day>29)
			{
				return false;
			}
		}
		else
		{
			if (day>28)
			{
				return false;
			}
		}
		break;
	}
	//if (month==2)
	//{
	//	if (isLeap(year))
	//	{
	//		if (day > 29)
	//		{
	//			return false;
	//		}
	//	}
	//	else if (day>28)
	//	{
	//		return false;
	//	}
	//}
	//if ((month%2!=0&&month<=7)||(month%2==0&&month>7))
	//{
	//	if (day>31)
	//	{
	//		return false;
	//	}
	//}
	//else /*if (month==4||month==6||month==9||month==11)*/
	//{
	//	if (day>30)
	//	{
	//		return false;
	//	}
	//}
	return true;
}

//task 04
unsigned getNumLen(long num)
{
	if (num==0)
	{
		return 1;
	}
	unsigned count = 0;
	while (num!=0)
	{
		count++;
		num /= 10;
	}
	return count;
}

void removeLastDigit(long& num)
{
	num /= 10;
}
int DigitPos(long num, int k)
{
	num = myAbs(num);
	unsigned size = getNumLen(num);
	if (k>size||k<0||size==0)
	{
		return -1;
	}
	else if (k==size)
	{
		return num % 10;
	}

	int digitsToRemove = size - k;
	
	while (digitsToRemove>0)
	{
		removeLastDigit(num);
		digitsToRemove--;;
	}
	return num % 10;
}

//task 05
bool doExist(const char* symbols, const char* word)
{
	if (!symbols||!word)
	{
		return false;
	}

	size_t wordLen = strlen(word);
	bool inWord = false;
	int wordInd = 0;

	for (int i = 0; symbols[i]!=0; i++)
	{
		if (inWord)
		{
			if (symbols[i]!=word[wordInd])
			{
				inWord = false;
				if (wordInd==wordLen)
				{
					return true;
				}
				wordInd = 0;
			}
			else
			{
				wordInd++;
				if (wordInd==wordLen)
				{
					return true;
				}
			}
		}
		else if (symbols[i] == word[wordInd])
		{
			inWord = true;
			wordInd++;
		}
	}
	if (inWord&&wordInd==wordLen)
	{
		return true;
	}
	return false;
}

// 2 variant
bool isAlphaOrNum(char ch)
{
	return (ch >= 'a' && ch <= 'z')
		|| (ch >= 'A' && ch <= 'Z')
		|| (ch >= '0' && ch <= '9');
}
bool doExist1(const char* symbols, const char* word)
{
	if (!symbols || !word)
	{
		return false;
	}

	size_t wordLen = strlen(word);

	size_t wordInd = 0;
	for (int i = 0; symbols[i]!='\0'; i++)
	{
		char ch = symbols[i];
		if (isAlphaOrNum(ch))
		{
			if (isUpper(ch))
			{
				makeLower(ch);
			}
			if (ch==symbols[i])
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
int main()
{
    //01
	/*std::cout << sqrt_a(4, 0.0000001);*/

	//02
	/*char str[] = "IlIaNa MiLaDiNoVa, 20";
	Revert(str);
	std::cout << str;*/

	//03
	/*std::cout << CheckDate("29.02.2004");*/

	//04
	/*std::cout << DigitPos(-987654321, 9);*/
	char str[] = "My, beautiful.";
	char word[] = "beautiful";
	std::cout << doExist(str, word);
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
