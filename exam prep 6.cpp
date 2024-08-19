// exam prep 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//int max(int num1, int num2)
//{
//    return (num1 > num2) ? num1 : num2;
//}
//
//int maxSequence(int** matrix, int row, int col, int rows, int prev)
//{
//    if (row < 0 || row >= rows || col < 1 || col > matrix[row][0] || matrix[row][col] <= prev)
//    {
//        return 0;
//    }
//
//    int current = matrix[row][col];
//    int res = 1;
//
//    // Рекурсивно извикване за всичките осем възможни посоки
//    res = max(res, 1 + maxSequence(matrix, row + 1, col, rows, current));
//    res = max(res, 1 + maxSequence(matrix, row - 1, col, rows, current));
//    res = max(res, 1 + maxSequence(matrix, row, col + 1, rows, current));
//    res = max(res, 1 + maxSequence(matrix, row, col - 1, rows, current));
//    res = max(res, 1 + maxSequence(matrix, row - 1, col - 1, rows, current));
//    res = max(res, 1 + maxSequence(matrix, row + 1, col + 1, rows, current));
//    res = max(res, 1 + maxSequence(matrix, row - 1, col + 1, rows, current));
//    res = max(res, 1 + maxSequence(matrix, row + 1, col - 1, rows, current));
//
//    return res;
//}
//
//int getLongestIncreasingSequence(int** matrix, int rows)
//{
//    int maxCount = 0;
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 1; j <= matrix[i][0]; j++)
//        {
//            int currentCount = maxSequence(matrix, i, j, rows, -1);
//            maxCount = max(maxCount, currentCount);
//        }
//    }
//    return maxCount;
//}

//int** createMatrix(int rows)
//{
//    int** matrix = new int* [rows];
//    for (int i = 0; i < rows; i++)
//    {
//        int M;
//        cin >> M;
//        matrix[i] = new int[M + 1];
//        matrix[i][0] = M;  // Първият елемент на всеки ред съдържа броя на колоните
//        for (int j = 1; j <= M; j++)
//        {
//            cin >> matrix[i][j];
//        }
//    }
//    return matrix;
//}
//
//void freeMatrix(int** matrix, int rows)
//{
//    for (int i = 0; i < rows; i++)
//    {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//}



//void createMatrix(int** matrix, int rowsCount, int* cols)
//{
//    for (int i = 0; i < rowsCount; i++) {
//        int colsCount;
//        //std::cout << "Enter the number of elements in row " << i + 1 << ": ";
//        std::cin >> colsCount;
//
//        cols[i] = colsCount;
//        matrix[i] = new int[colsCount];
//
//        //std::cout << "Enter the elements of the row " << i + 1 << ": ";
//        for (int j = 0; j < colsCount; j++) {
//            std::cin >> matrix[i][j];
//        }
//    }
//}



int** createMatrix(int rowsCount, int*& cols)
{
    int** mtx = new int* [rowsCount];
    cols = new int[rowsCount];
    for (int i = 0; i < rowsCount; i++)
    {
        int colsCount;
        std::cin >> colsCount;
        cols[i] = colsCount;
        mtx[i] = new int[colsCount];
        for (int j = 0; j < colsCount; j++)
        {
            std::cin >> mtx[i][j];
        }
    }
    return mtx;
}

void freeMatrix(int** mtx, int rowsCount)
{
    for (int i = 0; i < rowsCount; i++)
    {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int myMax(int a, int b)
{
    return a > b ? a : b;
}

int getLongestIncreasingSequance(int** mtx, int currRow, int currCol, int rows, int* cols)
{
    if (currRow<0||currRow>rows-1||currCol<0||currCol>cols[currRow]-1)
    {
        return 0;
    }

    int currLength = 1;

    int up = (currRow > 0 && mtx[currRow][currCol] < mtx[currRow - 1][currCol]) ?
       1 + getLongestIncreasingSequance(mtx, currRow - 1, currCol, rows, cols) : 0;
    int down = (currRow < rows - 1 && mtx[currRow][currCol] < mtx[currRow + 1][currCol]) ?
       1 + getLongestIncreasingSequance(mtx, currRow + 1, currCol, rows, cols) : 0;
    int right = (currCol > 0 && mtx[currRow][currCol] < mtx[currRow][currCol - 1]) ?
       1 + getLongestIncreasingSequance(mtx, currRow, currCol - 1, rows, cols) : 0;
    int left = (currCol < cols[currRow] - 1 && mtx[currRow][currCol] < mtx[currRow][currCol + 1]) ?
       1 + getLongestIncreasingSequance(mtx, currRow, currCol + 1, rows, cols) : 0;
    int upRight = (currRow > 0 && currCol > 0 && mtx[currRow][currCol] < mtx[currRow - 1][currCol - 1]) ?
       1 + getLongestIncreasingSequance(mtx, currRow - 1, currCol - 1, rows, cols) : 0;
    int downRight = (currRow < rows - 1 && currCol>0 && mtx[currRow][currCol] < mtx[currRow + 1][currCol - 1]) ?
       1 + getLongestIncreasingSequance(mtx, currRow + 1, currCol - 1, rows, cols) : 0;
    int upLeft = (currRow > 0 && currCol < cols[currRow] - 1 && mtx[currRow][currCol] < mtx[currRow - 1][currCol + 1]) ?
       1 + getLongestIncreasingSequance(mtx, currRow - 1, currCol + 1, rows, cols) : 0;
    int downLeft = (currRow < rows - 1 && currCol < cols[currRow] - 1 && mtx[currRow][currRow] < mtx[currRow + 1][currCol + 1]) ?
       1 + getLongestIncreasingSequance(mtx, currRow + 1, currCol + 1, rows, cols) : 0;

    return myMax(downLeft, myMax(upLeft, myMax(downRight, myMax(upRight, myMax(left, myMax(right, myMax(down, myMax(currLength, up))))))));
}

int findLongestIncreasingInMatrix(int** mtx, int rows, int* cols)
{
    int max = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols[i]; j++)
        {
            max = myMax(max,getLongestIncreasingSequance(mtx, i, j, rows, cols));
        }
    }
    return max;
}

void printMatrix(int** mtx, int rows, int* colls)
{
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < colls[i]; j++)
        {
            std::cout << mtx[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


//exam task 02
void freeVisited(bool** visited, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;
}
bool searchInText(const char* const* grid, size_t M, size_t N, const char* word, int currRow, int currCol, int index, bool** visited)
{
    if (index == strlen(word))
    {
        return true;
    }
    if (currRow<0 || currRow>M - 1 || currCol<0 || currCol>N - 1 || grid[currRow][currCol] != word[index] || visited[currRow][currCol])
    {
        return false;
    }

    visited[currRow][currCol] = true;

    bool found = searchInText(grid, M, N, word, currRow + 1, currCol, index + 1, visited) ||
        searchInText(grid, M, N, word, currRow - 1, currCol, index + 1, visited) ||
        searchInText(grid, M, N, word, currRow, currCol - 1, index + 1, visited) ||
        searchInText(grid, M, N, word, currRow, currCol + 1, index + 1, visited);
    visited[currRow][currCol] = false;
    return found;
}
bool findWord(const char* const* grid, size_t M, size_t N, const char* word)
{
    bool** visited = new bool* [M];
    for (int i = 0; i < M; i++)
    {
        visited[i] = new bool[N];
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (searchInText(grid,M,N,word,i,j,0,visited))
            {
                freeVisited(visited, M);
                return true;
            }
        }
    }

    freeVisited(visited, M);
    return false;
}

//exam 2021/2022
//task 01
bool hasEvenDigits(long num)
{
    if (num==0)
    {
        return true;
    }

    int countEven = 0;
    while (num!=0)
    {
        int lastDigit = num % 10;
        if (lastDigit%2==0)
        {
            countEven++;
        }
        num /= 10;
    }

    return countEven > 0;
}

long reverse(long num)
{
    if (num==0)
    {
        return 0;
    }

    long rev = 0;
    while (num!=0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }

    return rev;
}

long newNum(long num)
{
    if (!hasEvenDigits(num))
    {
        return -1;
    }
    if (num==0)
    {
        return 0;
    }

    int newNum = 0;
    int mult = 1;
    while (num!=0)
    {
        int lastDig = num % 10;
        if (lastDig%2==0)
        {
           /* newNum = newNum * 10 + lastDig;*/
            newNum += lastDig * mult;
            mult *= 10;
        }
        num /= 10;
    }
    return newNum;
}

//task 02
void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int countEvenDigits(long num)
{
    if (num==0)
    {
        return 1;
    }
    int count = 0;
    while (num!=0)
    {
        int lastDig = num % 10;
        if (lastDig%2==0)
        {
            count++;
        }
        num /= 10;
    }
    return num;
}

int countDigInNum(long num)
{
    if (num==0)
    {
        return 1;
    }

    int count = 0;
    while (num!=0)
    {
        count++;
        num /= 10;
    }
    return count;
}

int* convertNum(long num, int k, int m)
{
    int len = countDigInNum(num);
    if (k>len||m>len || k<=0||m<=0)
    {
        return nullptr;
    }
    int* arr = new int[len];
    for (int i = len - 1; i >= 0; i--)
    {
        arr[i] = num % 10;
        num /= 10;
    }

    swap(arr[k-1], arr[m-1]);
    return arr;
}

void printArr(const int* arr, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << ' ';
    }
}

//task 03
int countEvenDigits(const int* arr, int len)
{

    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i]%2==0)
        {
            count++;
        }
    }

    return count;
}

int getAverageOfArray(const int* arr, int len)
{
    
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }

    int avg = sum / len;
    return len > 0 ? avg : 0;
}

int* newArr(const int* arr, int len)
{
    if (!arr)
    {
        return nullptr;
    }

    int len1 = countEvenDigits(arr, len);
    if (len1<=0)
    {
        return nullptr;
    }

    int* newArr = new int[len1];
    int ind = 0;
    int avg = getAverageOfArray(arr, len);
    for (int i = 0; i < len; i++)
    {
        if (arr[i]%2==0)
        {
            newArr[ind] = arr[i] + avg;
            ind++;
        }
        /*if (ind==len1)
        {
            break;
        }*/
    }

    return newArr;
}

//04
bool isThereAGreaterNum(const int* arr1, const int* arr2, int len, int index)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr1[index]>=arr2[i])
        {
            count++;
        }
    }

    if (count==len)
    {
        return false;
    }
    return true;
}

int* mergeArr(const int* arr1, const int* arr2, int len)
{
    if (!arr1||!arr2)
    {
        return nullptr;
    }

    int* res = new int[len];
    int ind = 0;
    int arr1Ind = 0;
    int arr2Ind = 0;

    while (arr1Ind<len)
    {
        if (!isThereAGreaterNum(arr1,arr2,len,arr1Ind))
        {
            res[ind] = -1;
            ind++;
            arr1Ind++;
        }
        else if (arr2[arr2Ind]>arr1[arr1Ind])
        {
            res[ind] = arr2Ind;
            ind++;
            arr1Ind++;
            arr2Ind = 0;
        }
        else
        {
            arr2Ind++;
        }
    }

    //for (int i = 0; i < len; i++)
    //{
    //    res[i] = -1; // По подразбиране, ако няма по-голямо число, стойността е -1
    //    for (int j = 0; j < len; j++) {
    //        if (arr2[j] > arr1[i]) {
    //            res[i] = j;
    //            break; // Намерено е първото по-голямо число, прекъсваме вътрешния цикъл
    //        }
    //    }
    //}
    return res;
}

//task 05
int** splitArr(const int* arr, int M)
{
    if (!arr)
    {
        return nullptr;
    }

    int** res = new int* [M];
    for (int i = 0; i < M; i++)
    {
        res[i] = new int[2];
    }

    int avg = getAverageOfArray(arr, M);

    for (int i = 0; i < M; i++)
    {
        res[i][0] = arr[i];
        res[i][1] = avg;
    }

    return res;
}

void printMatrix(int** res, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        std::cout << "{ ";
        for (int j = 0; j < cols; j++)
        {
            std::cout << res[i][j];
            if (j<cols-1)
            {
                std::cout << ", ";
            }
        }
        std::cout << " }";
        if (i<rows-1)
        {
            std::cout << ", ";
        }
    }
}

void free(int** mtx, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] mtx[i];
    }
    delete[] mtx;
}

//06
int* revArr(int* arr, int len, int k)
{
    if (!arr || k > len || k < 1)
    {
        return nullptr;
    }

    int* res = new int[len];

    int resInd = 0;
    for (int i = len-1; i >= k-1 ; i--)
    {
        res[resInd] = arr[i];
        resInd++;
    }
    for (int i = 0; i < k-1 ; i++)
    {
        res[resInd] = arr[i];
        resInd++;
    }
    return res;
}
int main()
{
    //hw.2 task 04
   /* int rowsCount;
    std::cin >> rowsCount;

    int* cols = nullptr;
    int** mtx = createMatrix(rowsCount, cols);
    printMatrix(mtx, rowsCount, cols);
    std::cout << std::endl;

    std::cout << findLongestIncreasingInMatrix(mtx, rowsCount, cols);
    freeMatrix(mtx, rowsCount);
    delete[] cols;*/

    //exam task 02
    /*const size_t M = 4, N = 4;
    const char* str1 = "abcd";
    const char* str2 = "efgh";
    const char* str3 = "ijkl";
    const char* str4 = "mnop";
    const char* grid[] =
    {
        str1,
        str2,
        str3,
        str4
    };

    const char* word = "bcgfjkl";
    std::cout << findWord(grid, M, N, word);*/

    //01
    /*std::cout << newNum(1234567809);*/

    //02
    /*int* arr = convertNum(123456789, 0, 5);
    printArr(arr, 9);
    delete[] arr;*/

    //03
    /*int arr[8] = { 1,2,3,4,5,6,7,8 };
    int* res = newArr(arr, 8);
    printArr(res, 4);*/

    //04
  /*  int arr1[7] = { 22, 5, 17, 8, 90, 7, 12 };
    int arr2[7] = { 6, 9, 18, 7, 1, 2, 3 };
    int* res = mergeArr(arr1, arr2, 7);
    printArr(res, 7);
    delete[] res;*/

    //05
   /* int arr[8] = { 1, 7, 4, 11, 23, 15, 12, 21 };
    int** res = splitArr(arr, 8);
    printMatrix(res, 8, 2);
    freeMatrix(res, 8);*/

    //06
    int arr[8] = { 1,2,3,4,5,6,7,8 };
    int* res=revArr(arr, 8, 3);
    printArr(res, 8);
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
