// seminar 04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//mostCommonDigitOccurance
int countDigitOccurances(int n, int digit)
{
	if (digit > 9 || digit < 0)
	{
		return -1; 
	}

	int count = 0;

	while (n != 0)
	{
		if (n % 10 == digit)
		{
			count++;
		}
		n /= 10;
	}
	return count;
}

int mostCommonDigit(int n)
{
	int mostCommonDigit = -1;
	int mostCommonDigitOccurances = 0;

	for (int currentDigit = 0; currentDigit <= 9; currentDigit++)
	{
		int currentDigitOccurances = countDigitOccurances(n, currentDigit);

		if (currentDigitOccurances > mostCommonDigitOccurances)
		{
			mostCommonDigit = currentDigit;
			mostCommonDigitOccurances = currentDigitOccurances;
		}
	}

	return mostCommonDigit;
}

//task 01
bool isPrime(int n)
{
	if (n<=1)
	{
		return false;
	}

	double temp = sqrt(n);
	for (size_t i = 2; i <= temp; i++)
	{
		if (n%i==0)
		{
			return false;
		}
	}
	return true;
}

//task 02
unsigned countDigits(int num)
{
	unsigned count = 0;
	while (num!=0)
	{
		count++;
		num /= 10;
	}
	return count;
}
unsigned reverse(unsigned n)
{
	unsigned reverse=0;
	/*unsigned digitsCount = countDigits(n);
	for (int i = 0; i < digitsCount; i++)
	{
		int lastDigit = n % 10;
		reverse += lastDigit * pow(10, i);

		n /= 10;
		if (n==0)
		{
			break;
		}
	}*/
	while (n!=0)
	{
		int lastDigit = n % 10;
		reverse = reverse * 10 + lastDigit;
		n /= 10;
	}
	return reverse;
}

//task 03
bool isPalindrome(unsigned n)
{
	if (n==reverse(n))
	{
		return true;
	}
	return false;
}

//task 04 - my way
bool isSuffix(int num, int suffix)
{
	int reversedNum = reverse(num);
	int reversedSuffix = reverse(suffix);
	while (reversedNum!=0)
	{
		if (reversedNum==reversedSuffix)
		{
			return true;
		}
		reversedNum /= 10;
	}
	return false;
}

//task 04 - Angel's way
//bool isSuffix(unsigned num, unsigned suff)
//{
//	while (suff != 0)
//	{
//		unsigned lastDigOfNum = num % 10;
//		unsigned lastDigitOfSuff = suff % 10;
//		if (lastDigOfNum!=lastDigitOfSuff)
//		{
//			return false;
//		}
//		num /= 10;
//		suff /= 10;
//	}
//	return true;
//}

//task 05
bool isPrefix(unsigned n, unsigned prefix)
{
	while (n >= prefix)
	{
		if (n==prefix)
		{
			return true;
		}
		n /= 10;
	}
	return false;
}

//task 06
bool isInfix(unsigned n, unsigned infix)
{
	while (n>=infix)
	{
		if (isSuffix(n,infix))
		{
			return true;
		}
		n /= 10;
	}
	return false;
}

//task 07
unsigned power(unsigned n, unsigned k)
{
	int res = 1;
	for (int i = 0; i < k; i++)
	{
		res *= n;
	}
	return res;
}

unsigned log(unsigned n, unsigned k)
{
	unsigned powerOfK = 1;
	unsigned count = 0;
	while (powerOfK<n)
	{
		powerOfK *= k;
		count++;
	}
	return count - 1;
}

double getDistance(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double absoluteValue(double n)
{
	if (n < 0)
	{
		return -n;
	}
	return n;
}
bool areBothPointsOnTheCircle(int a, int b, int c, int d)
{
	double point1Dist = getDistance(a, b, 0, 0);
	double point2Dist = getDistance(c, d, 0, 0);
	return absoluteValue(point1Dist-point2Dist)<=0.00000001;
}

//HOMEWORK
//task 03
double getPerimeter(unsigned x1, unsigned y1, unsigned x2, unsigned y2, unsigned x3, unsigned y3)
{
	double getA = getDistance(x1, y1, x2, y2);
	double getB = getDistance(x2, y2, x3, y3);
	double getC = getDistance(x1, y1, x3, y3);
	return getA + getB + getC;
}

//task 04
unsigned int concatDigitOnBack(unsigned int a, unsigned int digit)
{
	if (digit > 9)
	{
		return 0;
	}
	return a * 10 + digit;
}

unsigned int concatNumbers(unsigned int a, unsigned int b)
{
	if (a == 0)
	{
		return 0;
	}

	if (b == 0)
	{
		return concatDigitOnBack(a, 0);
	}

	unsigned result = a;
	unsigned reversedB = reverse(b);

	while (reversedB != 0)
	{
		int lastDigit = reversedB % 10;
		result = concatDigitOnBack(result, lastDigit);
		reversedB /= 10;
	}
	while (b % 10 == 0)
	{
		result = concatDigitOnBack(result, 0);
		b /= 10;
	}
	return result;
}

//task 05
unsigned concatWithReverse(unsigned num)
{
	unsigned rev = reverse(num);
	return concatNumbers(rev, num);
}

//task 06
bool isDevisor(unsigned k, unsigned dev)
{
	if (k%dev==0)
	{
		return true;
	}
	return false;
}
unsigned countPrimeDivisors(unsigned num)
{
	unsigned count = 0;
	for (size_t i = 2; i <=num ; i++)
	{
		if (isPrime(i))
		{
			if (isDevisor(num, i))
			{
				count++;
			}
		}
	}

	return count;
}
unsigned countNumsWithKPrimeDevisors(unsigned a, unsigned b, unsigned k)
{
	unsigned countNum = 0;
	for (unsigned i = a; i <= b; i++)
	{
		unsigned devisorsOfICount = countPrimeDivisors(i);
		if (devisorsOfICount==k)
		{
			countNum++;
		}
	}
	return countNum;
}

//task 07
bool isSortedInUpWay(unsigned num)
{
	if (num<=9)
	{
		return true;
	}
	while (num != 0)
	{
		int lastDigit = num % 10;
		int secondLastDigit = (num / 10) % 10;
		if (secondLastDigit<lastDigit)
		{
			return false;
		}
		num /= 10;
	}
	return true;
}

bool isSortedInDownWay(unsigned num)
{
	if (num<= 9)
	{
		return true;
	}
	while (num!=0)
	{
		unsigned lastDigit = num % 10;
		unsigned secondLast = (num / 10) % 10;
		if (secondLast>lastDigit)
		{
			return false;
		}
		num /= 10;
	}
	return true;
}

bool isSorted(unsigned num)
{
	return isSortedInDownWay(num) || isSortedInUpWay(num);
}

//task 08
bool containsSameDigits(unsigned num)
{
	if (num<=9)
	{
		return true;
	}
	unsigned lastDig = num % 10;
	while (num!=0)
	{
		if (lastDig!=num%10)
		{
			return false;
		}
		num /= 10;
	}
	return true;
}

//task 09
unsigned concatAtBack(unsigned num, unsigned digit, unsigned howManyTimes)
{
	for (size_t i = 0; i < howManyTimes; i++)
	{
		num = num * 10 + digit;
	}
	return num;
}

int sortNumber(unsigned num)
{
	int res = 0;
	for (size_t i = 0; i <= 9; i++)
	{
		int countOccurances = countDigitOccurances(num, i);
		res = concatAtBack(res, i, countOccurances);
	}
	return res;
}
int main()
{
	/*int n;
	std::cin >> n;
	std::cout << mostCommonDigit(n);*/

	//task 01
	/*int N;
	std::cin >> N;
	for (int i = 6; i <=N ; i+=6)
	{
		if (isPrime(i-1)&&isPrime(i+1))
		{
			std::cout << '<' << i - 1 << ',' << i + 1 << '>' << ' ';
		}
	}*/

	//task 02
	/*int n;
	std::cin >> n;*/
	/*std::cout << reverse(n);*/

	//task 03
	/*std::cout << isPalindrome(n);*/

	//task 04
	/*int suff;
	std::cin >> suff;*/
	/*std::cout << isSuffix(n, suff);*/

	//task 05
	/*std::cout << isPrefix(n, suff);*/

	//task 06
	/*std::cout << isInfix(n, suff);*/

	//task 07
	/*std::cout << power(n, suff);*/

	//task 08
	/*std::cout << log(n, suff);*/

	//task 09
	/*std::cout << areBothPointsOnTheCircle(1, 0, 0, 1);*/

	//homework
	//task 01
	/*std::cout << absoluteValue(-4);*/

	//task 02
	/*std::cout << countDigits(5430);*/

	//task 03
	/*std::cout << getPerimeter(1, 1, 4, 7, 0, 10);*/

	//task 04
	/*std::cout << concatNumbers(123, 3450);*/
		
	//task 05
	/*std::cout << concatWithReverse(1234);*/

	//task 06
	/*std::cout << countNumsWithKPrimeDevisors(19, 42, 3);*/

	//task 07
	/*std::cout << isSorted(122339);*/

	//task 08
	/*std::cout << containsSameDigits(111111);*/

	//task 09
	std::cout << sortNumber(531261);
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
