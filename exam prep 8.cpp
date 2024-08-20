// exam prep 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//photo-from last year
int countCharInArr(const char* str, char ch)
{
	if (!str)
	{
		return 0;
	}
	int count = 0;
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
//int analyzeArr(const char* str)
//{
//	if (!str)
//	{
//		return 0;
//	}
//
//	int count = 0;
//	const char* temp = str;
//	while (*str)
//	{
//		if (countCharInArr(temp,*str)==1)
//		{
//			count++;
//		}
//		str++;
//	}
//	return count;
//}

//2 nachin 
int analyzeArr(const char* str)
{
	if (!str)
	{
		return -1;
	}

	int charCount[256]{ 0 }; //int charCount[128]{0};
	while (*str)
	{
		charCount[*str]++;
		str++;
	}

	int count = 0;
	for (int i = 0; i < 256; i++)
	{
		if (charCount[i]==1)
		{
			count++;
		}
	}
	return count;
}

//task 02
int getModulo(long num, int num2)
{
	if (num2==0)
	{
		return 0;
	}
	int res = num / num2;
	int modulo = num - res * num2;
	return modulo;
}
long power(long num, unsigned k)
{
	long res = 1;
	for (int i = 0; i < k; i++)
	{
		res *= num;
	}
	return res;
}



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

bool isDivisable(long num, int num2)
{
	if (num2==0)
	{
		return false;
	}
	long res = num / num2;
	return num == (res * num2);
}
int checkNum(long N)
{
	if (abs(N)>=power(10,9))
	{
		return -1;
	}

	int digitsCount = countDigits(N);
	for (int i = digitsCount; i > 0; i--)
	{
		int digToRemove = getModulo(N / power(10, i-1) ,10);//N / power(10, i-1)%10;
		int leftPart = N / power(10, i);
		int rightPart = getModulo(N, power(10, i-1));//N% power(10, i-1);

		int newNum = leftPart * power(10, i - 1) + rightPart;
		if (isDivisable(newNum,3))
		{
			return digitsCount - i + 1;
		}
	}
	return 0;
}

// 2 nachin
int getSumOfDigits(long N)
{
	if (N==0)
	{
		return 0;
	}
	int sum = 0;
	while (N!=0)
	{
		sum += N % 10;
		N /= 10;
	}
	return sum;
}
int checkNum1(long N)
{
	if (abs(N)>=power(10,9))
	{
		return -1;
	}
	int sumDig = getSumOfDigits(N);
	int digCount = countDigits(N);
	for (int i = digCount; i > 0; i--)
	{
		int digToRemove = N / power(10, i - 1) % 10;
		int newSumDig = sumDig - digToRemove;
		if (isDivisable(newSumDig,3))
		{
			return digCount - i + 1;
		}
	}
	return 0;

}

//3 nachin
int getNthDigit1(int num, int pos)
{
	int div = 1;
	for (int i = 0; i < pos-1; i++)
	{
		div *= 10;
	}

	int shiftedNum = num / div;
	int lastDig = shiftedNum - (shiftedNum / 10) * 10;
	return lastDig;
}
int getSumOfDigits1(long N)
{
	if (N == 0)
	{
		return 0;
	}
	int sum = 0;
	int digCount = countDigits(N);
	for (int i = 1; i <= digCount; i++)
	{
		sum += getNthDigit1(N, i);
	}
	return sum;
}

int checkNum2(long N)
{
	if (abs(N)>=power(10,9))
	{
		return -1;
	}

	int sumDig = getSumOfDigits(N);
	int digCount = countDigits(N);
	for (int i = digCount; i >= 1; i--) //zashtoto getNthDigit ni vrashta naj-dyasnata cifra, toest trygva ot kraya kam nachaloto
	{
		int digToRemove = getNthDigit1(N, i);
		int newSum = sumDig - digToRemove;
		if (isDivisable(newSum,3))
		{
			return digCount-i+1;
		}
	}
	return 0;
}

//rask 03
char* encodeWord(const char* word, int N)
{
	if (!word||N<2||N>49)
	{
		return nullptr;
	}

	int len = strlen(word);
	char* res = new char[len + 1];
	int resInd = 0;

	while (*word)
	{
		int ascii = *word;
		int encodeAscii = *word + N;
		if (encodeAscii>126)
		{
			encodeAscii = (encodeAscii - 127) + 32;
			
		}
		res[resInd] = encodeAscii;
		resInd++;
		word++;
	}
	res[resInd] = '\0';
	return res;
}

//2 nachin
char* encodeWord1(const char* word, int N)
{
	if (!word || N < 2 || N>49)
	{
		return nullptr;
	}

	int len = strlen(word);
	char* res = new char[len + 1];
	int resInd = 0;

	while (*word)
	{
		char currChar = *word;
		char newChar = ((currChar - 32) +N)% 95 + 32;
		res[resInd] = newChar;
		resInd++;
		word++;
	}
	res[resInd] = '\0';
	return res;
}


//hw 1 task 4
bool getInput(unsigned& startYear, unsigned& startMonth, unsigned& startDay,
	unsigned& endYear, unsigned& endMonth, unsigned& endDay, unsigned& interval)
{
	std::cin >> startYear >> startMonth >> startDay >> endYear >> endMonth >> endDay >> interval;

	if ((startYear<1600||startYear>2100)||(endYear<1600||endYear>2100)||(startYear>endYear)
		||(startMonth<1||startMonth>12)||(endYear<1||endMonth>12)
		||(startDay<1||startDay>31)||(endDay<1||endDay>31)
		||(startDay>endDay&&startMonth>endMonth&&startYear>endYear)
		||(interval<1||interval>365)
		||(startYear==1916&&startMonth==4&&(startDay>=1&&startDay<=13)))
	{
		return false;
	}
	return true;
}

bool isLeapYear(unsigned year)
{
	if (year < 1916) // Юлиански календар
	{
		return year % 4 == 0;
	}
	else if (year > 1916) // Григориански календар
	{
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}
	else // 1916 година: от 14 април е в сила Григорианския календар
	{
		return false; // 1916 не е високосна в Григорианския календар
	}
}

void updateFebruary(unsigned* daysOfMonth, unsigned year)
{
	if (isLeapYear(year))
	{
		daysOfMonth[1] = 29;
	}
	else
	{
		daysOfMonth[1] = 28;
	}
}

void changeDaysWithInterval(unsigned* daysOfMonth, unsigned& day, unsigned& month, unsigned& year, unsigned interval)
{
	while (day>daysOfMonth[month-1])
	{
		day = day - daysOfMonth[month - 1];
		if (month+1>12)
		{
			year++;
			month = 1;

			updateFebruary(daysOfMonth, year);
		}
		else
		{
			month++;
		}
	}
}

void checkGregorianToUlianCalendar(unsigned startYear, unsigned startMonth, unsigned startDay)
{
	if (startYear==1916&&startMonth==4&&startDay<=13)
	{
		startDay += 14;
	}
}

void splitInterval(unsigned startYear, unsigned startMonth, unsigned startDay, unsigned endYear, unsigned endMonth, unsigned endtDay, unsigned interval)
{
	unsigned daysOfMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	updateFebruary(daysOfMonth, startYear);
	if (startYear==endYear&&startMonth==endMonth&&startDay==endtDay)
	{
		std::cout << startYear << '-' << startMonth << '-' << startDay << '-' << startYear << '-' << startMonth << '-' << startDay << std::endl;
		return;
	}

	while (startYear < endYear || startMonth < endMonth || startDay < endtDay)
	{
		std::cout << startYear << '-' << startMonth << '-' << startDay << '-';
		startDay += interval;
		if (startDay>=daysOfMonth[startMonth-1] &&interval!=1)
		{
			changeDaysWithInterval(daysOfMonth, startDay, startMonth, startYear, interval);
		}
		else if (startDay>=daysOfMonth[startMonth-1]&&interval==1)
		{
			std::cout << startYear << '-' << startMonth << '-' << startDay - 1 << std::endl;;
			changeDaysWithInterval(daysOfMonth, startDay, startMonth, startYear, interval);
			checkGregorianToUlianCalendar(startYear, startMonth, startDay);
			continue;
		}
		checkGregorianToUlianCalendar(startYear, startMonth, startDay);

		// Check if this is the final interval is bigger than endYear, endMonth, endDay
		if (startYear >= endYear && startMonth >= endMonth && (startDay - 1) > endtDay)
		{
			std::cout << endYear << '-' << endMonth << '-' << endtDay << std::endl;
			break;
		}
		std::cout << startYear << '-' << startMonth << '-' << startDay - 1 << std::endl;;
	}

}

//2020/2021 august
//task 02
int* numOfWords(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	int resLen = 2;
	int* res = new int[resLen] {0};
	int wordInd = 0;

	for (int i = 0; str[i]!='\0'; i++)
	{
		char ch = str[i];
		if (ch==' '||ch=='\t')
		{
			if (wordInd>0)
			{
				if (wordInd%2==0)
				{
					res[0]++;
				}
				else 
				{
					res[1]++;
				}
				wordInd = 0;
			}
		}
		else
		{
			wordInd++;
		}
	}
	if (wordInd>0)
	{
		if (wordInd%2==0)
		{
			res[0]++;
		}
		else
		{
			res[1]++;
		}
	}
	return res;
}

void printArr(const int* arr, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

//task 03
int* mergeArrays(const int* arr1, const int* arr2, int m)
{
	if (!arr1||!arr2||m<=0)
	{
		return nullptr;
	}

	int* res = new int[m];
	int resInd = 0;
	for (int i = 0; i < m; i++)
	{
		res[resInd] = arr1[i] + arr2[m - i - 1];
		resInd++;
	}
	return res;
}

//task 07
bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

long convertNumber(const char* num)
{
	if (!num)
	{
		return -1;
	}

	/*const char* tempNum = num;*/
	int sum = 0;
	while (*num)
	{
		if (!isDigit(*num))
		{
			return -1;
		}
		sum += *num;
		num++;
	}
	/*num = tempNum;

	int sum = 0;
	while (*num)
	{
		sum += *num;
		num++;
	}*/
	return sum;
}

//task 08
double mySin(double x, long n)
{
	double res = 0.0;
	double term = x;
	double sign = 1;
	for (int i = 1; i <=n ; i++)
	{
		res += sign * term;
		term = (term * x * x) / ((2 * i) * (2 * i + 1));
		sign = -sign;
	}
	return res;
}

double myCos(double x, long n)
{
	double res = 1.0;
	double term = 1.0;
	double sign = -1.0;
	for (int i = 1; i <= n; i++)
	{
		term = (term * x * x) / ((2 * i - 1) * (2 * i));
		res += sign * term;
		sign = -sign;
	}
	return res;
}

//task 09
char getDigCharFromDigit(int n)
{
	return '0' + n;
}
char* Encode(const char* str)
{
	if (!str)
	{
		return nullptr;
	}
	int len = strlen(str);
	int resLen = 3 * len + (len - 1);
	char* res = new char[resLen];

	int ind = 0;
	while (*str)
	{
		char ch = *str;
		if (ch != ' ')
		{
			int ascii = ch;
			if (ascii >= 100)
			{
				res[ind] = getDigCharFromDigit(ascii / 100);
				ind++;
				ascii %= 100;

			}
			if (ascii >= 10)
			{
				res[ind] = getDigCharFromDigit(ascii / 10);
				ind++;
				ascii %= 10;
			}
			res[ind] = getDigCharFromDigit(ascii);
			ind++;
			if (*(str+1)!='\0' && *(str+1)!=' ')
			{
				res[ind] = '_';
				ind++;
			}
		}
		str++;
	}
	res[ind] = '\0';
	return res;
}
int main()
{
    //task 01
	/*std::cout << analyzeArr("abbccdfgB%%&");*/

	//task 02
	//std::cout << checkNum2(12345);
	///*std::cout << getModulo(123, 100);*/
	//std::cout << getNthDigit1(1246, 2);

	//task 03
	/*char* res = encodeWord1("!Gwv", 14);
	std::cout << res;
	delete[] res;*/

	//hw1 task 01
	/*unsigned startYear, startMonth, startDay, endYear, endMonth, endDay, interval;
	bool isValid = getInput(startYear, startMonth, startDay, endYear, endMonth, endDay, interval);
	if (isValid)
	{
		splitInterval(startYear, startMonth, startDay, endYear, endMonth, endDay, interval);
	}
	else
	{
		std::cout << "Invalid input" << std::endl;
	}*/

	//task 02
	/*char str[100];
	std::cin.getline(str,100);
	int* res = numOfWords(str);
	printArr(res, 2);
	delete[] res;*/

	/*constexpr int size = 4;
	int arr1[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr1[i];
	}
	int arr2[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr2[i];
	}
	int* res = mergeArrays(arr1, arr2, size);
	printArr(res, size);
	delete[] res;*/

	//task 07
	/*char str[100];
	std::cin >> str;
	std::cout << convertNumber(str);*/

	//task 08
	/*double x = 3.14159 / 2;
	long n = 10;
	std::cout << myCos(x, n);*/

	//09
	char str[100];
	std::cin.getline(str, 100);
	char* res = Encode(str);
	std::cout << res;
	delete[] res;
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
