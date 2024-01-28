#include "stdio.h"
#define N 3

void swapLines(float matrix[N][N])
{
    float temp2;

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp2 = matrix[i + 1][j];
            matrix[i + 1][j] = matrix[i][j];
            matrix[i][j] = temp2;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

float main()
{
    float matrix[N][N];
    float temp;
    float determinant = 1;
    printf("Hi, please enter a matrix:\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("(%d,%d): ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    if (matrix[0][0] == 0)
    {
        swapLines(matrix);
        determinant *= -1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            temp = matrix[j][i] / matrix[i][i];
            for (int k = i; k < N; k++)
            {
                matrix[j][k] -= matrix[i][k] * temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        determinant *= matrix[i][i];
    }

    printf("Determinant is: %3.f", determinant);
}
