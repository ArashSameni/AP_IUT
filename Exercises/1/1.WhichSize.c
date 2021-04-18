#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2;
    scanf("%d", &n1);
    if (n1 <= 0)
        return 0;

    int *arr = (int *)malloc(sizeof(int) * n1);
    int i;
    for (i = 0; i < n1; i++)
        *(arr + i) = 100;

    scanf("%d", &n2);
    if (n2 <= 0)
        return 0;

    arr = realloc(arr, sizeof(int) * n2);
    if (n2 > n1)
        for (int j = 0; j < n2 - n1; j++)
            *(arr + i + j) = 0;

    for (int i = 0; i < n2; i++)
        printf("%d ", *(arr + i));
    free(arr);
    return 0;
}