#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 7;
const int COLS = 6;

// Створення матриці
void Create(int T[][COLS])
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            T[i][j] = -42 + rand() % 94;
}

// Виведення матриці
void Print(int T[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            cout << setw(5) << T[i][j];
        cout << endl;
    }
    cout << endl;
}

// Копіювання матриці
void Copy(int A[][COLS], int B[][COLS])
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            B[i][j] = A[i][j];
}

// Підрахунок кількості, суми та заміна нулями
void Calculate(int T[][COLS], int& count, int& sum)
{
    count = 0;
    sum = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (!(T[i][j] > 0 && T[i][j] % 5 == 0))
            {
                count++;
                sum += T[i][j];
                T[i][j] = 0;
            }
        }
    }
}

// Перевірка порядку двох рядків
bool NeedSwap(int T[][COLS], int i, int j)
{
    if (T[i][0] > T[j][0])
        return true;

    if (T[i][0] == T[j][0] &&
        T[i][1] < T[j][1])
        return true;

    if (T[i][0] == T[j][0] &&
        T[i][1] == T[j][1] &&
        T[i][2] > T[j][2])
        return true;

    return false;
}

// Сортування рядків
void Sort(int T[][COLS])
{
    for (int i = 0; i < ROWS - 1; i++)
    {
        for (int j = i + 1; j < ROWS; j++)
        {
            if (NeedSwap(T, i, j))
            {
                for (int k = 0; k < COLS; k++)
                {
                    int temp = T[i][k];
                    T[i][k] = T[j][k];
                    T[j][k] = temp;
                }
            }
        }
    }
}

int main()
{
    srand((unsigned)time(0));

    int T[ROWS][COLS];
    int A[ROWS][COLS];
    int B[ROWS][COLS];
    int count, sum;

    Create(T);
    Copy(T, A);
    Copy(T, B);

    cout << "Original matrix:" << endl;
    Print(T);

    Calculate(A, count, sum);

    cout << "Count = " << count << endl;
    cout << "Sum = " << sum << endl;
    cout << "Matrix after replacement:" << endl;
    Print(A);

    Sort(B);

    cout << "Sorted matrix:" << endl;
    Print(B);

    return 0;
}

