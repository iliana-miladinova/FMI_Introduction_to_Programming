// hw1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int countDivisors(int num)
{
    int count = 0;
	for (int i = 1; i <= num; i++)
	{
		if (num%i==0)
		{
			count++;
		}
	}
	return count;
}

int findNumOfCouples(int n, int k)
{
	unsigned x = 1;
	unsigned y = x;
	unsigned count = 0;
	if (x<1 || x>y || y>n )
	{
		return -1;
	}

	while (1 <= x && x <= y && y <= n)
	{
		unsigned dx = countDivisors(x);
		unsigned dy = countDivisors(y);
		if (k*dx*dy==x*y)
		{
			count++;
		}
		if (y<n)
		{
			y++;
		}
		else
		{
			x++;
			y = x;
		}
	}
	return count;
	
}


unsigned pairsOfWholeNumbers(unsigned n, unsigned k)
{
    unsigned x = 1;
    unsigned y = x;
    unsigned countNumberOfPairsXAndY = 0;
   /* if (x < 1 && x > y && y > n)
    {
        std::cout << "Incorrect input";
        return -1;
    }*/
    while (1 <= x && x <= y && y <= n)
    {
        unsigned countDevisorsOfX = countDivisors(x);
        unsigned countDevisorsOfY = countDivisors(y);
        if (k * countDevisorsOfX * countDevisorsOfY == x * y)
        {
            countNumberOfPairsXAndY++;
        }
        if (y < n)
        {
            y++;
        }
        else
        {
            x++;
            y = x;
        }
    }
    return countNumberOfPairsXAndY;
}

//task 02
unsigned findMinPeople(const int* peopleAsked, int asked)
{
	int count = 0;
	int population[1001]{ 0 };//masiv v kojto she zapazvame kolko pati sme poluchili daden otgovor. naprimer v primera 2,2,2,4 
								//population[2]=3;
	for (int i = 0; i < asked; i++)
	{
		int answer = peopleAsked[i];
		if (population[answer]%(answer+1)==0)//sled popul[answer]=0, sledvashtoto kpeto se deli na anser+1 e samoto popul[answe]=answer+1.
								//taka che ako ne se nalaga da razdelyame grupite na 2(ili poveche) grupi ne promenyame resultata
		{
			count += answer + 1;
		}
		population[answer]++;
	}
	return count;
}

//izpit zad.1
bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

char getCharFromDigit(unsigned digit)
{
	return digit + '0';
}

bool isDigitInArr(const char* arr, unsigned digit)
{
	if (!arr)
	{
		return false;
	}
	while (*arr)
	{
		if (isDigit(*arr))
		{
			int ch = getCharFromDigit(digit);
			if (ch==*arr)
			{
				return true;
			}
		}
		arr++;
	}

	return false;
}

bool containsDigits(const char* arr)
{
	if (!arr)
	{
		return false;
	}
	while (*arr)
	{
		if (isDigit(*arr))
		{
			return true;
		}
		arr++;
	}
	return false;
}
int analyzeArray(const char* arr)
{
	if (!arr||!(containsDigits(arr)))
	{
		return -1;
	}
	
	for (int i = 9; i >= 0; i--)
	{
		if (!(isDigitInArr(arr,i)))
		{
			return i;
		}
	}
}

//task 02
void selectionSort(int* arr, size_t size)
{
	for (int i = 0; i < size-1; i++)
	{
		int minElInd = i;
		for (int j = i+1; j < size; j++)
		{
			if (arr[j]>arr[minElInd])
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

int findMaxInArr(const int* arr, size_t size)
{
	if (!arr||size==0)
	{
		return -1;
	}

	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}
int findInex(const int* arr, size_t L)
{
	if (!arr||L==0)
	{
		return -1;
	}

	int maxValue = findMaxInArr(arr, L);
	int* count = new int[maxValue + 1] {0};

	for (int i = 0; i < L; i++)
	{
		count[arr[i]]++;
	}

	int accumulated = 0;
	for (int i = maxValue; i >= 0; i--)
	{
		accumulated += count[i];
		if (accumulated>=i)
		{
			delete[] count;
			return i;
		}
	}

	delete[] count;
	return -1;
	/*int count = 0;
	int globalCount = 0;
	for (int i = 0; i < L; i++)
	{
		if (arr[i]>=count+1)
		{
			count += 1;
		}
		else
		{
			if (count>globalCount)
			{
				globalCount = count;
			}
			count = 0;
		}
		
	}
	return globalCount;*/
}

//task 03
unsigned countDigits(long num)
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
char getCharFromDig(int dig)
{
	return dig + '0';
}
char* getStrFromNum(long num)
{
	unsigned digCount = countDigits(num);
	char* res = new char[digCount + 1];
	res[digCount] = '\0';

	for (int i = digCount-1; i >= 0; i--)
	{
		res[i] = getCharFromDig(num % 10);
		num /= 10;
	}
	return res;
}

long max(long n1, long n2)
{
	return n1 > n2 ? n1 : n2;
}

long min(long n1, long n2)
{
	return n1 < n2 ? n1 : n2;
}
char* findDiff(const long* arr, size_t N)
{
	if (!arr||N<2)
	{
		return nullptr;
	}

	/*size_t resLen = 4;
	char* res = new char[resLen];
	res[resLen] = '\0';*/

	long num1 = arr[0];
	long num2 = arr[1];
	long minDiff = abs(num1 - num2);

	for (int i = 1; i < N-1; i++)
	{
		if (abs(arr[i]-arr[i+1])<minDiff)
		{
			minDiff = abs(arr[i] - arr[i + 1]);
			num1 = arr[i];
			num2 = arr[i + 1];
		}
	}

	unsigned digCount1 = countDigits(num1);
	unsigned digCount2 = countDigits(num2);
	unsigned len = digCount1 + digCount2 + 1;
	char* res = new char[len+1];
	

	long maxNum = max(num1, num2);
	long minNum = min(num1, num2);

	char* max = getStrFromNum(maxNum);
	char* min = getStrFromNum(minNum);

	int resInd = 0;
	for (int i = 0; i < digCount1; i++)
	{
		res[resInd++] = max[i];
	}
	res[resInd++] = ',';
	for (int i = 0; i < digCount2; i++)
	{
		res[resInd++] = min[i];
	}
	res[resInd] = '\0';
	return res;
}
int main()
{
	/*std::cout << countDevisors(6);*/
	//std::cout << findNumOfCouples(25,9);

	/*int arr[1] = {0};
	std::cout << findMinPeople(arr, 1);*/

	//char str[] = "kw3592rt";
	//std::cout << analyzeArray(str);
	//const char* test1 = "123456789";
	//const char* test2 = "0123456789";
	//const char* test3 = "9876543210";

	//std::cout << "Missing digit in '123456789': " << analyzeArray(test1) << std::endl;
	//std::cout << "Missing digit in '0123456789': " << analyzeArray(test2) << std::endl;
	//std::cout << "Missing digit in '9876543210': " << analyzeArray(test3) << std::endl;

	/*int arr[5] = { 2,5,1,8,4 };
	selectionSort(arr, 5);
	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << ' ';
	}*/

	int arr[] = { 4, 3, 5, 2, 8, 3, 6, 3, 7, 8 };
	size_t L = sizeof(arr) / sizeof(arr[0]);
	std::cout << findInex(arr, L);

	/*std::cout << countDigits(123456);*/

	/*const long arr[] = { 10, 5, 20, 8, 15 };
	size_t N = sizeof(arr) / sizeof(arr[0]);

	char* result = findDiff(arr, N);
	std::cout << result;*/
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
