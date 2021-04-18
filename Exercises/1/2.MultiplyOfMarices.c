#include <stdio.h>
#include <stdlib.h>

void CreateMatrix(int*** matrix, int n, int m)
{
    *matrix = (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++)
        *(*matrix + i) = (int*)malloc(sizeof(int) * m);
}

void FillMatrix(int*** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", *(*matrix + i) + j);
}

void PrintMatrix(int*** matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", *(*(*matrix + i) + j));
        }
        printf("\n");
    }
}

int main()
{
    int n1, m1, n2, m2;
    scanf("%d %d %d", &n1, &m1, &m2);
    n2 = m1;
    int** Mat1, ** Mat2;
    CreateMatrix(&Mat1, n1, m1);
    CreateMatrix(&Mat2, n2, m2);
    FillMatrix(&Mat1, n1, m1);
    FillMatrix(&Mat2, n2, m2);

    int** Result;
    CreateMatrix(&Result, n1, m2);
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            int sum = 0;
            for (int k = 0; k < m1; k++)
            {
                sum += *((*(Mat1 + i)) + k) * *((*(Mat2 + k)) + j);
            }
            *((*(Result + i)) + j) = sum;
        }
    }
    PrintMatrix(&Result, n1, m2);
    for (int i = 0; i < n1; i++)
        free(*(Mat1 + i));
    for (int i = 0; i < n2; i++)
        free(*(Mat2 + i));
    free(Mat1);
    free(Mat2);
    free(Result);
    return 0;
}