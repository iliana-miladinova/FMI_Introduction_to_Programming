
// exam prep 10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//task 01
//Замяна на думи в низ
//Да се напише функция на C++, със сигнатура 
// char* replaceWord(char* str, const char* oldWord, const char* newWord), 
// която замества всяко срещане на дума oldWord с newWord в подадения символен низ str.
// Ако старата дума не се среща в низа, да връща оригиналния низ непроменен.
//
//Пример:
//
//Вход: "This is a test string.", "test", "final"
//Изход : "This is a final string."

unsigned countWordRepetitions(const char* str, const char* word)
{
    if (!str||!word)
    {
        return 0;
    }
    int wordInd = 0;
    int wordLen = strlen(word);
    int count = 0;
    bool hasOtherLettersBeforeWord = false;
    for (int i = 0; str[i]!='\0'; i++)
    {
        char ch = str[i];
        if (ch==' '||ch=='\t')
        {
            if (wordInd>0 && hasOtherLettersBeforeWord==false)
            {
                if (wordInd == wordLen)
                {
                    count++;
                }
                wordInd = 0;
            }
            hasOtherLettersBeforeWord = false;
        }
        else
        {
            if (ch==word[wordInd])
            {
                wordInd++;
            }
            else if (ch != word[wordInd])
            {
                hasOtherLettersBeforeWord = true;
                wordInd = 0;
            }
           
        }
    }
    if (wordInd==wordLen&&hasOtherLettersBeforeWord==false)
    {
        count++;
    }
    return count;
}

int countSymbolsInWord(const char* str, int wordInd)
{
    int count = 0;
    int wordLen = 0;
    for (int i = 0; str[i]!=0; i++)
    {
        char ch = str[i];
        if (ch==' '||ch=='\t')
        {
            if (wordLen > 0)
            {
                if (count == wordInd)
                {
                    return wordLen;
                }
                count++;//zashtoto indeksite na dumata zapochavat ot 0
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
        if (count==wordInd)
        {
            return wordLen;
        }
    }
    return 0;
}

int countWordsInStr(const char* str)
{
    int count = 0;
    int wordInd = 0;
    for (int i = 0; str[i]!='\0'; i++)
    {
        char ch = str[i];
        if (ch==' '||ch=='\t')
        {
            if (wordInd>0)
            {
                count++;
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
        count++;
    }
    return count;
}
char** createWordMatrix(const char* str)
{
    int wordsCount = countWordsInStr(str);
    char** words = new char* [wordsCount];
    int wordInd = 0;
    for (int i = 0; i < wordsCount; i++)
    {
        int symbolsCountInWord = countSymbolsInWord(str, i);
        words[i] = new char[symbolsCountInWord + 1];
    }

    int lenInd = 0;
    for (int i = 0; str[i]!='\0'; i++)
    {
        int ch = str[i];
        if (ch==' '||ch=='\t')
        {
            if (lenInd>0)
            {
                words[wordInd][lenInd] = '\0';
                lenInd = 0;
                wordInd++;
            }
        }
        else
        {
            words[wordInd][lenInd] = ch;
            lenInd++;
        }
    }
    if (lenInd>0)
    {
        words[wordInd][lenInd] = '\0';
    }
    return words;
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
char* replaceWord(const char* str, const char* oldWord, const char* newWord)
{
    if (!str||!oldWord||!newWord)
    {
        return nullptr;
    }

    int ogLen = strlen(str);
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);
    int oldWordRepetitions = countWordRepetitions(str, oldWord);
    /*int resLen = (ogLen - oldWordRepetitions * oldWordLen) + oldWordRepetitions * newWordLen;
    char* res = new char[resLen + 1];
    int resInd = 0;*/
    char** words = createWordMatrix(str);
    int wordsCount = countWordsInStr(str);
    int newSize = 0;
    for (size_t i = 0; i < wordsCount ; i++)
    {
        if (myStrcmp(words[i], oldWord) == 0)
        {
            newSize += newWordLen;
        }
        else
        {
            newSize += strlen(words[i]);
        }
        newSize += 1;
    }

    char* result = new char[newSize + 1];
    char* p = result;
    for (int i = 0; i < wordsCount; ++i) {
        if (myStrcmp(words[i], oldWord) == 0) {
            myStrcpy(newWord, p);
            p += newWordLen;
        }
        else {
            myStrcpy(words[i], p);
            p += strlen(words[i]);
        }
        *p++ = ' ';
    }

    if (p != result) {
        *(p - 1) = '\0'; // Замяна на последното пространство с нулев символ
    }
    else {
        *p = '\0'; // Празен входен низ
    }


  
    for (int i = 0; i < wordsCount; ++i) {
        delete[] words[i];
    }
    delete[] words;
    return result;
}

//Задача 2: Генериране на поднизове
//Да се напише функция на C++, със сигнатура char** generateSubstrings(const char* str, size_t k), 
// която генерира всички поднизове с дължина k от подадения низ str.Функцията да връща масив от поднизове, 
// а ако няма възможни поднизове с тази дължина, да връща NULL.

//Пример:
//
//Вход: "example", 3
//Изход : { "exa", "xam", "amp", "mpl", "ple" }

char** generateSubstrings(const char* str, size_t k)
{
    if (!str)
    {
        return nullptr;
    }
    int len = strlen(str);
    if (len < k)
    {
        return nullptr;
    }

    int substringsLen = len - k + 1;
    char** substrings = new char* [substringsLen];
    for (int i = 0; i < substringsLen; i++)
    {
        substrings[i] = new char[k + 1];

        for (int j = 0; j < k; j++)
        {
            substrings[i][j] = str[i + j];
        }
        substrings[i][k] = '\0';
    }
    return substrings;
}

void print(char** mtx, size_t rows)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << mtx[i] << ' ';
    }
}

//task 03
//Най - дълга дума без повтарящи се букви
//Да се напише функция на C++, със сигнатура int longestUniqueWord(const char* str), 
// която намира най - дългата дума в подадения низ, която не съдържа повтарящи се букви.
// Функцията да връща дължината на тази дума.
//
//Пример:
//
//Вход: "This is an example"
//Изход : 7 (за "example")

bool doesItHaveReapetingSymbols(const char* word, int len)
{
    if (!word)
    {
        return false;
    }

    bool alreadySeen[256]{ 0 };
    for (int i = 0; i<len; i++)
    {
        unsigned char ch = word[i];
        if (alreadySeen[ch])
        {
            return true;
        }
        alreadySeen[ch] = true;
    }
    return false;
}

int longestUniqueWord(const char* str)
{
    if (!str)
    {
        return 0;
    }

    int currentLen = 0;
    int maxLen = 0;

   const char* wordstart = str;//ukazatel kym nachaloto na duma
   /* int wordsCount = countWordsInStr(str);
    char** words = createWordMatrix(str);

    for (int i = 0; i < wordsCount; i++)
    {
        int wordLen = countSymbolsInWord(str, i);
        if (doesItHaveReapetingSymbols(words[i],wordLen))
        {
            if (wordLen>maxLen)
            {
                maxLen = wordLen;
            }
        }
    }
    return maxLen;*/
    while (*str)
    {
        char ch = *str;
        if (ch==' '||ch=='\t')
        {
            if (currentLen > 0)
            {
                if (!doesItHaveReapetingSymbols(wordstart,currentLen))
                {
                    if (currentLen>maxLen)
                    {
                        maxLen = currentLen;
                    }
                }
                currentLen = 0;
            }
            wordstart = str + 1;
           
        }
        else
        {
            currentLen++;
        }
        str++;
    }
    if (currentLen>0)
    {
        if (!doesItHaveReapetingSymbols(wordstart,currentLen))
        {
            if (currentLen>maxLen)
            {
                maxLen = currentLen;
            }
        }
    }
    return maxLen;
}

int main()
{
    //seminar 3
    //task 17
    /*int n;
    std::cin >> n;
    int max = 0;
    int secondMax = 0;
    do
    {
        int a;
        std::cin >> a;
        if (a>max)
        {
            secondMax = max;
            max = a;
        }
        else if (a>secondMax)
        {
            secondMax = a;
        }
        n--;
    } while (n!=0);
    std::cout << max << ' ' << secondMax;*/

    //task 01
   /* std::cout << replaceWord("This test is the test for the test", "test","examination");*/

    //task 02
  /*  char** substrings = generateSubstrings("example", 3);
    print(substrings, 5);*/

    //task 03
    /*std::cout << doesItHaveReapetingSymbols("pretty",6);*/
    std::cout << longestUniqueWord("This is an example");
    
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
