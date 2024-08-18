
// exam prep1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//task 01-2019/2020
int AnalyzeArray(int* arr, int l)
{
	if (!arr||l==0)
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

//task 02
int countSymbolRepetition(const char* str, char sym)
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

int countSymbolsThatAreRepetingOddTimes(const char* str)
{
	if (!str)
	{
		return -1;
	}

	char odd = '\0';
	int count = 0;
	while (*str)
	{
		if (countSymbolRepetition(str,*str)%2!=0 && *str!=odd)
		{
			count++;
			odd = *str;
		}
		str++;
	}
	return count;
}
int checkStr(const char* str)
{
	if (!str ||strlen(str)<2)
	{
		return -1;
	}

	int charCount[256] = { 0 };

	for (int i = 0; str[i]!='\0'; i++)
	{
		charCount[str[i]]++;
	}

	int odd = 0;
	for (int i = 0; i < 256; i++)
	{
		if (charCount[i]%2!=0)
		{
			odd++;
		}
	}
	if (strlen(str)%2==0)
	{
		if (odd==0)
		{
			return true;
		}
	}
	else
	{
		if (odd==1)
		{
			return true;
		}
	}
	return false;
}

//task 03
void ConvertNum(long& num)
{
	if (num >= -9 && num <= 9)
	{
		return;
	}

	bool isNegative = false;
	if (num < 0)
	{
		isNegative = true;
	}
	int tempRes = 0;
	long absNum = abs(num);
	while (absNum != 0)
	{
		tempRes = tempRes * 10 + absNum % 10;
		absNum /= 10;
	}

	if (isNegative)
	{
		num = -tempRes;
	}
	else
	{
		num = tempRes;
	}
}


//06
const int MAX_WORD_LENGTH = 100;

void copyWord(char* dest, const char* source) 
{
	int ind = 0;
	while (source[ind] != '\0')
	{
		dest[ind] = source[ind];
		ind++;
	}
	dest[ind] = '\0';
}

bool compareWords(const char* word1, const char* word2)
{
	int ind = 0;
	while (word1[ind] != '\0' && word2[ind] != '\0')
	{
		if (word1[ind] < word2[ind]) 
			//proveryava dali bukvata v word1 e po-malka ot bukvata v word2
		{
			return true; //word1 e predi word2 po azbuchen red
		}
		if (word1[ind] > word2[ind])
		{
			return false;
		}
		ind++;
	}
	return word1[ind] == '\0' && word2[ind] != '\0'; //dumite sa ednakvi
}

void toLower(char* word)
{
	int ind = 0;
	while (word[ind] != '\0') 
	{
		if (word[ind] >= 'A' && word[ind] <= 'Z') 
		{
			word[ind] = word[ind] + ('a' - 'A');
		}
		ind++;
	}
}

void getSmallestWord(const char* input) 
{
	char smallestWord[MAX_WORD_LENGTH] = "";
	char currentWord[MAX_WORD_LENGTH] = "";
	int currentIndex = 0;
	bool firstWord = true;

	for (int i = 0; input[i] != '\0'; ++i) 
	{
		if (input[i] == ' ' || input[i] == '?' || input[i] == ',' || input[i] == '.') 
		{
			if (currentIndex > 0) //stignali sme kraya na duma
			{
				currentWord[currentIndex] = '\0';
				toLower(currentWord); 
				if (firstWord || compareWords(currentWord, smallestWord))  
					//ako e paravata duma ili currentWord e po-malka ot smallestWord
																	
				{
					copyWord(smallestWord, currentWord); //zapisvame currentWord na smallestWord
					firstWord = false; //vsyaka sledvashta duma ne e parvata
				}
				currentIndex = 0;
			}
		}
		else
		{
			currentWord[currentIndex++] = input[i];
			//ako simvola ne e razdelitel, zapisvame bukvite ot izrecienieto na currentWord 
		}
	}

	// Проверка на последната дума
	if (currentIndex > 0) 
	{
		currentWord[currentIndex] = '\0';
		toLower(currentWord);
		if (firstWord || compareWords(currentWord, smallestWord))
		{
			copyWord(smallestWord, currentWord);
		}
	}

	std::cout << smallestWord << std::endl;
}
int main()
{
    //01
	/*int arr[6] = { 1,6,1,0,5,199 };
	std::cout << AnalyzeArray(arr, 6);*/

	//02
	/*std::cout << checkStr("asdfgjk");*/

	//03
	/*long num = 123456789;
	ConvertNum(num);
	std::cout << num;*/

	const char input[] = "Me? Why always me?";
	getSmallestWord(input);
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
