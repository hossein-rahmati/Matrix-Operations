#include "stdio.h"
#define N 3

int main()
{
    float matrix[N][N + N];
    float temp;
    printf("Hi, please enter a matrix:\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("(%d,%d): ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = N; j < N + N; j++)
        {
            matrix[i][j] = 0;
        }
        matrix[i][i + N] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            temp = matrix[j][i] / matrix[i][i];
            for (int k = i; k < N + N; k++)
            {
                matrix[j][k] -= matrix[i][k] * temp;
            }
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            temp = matrix[j][i] / matrix[i][i];
            for (int k = i; k < N + N; k++)
            {
                matrix[j][k] -= matrix[i][k] * temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N + N; j++)
        {
            matrix[i][j] /= matrix[i][i];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = N; j < N + N; j++)
        {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
}