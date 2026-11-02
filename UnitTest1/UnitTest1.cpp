#include "pch.h"
#include "CppUnitTest.h"

// Підключаємо програму, перейменувавши її main.
#define main LabProgramMain
#include "C:/Users/Користува/Desktop/AP/lab_07.1IT/lab_07.1IT/lab_07.1IT.cpp"
#undef main

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestNew
{
    TEST_CLASS(MatrixTests)
    {
    public:

        TEST_METHOD(TestCalculate)
        {
            int T[ROWS][COLS] = {
                { -10, 0, 5, 7, 10, 51 },
                { -10, 0, 5, 7, 10, 51 },
                { -10, 0, 5, 7, 10, 51 },
                { -10, 0, 5, 7, 10, 51 },
                { -10, 0, 5, 7, 10, 51 },
                { -10, 0, 5, 7, 10, 51 },
                { -10, 0, 5, 7, 10, 51 }
            };

            int count = -1;
            int sum = -1;

            Calculate(T, count, sum);

            Assert::AreEqual(28, count);
            Assert::AreEqual(336, sum);

            const int expected[COLS] = { 0, 0, 5, 0, 10, 0 };

            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    Assert::AreEqual(expected[j], T[i][j]);
        }

        TEST_METHOD(TestPositiveMultiplesOfFive)
        {
            int T[ROWS][COLS];

            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    T[i][j] = 5;

            int count = -1;
            int sum = -1;

            Calculate(T, count, sum);

            Assert::AreEqual(0, count);
            Assert::AreEqual(0, sum);

            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    Assert::AreEqual(5, T[i][j]);
        }

        TEST_METHOD(TestSort)
        {
            int T[ROWS][COLS] = {
                { 2, 1, 9, 11, 12, 13 },
                { 1, 8, 4, 21, 22, 23 },
                { 1, 9, 7, 31, 32, 33 },
                { 1, 9, 2, 41, 42, 43 },
                { 3, 0, 0, 45, 46, 47 },
                { -1, 0, 0, 51, 50, 49 },
                { 2, 3, 1, 48, 47, 46 }
            };

            const int expected[ROWS][COLS] = {
                { -1, 0, 0, 51, 50, 49 },
                { 1, 9, 2, 41, 42, 43 },
                { 1, 9, 7, 31, 32, 33 },
                { 1, 8, 4, 21, 22, 23 },
                { 2, 3, 1, 48, 47, 46 },
                { 2, 1, 9, 11, 12, 13 },
                { 3, 0, 0, 45, 46, 47 }
            };

            Sort(T);

            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    Assert::AreEqual(expected[i][j], T[i][j]);
        }
    };
}