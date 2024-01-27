#include "stdio.h"
#define N 1

int main()
{
    float matrix[N][N + 1];
    float temp1;
    float temp2;
    float temp3 = 0;
    float answers[N];
    printf("Hi, please enter a matrix:\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            printf("(%d,%d): ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            temp1 = matrix[j][i] / matrix[i][i];
            for (int k = i; k < N + 1; k++)
            {
                matrix[j][k] -= matrix[i][k] * temp1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        answers[i] = 0;
    }

    answers[N - 1] = matrix[N - 1][N] / matrix[N - 1][N - 1];

    for (int i = N - 2; i >= 0; i--)
    {
        temp2 = matrix[i][N];
        temp3 = 0;
        for (int j = i + 1; j < N; j++)
        {
            temp3 += (answers[j] * matrix[i][j]);
        }
        answers[i] = (temp2 - temp3) / matrix[i][i];
    }

    for (int i = 0; i < N; i++)
    {
        printf("X%d: %.2f\t", i, answers[i]);
    }
}