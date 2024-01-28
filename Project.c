#include "stdio.h"

void swapLines(int N, float matrix[N][N])
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
}
void Determinant()
{
    int order;
    printf("Enter order of matrix: ");
    scanf("%d", &order);
    float matrix[order][order];
    float temp;
    float determinant = 1;
    printf("Hi, please enter a matrix:\n");

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            printf("(%d,%d): ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    if (matrix[0][0] == 0)
    {
        swapLines(order, matrix);
        determinant *= -1;
    }

    for (int i = 0; i < order; i++)
    {
        for (int j = i + 1; j < order; j++)
        {
            temp = matrix[j][i] / matrix[i][i];
            for (int k = i; k < order; k++)
            {
                matrix[j][k] -= matrix[i][k] * temp;
            }
        }
    }

    for (int i = 0; i < order; i++)
    {
        determinant *= matrix[i][i];
    }

    printf("Determinant is: %3.f", determinant);
}
void Inverse()
{
    int order;
    printf("Enter order of matrix: ");
    scanf("%d", &order);
    float matrix[order][order + order];
    float temp;
    printf("Hi, please enter a matrix:\n");

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            printf("(%d,%d): ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    for (int i = 0; i < order; i++)
    {
        for (int j = order; j < order + order; j++)
        {
            matrix[i][j] = 0;
        }
        matrix[i][i + order] = 1;
    }

    for (int i = 0; i < order; i++)
    {
        for (int j = i + 1; j < order; j++)
        {
            temp = matrix[j][i] / matrix[i][i];
            for (int k = i; k < order + order; k++)
            {
                matrix[j][k] -= matrix[i][k] * temp;
            }
        }
    }

    for (int i = order - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            temp = matrix[j][i] / matrix[i][i];
            for (int k = i; k < order + order; k++)
            {
                matrix[j][k] -= matrix[i][k] * temp;
            }
        }
    }

    for (int i = 0; i < order; i++)
    {
        for (int j = i + 1; j < order + order; j++)
        {
            matrix[i][j] /= matrix[i][i];
        }
    }

    for (int i = 0; i < order; i++)
    {
        for (int j = order; j < order + order; j++)
        {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
}
void SystemOfLinearEquations()
{
    int order;
    printf("Enter order of matrix: ");
    scanf("%d", &order);
    float matrix[order][order + 1];
    float temp1;
    float temp2;
    float temp3 = 0;
    float answers[order];
    printf("Hi, please enter a matrix:\n");

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order + 1; j++)
        {
            printf("(%d,%d): ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    for (int i = 0; i < order; i++)
    {
        for (int j = i + 1; j < order; j++)
        {
            temp1 = matrix[j][i] / matrix[i][i];
            for (int k = i; k < order + 1; k++)
            {
                matrix[j][k] -= matrix[i][k] * temp1;
            }
        }
    }

    for (int i = 0; i < order; i++)
    {
        answers[i] = 0;
    }

    answers[order - 1] = matrix[order - 1][order] / matrix[order - 1][order - 1];

    for (int i = order - 2; i >= 0; i--)
    {
        temp2 = matrix[i][order];
        temp3 = 0;
        for (int j = i + 1; j < order; j++)
        {
            temp3 += (answers[j] * matrix[i][j]);
        }
        answers[i] = (temp2 - temp3) / matrix[i][i];
    }

    for (int i = 0; i < order; i++)
    {
        printf("X%d: %.2f\t", i, answers[i]);
    }
}

int main()
{
    int operation;
    printf("\nHi\n\n-Determinant (1)\n-System of linear equations (2)\n-Inverse (3)\n\nEnter a number to continue to matrix operations: ");
    scanf("%d", &operation);

    switch (operation)
    {
    case 1:
        Determinant();
        break;
    case 2:
        SystemOfLinearEquations();
        break;
    case 3:
        Inverse();
        break;
    default:
        break;
    }
}