#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void init(int *i, int *fileNumber)
{
    FILE *fptr = fopen("number.txt", "r+");
    if (fptr)
    {
        fscanf(fptr, "%d", i);
        fseek(fptr, 0, SEEK_SET);
        fprintf(fptr, "%d", *i + 1);
    }
    else
    {
        fptr = fopen("number.txt", "w");
        fprintf(fptr, "%d", 2);
    }
    fclose(fptr);

    fptr = fopen("file.txt", "r");
    char line[255];
    int lineNumber = 0;
    while (fgets(line, 255, fptr))
    {
        lineNumber++;
        if (lineNumber == *i)
        {
            sscanf(line, "%d", fileNumber);
            break;
        }
    }
    fclose(fptr);
}

long gcd(long a, long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

long lcm(long a, long b)
{
    return (a / gcd(a, b)) * b;
}

long lcmOfArray(int *arr, int count)
{
    long tmp = arr[0];
    for (int i = 1; i < count; i++)
        tmp = lcm(tmp, arr[i]);
    return tmp;
}

int isNumber(char *str)
{
    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

int main(int argc, char **argv)
{
    int i = 1;
    int fileNumber = 0;
    init(&i, &fileNumber);

    int stringsCount = 0;
    int *stringsLength = NULL;

    int numbersCount = 0;
    int *numbers = NULL;
    for (int i = 1; i < argc; i++)
    {
        if (isNumber(argv[i]))
        {
            int tmp = 0;
            sscanf(argv[i], "%d", &tmp);

            numbersCount++;
            if (!numbers)
                numbers = (int *)malloc(sizeof(int));
            else
                numbers = (int *)realloc(numbers, sizeof(int) * numbersCount);

            numbers[numbersCount - 1] = tmp;
        }
        else
        {
            stringsCount++;
            if (!stringsLength)
                stringsLength = (int *)malloc(sizeof(int));
            else
                stringsLength = (int *)realloc(stringsLength, sizeof(int) * stringsCount);

            stringsLength[stringsCount - 1] = strlen(argv[i]);
        }
    }

    FILE *fptr = fopen("9920693.txt", "a");
    fprintf(fptr, "%d\n", stringsCount);
    for (int i = 0; i < stringsCount; i++)
        fprintf(fptr, "%d\n", stringsLength[i]);
    if (numbersCount == 1)
        fprintf(fptr, "none\n");
    else
    {
        long lcm = lcmOfArray(numbers, numbersCount);
        fprintf(fptr, "%d\n", lcm + fileNumber);
    }
    fprintf(fptr, "----------------------\n");
    free(stringsLength);
    free(numbers);
    fclose(fptr);
    return 0;
}