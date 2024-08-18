// seminar 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

unsigned myStrLen(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned res = 0;
	while (*str)
	{
		res++;
		str++;
	}
	return res;
}

void myStrCpy(const char* source, char* dest)
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

int myStrcmp(const char* first, const char* second)
{
	if (!first||!second)
	{
		return 0;
	}

	while ((*first)&&(*second)&&(*first==*second))
	{
		first++;
		second++;
	}

	return (*first - *second);
}

void myStrcat(char* first, const char* second)
{
	if (!first||!second)
	{
		return;
	}
	unsigned firstLen = myStrLen(first);
	first += firstLen;
	myStrCpy(second, first);
}

bool isPrefix(const char* pattern, const char* text)
{
	while ((*text)&&(*pattern))
	{
		if (*text!=*pattern)
		{
			return false;
		}
		text++;
		pattern++;
	}
	return *pattern == '\0';
}

bool searchInText(const char* text, const char* pattern)
{
	int textLen = myStrLen(text);
	int patternLen = myStrLen(pattern);
	while (patternLen<=textLen)
	{
		if (isPrefix(pattern,text))
		{
			return true;
		}
		text++;
		textLen--;
	}
	return false;
}

//str to num

int converCharToDigit(char ch)
{
	if (ch>='0'&&ch<='9')
	{
		return ch - '0';
	}
	return -1;
}

unsigned convertStringToUnsigned(const char* str)
{
	if (!str)
	{
		return 0;
	}
	unsigned res = 0;
	while (*str)
	{
		int digit = converCharToDigit(*str);
		if (digit==-1)
		{
			return 0;
		}
		/*res = res * 10 + digit;*/
		(res *= 10) += digit;
		str++;
	}
	return res;
}

int converStringToSigned(const char* str)
{
	if (!str)
	{
		return 0;
	}
	if (*str == '-')
	{
		return -1 * convertStringToUnsigned(str + 1);
	}
	else
	{
		return convertStringToUnsigned(str);
	}
}

//num to str

char getCharFromDigit(int digit)
{
	if (digit<0||digit>9)
	{
		return '\0';
	}
	return digit + '0';
}

unsigned getNumLen(int num)
{
	if (num==0)
	{
		return 1;
	}

	unsigned len = 0;
	while (num!=0)
	{
		len++;
		num /= 10;
	}
	return len;
}

void toString(unsigned n, char* str)
{
	unsigned len = getNumLen(n);
	for (int i = len-1; i >= 0; i--)
	{
		str[i] = getCharFromDigit(n % 10);
		n /= 10;
	}
	str[len] = '\0';
}

//
unsigned countCharOccurances(const char* str, char ch)
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

//task 02
char toUpperChar(char ch)
{
	if (ch>='a'&&ch<='z')
	{
		return ch - ('a' - 'A');
	}
	return ch;
}

void toUpper(char* str)
{
	if (!str)
	{
		return;
	}

	while (*str)
	{
		*str=toUpperChar(*str);
		str++;
	}
}

char toLowerChar(char ch)
{
	if (ch>='A'&&ch<='Z')
	{
		return ch - 'A' + 'a';
	}
	return ch;
}

void toLower(char* str)
{
	if (!str)
	{
		return;
	}
	while (*str)
	{
		if (*str>='A'&&*str<='Z')
		{
			*str = toLowerChar(*str);
		}
		str++;
	}
}

//task 03
bool isSeparator(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == ',' || ch == '.' || ch == '?' || ch == '!' || ch == ';' || ch == ':');
}

unsigned countWords(const char* str)
{
	if (!str)
	{
		return 0;
	}

	unsigned count = 0;
	bool isInWord = false;
	while (*str)
	{
		if (isSeparator(*str))
		{
			if (isInWord)
			{
				count++;
				isInWord = false;
			}
		}
		else
		{
			isInWord = true;
		}
		str++;
	}
	return count;
}

//task 01
bool isPrefix1(const char* str, const char* pattern)
{
	if (!str||!pattern)
	{
		return 0;
	}

	while (*str && *pattern)
	{
		if (*str!=*pattern)
		{
			return false;
		}
		str++;
		pattern++;
	}

	return *pattern == '\0';
}

void shiftLeft(char* str, size_t shiftWith)
{
	if (!str)
	{
		return;
	}

	while (*str)
	{
		*(str - shiftWith) = *str;
		str++;
	}
	*(str - shiftWith) = '\0';
}

void shiftRight(char* str, size_t shiftWith)
{
	if (!str)
	{
		return;
	}

	size_t strLen = myStrLen(str);
	for (int i = strLen-1; i >= 0;  i--)
	{
		str[i + shiftWith] = str[i];
	}
	str[strLen + shiftWith] = '\0';
}

void replace(char* text, const char* what, size_t whereLen)
{
	if (!text||!what)
	{
		return;
	}

	size_t whatLen = myStrLen(what);
	if (whatLen>whereLen)
	{
		shiftRight(text + whereLen, whatLen - whereLen);
	}
	else if (whatLen<whereLen)
	{
		shiftLeft(text + whereLen, whereLen - whatLen);
	}

	while (*what)
	{
		*text = *what;
		text++;
		what++;
	}
}

void replaceInText(char* text, char* where, const char* what)
{
	if (!text||!where||!what)
	{
		return;
	}

	size_t textLen = myStrLen(text);
	size_t whereLen = myStrLen(where);
	size_t whatLen = myStrLen(what);

	while (textLen>=whereLen)
	{
		if (isPrefix1(text,where))
		{
			replace(text, what, whereLen);
			if (whereLen<whatLen)
			{
				textLen += whereLen - whatLen;
			}
			else
			{
				textLen -= whatLen - whereLen;
			}
		}
		textLen--;
		text++;
	}
}

//task 04
const int MAX_WORDS = 100;
const int MAX_WORD_LENGTH = 50;

char words[MAX_WORDS][MAX_WORD_LENGTH];//съхранява множество думи 
//всеки ред представлява една дума,
// а колоните представляват символите на думата

int wordCount[MAX_WORDS];
int totalWords = 0; 
//broyat razlichni dumi

//във условието е споменато, че няма разлика между главни и малки букви затова
// аз си избирам всички букви да бъдат малки
char toLowerCase(char ch)
{
	if (ch>='A'&&ch<='Z')
	{
		return ch + ('a' - 'A');
	}
	return ch;
}

// Функция за сравняване на два низа, игнорирайки разликата между главни и малки букви
bool compareWords(const char* word1, const char* word2)
{
	if (!word1||!word2)
	{
		return 0;
	}

	while (*word1 && *word2)
	{
		if (toLowerCase(*word1)!=toLowerCase(*word2))
		{
			return false;
		}
		word1++;
		word2++;
	}
	return *word1 == '\0' && *word2 == '\0';  
	//Ако и двата низа са равни, те трябва да завършват на същото място,
	// т.е. и двата трябва да имат нулев терминатор в същото положение
}

//Тази функция проверява дали думата вече съществува и ако не съществува я добавя като нова дума
void addWord(const char* word)
{
	if (!word)
	{
		return;
	}

	for (int i = 0; i < totalWords; i++) //Цикълът преминава през всички запазени думи в масива words
	{
		if (compareWords(words[i],word)) //Сравнява текущата дума (words[i]) с подадената дума (word)
		{
			wordCount[i]++; //увеличава броя на срещанията на тази дума
			return; // излиза от функцията, защото думата вече съществува и сме увеличили броя ѝ
		}
	}

	// Добавяне на нова дума
	//Ако думата не е намерена в масива words, преминаваме към добавянето ѝ
	int ind = 0;
	//За да добавите дума в масива, просто присвоявате символите на тази дума
	// на конкретен ред от двумерния масив и добавяте нулевия терминатор
	while (word[ind]!='\0' && ind<MAX_WORD_LENGTH-1)
	{
		words[totalWords][ind] = word[ind];
		ind++;
	}
	words[totalWords][ind] = '\0';
	wordCount[totalWords] = 1;
	totalWords++;  //Увеличава броя на уникалните думи, тъй като сме добавили нова
}

// Функция за намиране на най-често срещаната дума
const char* mostFrequentWord()
{
	const char* mostFrequentWord = nullptr;
	int maxCount = 0;
	for (int i = 0; i < totalWords; i++)
	{
		if (wordCount[i]>maxCount)
		{
			mostFrequentWord = words[i]; //wordCount-Броя на срещанията за всяка дума
			maxCount = wordCount[i];
		}
	}
	return mostFrequentWord;
}


//Функцията processString има за цел да обработва низ от символи,
// да извлича от него думи и да добавя тези думи в масив от думи
void processString(const char* str)
{
	char word[MAX_WORD_LENGTH]; //използва се за съхранение на текущата дума
	int wordInd = 0; //следи текущото място за запис на символи в масива word

	for (int i = 0; str[i]!='\0'; i++)
		//Функцията използва for цикъл, за да обхожда всеки символ от входния низ str,
		//  докато не срещне нулевия терминатор ('\0'), 
		// който бележи края на низа.
	{
		char ch = str[i]; //Променливата ch съхранява текущия символ в низа, на позиция i.
		if (ch==' '||ch=='\t'||ch==','||ch=='.'||ch=='!'||ch=='?'||ch==':'||ch==';')
			//Разделителите са използвани за идентифициране на края на думата.
		{
			if (wordInd>0)//Ако има натрупани символи в масива word (т.е. wordIndex е по-голямо от 0),
							//това означава, че сме събрали дума.
			{
				word[wordInd] = '\0'; // Добавя се нулевият терминатор в края на масива word, 
									//за да се формира валиден низ (дума).
				addWord(word); //Извиканата функция addWord добавя намерената дума в масива от думи
								//или увеличава броя на срещанията ѝ, ако вече съществува.
				wordInd = 0; //След като думата е обработена, wordIndex се нулира, 
							//за да се подготви за следващата дума.
			}
		}
		//Ако текущият символ не е разделител, той се добавя към текущата дума.
		else if (wordInd<MAX_WORD_LENGTH-1)  //Това условие гарантира, че не превишаваме максималната дължина 
								//на думата(MAX_WORD_LENGTH), за да предотвратим излизане извън 
								// границите на масива word.
		{
			word[wordInd] = toLowerCase(ch);//Текущият символ ch се преобразува в малка буква с 
										//помощта на функцията toLowerCase и 
					//след това се добавя към текущата позиция в масива word.
			wordInd++; //Увеличаваме индекса, за да сочим към следващата свободна позиция в масива word.
		}
	}

	// Добавяне на последната дума
	//Това се случва, ако низът не завършва с разделител, а с дума
	if (wordInd>0)
	{
		word[wordInd] = '\0';
		addWord(word);
	}
}

//task 05
const size_t MAX_WORD_LEN = 100;

void copyWord(const char* source, char* dest)
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

bool compareWords1(const char* word1, const char* word2)
{
	if (!word1||!word2)
	{
		return 0;
	}


	while (*word1&&*word2)
	{
		if (*word1<*word2)
		{
			return true;
		}
		else if (*word1>*word2)
		{
			return false;
		}
		word1++;
		word2++;
	}
	return *word1 == '\0' && *word2 != '\0';
}

void toLowerCase(char* word)
{
	if (!word)
	{
		return;
	}
	while (*word)
	{
		if (*word>='A'&&*word<='Z')
		{
			*word = *word + ('a' - 'A');
		}
		word++;
	}
}

const char* getSmallestWord(const char* str)
{
	if (!str)
	{
		return nullptr;
	}

	char* smallestWord=new char[MAX_WORD_LEN];
	smallestWord[0] = '\0';  // Инициализираме с празен низ

	char currentWord[MAX_WORD_LEN];
	int currInd = 0;
	bool isFirstWord = true;

	for (int i = 0; str[i]!=0 ; i++)
	{
		char ch = str[i];
		if (ch==' '||ch=='\t'||ch==','||ch=='.'||ch=='?'||ch=='!'||ch==';'||ch==':')
		{
			if (currInd>0)
			{
				currentWord[currInd] = '\0';
				toLowerCase(currentWord);
				if (isFirstWord||compareWords1(currentWord,smallestWord))
				{
					copyWord(currentWord, smallestWord);
					isFirstWord = false;
				}
				currInd = 0;
			}
		}
		else
		{
			currentWord[currInd] = str[i];
			currInd++;
		}
	}

	if (currInd>0)
	{
		currentWord[currInd] = '\0';
		toLowerCase(currentWord);
		if (isFirstWord||compareWords1(currentWord,smallestWord))
		{
			copyWord(currentWord, smallestWord);
			isFirstWord = false;
		}
	}

	return smallestWord;
}
int main()
{
	/*char str[] = "Iliana";
	std::cout << myStrLen(str) << std::endl;
	unsigned len = myStrLen(str);
	char* str2=new char[len+1];
	myStrCpy(str, str2);
	std::cout << str2<<std::endl;
	char str3[] = "Ilianka";
	std::cout << myStrcmp(str, str3) << std::endl;
	myStrcat(str, str3);
	std::cout << str << std::endl;*/
	//char str[] = "hello, guys";
	//char str2[] = "guys";
	//std::cout << searchInText(str, str2) << std::endl;

	/*unsigned int n = converStringToSigned("123");
	std::cout << n << std::endl;
	
	char str[50];
	int a = 1234;
	toString(a, str);
	std::cout << a << std::endl;*/

	/*char str[] = "Iliana";
	std::cout << countCharOccurances(str, 'a') << std::endl;*/
	//char str[] = "ILIANA";
	///*toUpper(str);*/
	//toLower(str);
	//std::cout << str;

	//task 03
	/*char str[] = "Me? Why always me?";
	std::cout << countWords(str) << std::endl;*/

	//01
	/*char str[] = "I am the worst of the worst";
	char what[] = "best";
	char where[] = "worst";
	replaceInText(str, where, what);
	std::cout << str;*/

	//04
	/*char str[100] = "Me ? Why always me ?";
	processString(str);*/
	/*std::cout << mostFrequentWord();*/

	//05
	const char* str = "Me? Why always me?";
    const char* smallest= getSmallestWord(str);
	std::cout << smallest;
	delete[] smallest;
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
