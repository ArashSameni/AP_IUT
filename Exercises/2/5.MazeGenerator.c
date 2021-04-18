#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

enum move
{
    left,
    up,
    right,
    down
};
char **table;
int rows, cols;

void InitTable()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            table[i][j] = '0';

    for (int i = 0; i < rows; i++)
    {
        table[i][0] = '1';
        table[i][cols - 1] = '1';
    }
    for (int j = 0; j < cols; j++)
    {
        table[0][j] = '1';
        table[rows - 1][j] = '1';
    }
    table[0][1] = 'e';
    table[rows - 1][cols - 2] = 'e';

    for (int i = 1; i < rows; i += 2)
        for (int j = 1; j < cols; j += 2)
            table[i][j] = '*';
}

void PrintMaze()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c", table[i][j]);
        }
        printf("\n");
    }
}

bool isZero(int x, int y)
{
    if (table[x][y] != '0')
        return 0;
    if (x <= 1 || x >= rows - 2 || y <= 1 || y >= cols - 2)
        return 0;
    return 1;
}

bool isOk(int x, int y, int mode)
{
    if (!isZero(x, y))
        return 0;
    if (table[x][y - 1] == '1' && mode != right)
        return 0;
    if (table[x][y + 1] == '1' && mode != left)
        return 0;
    if (table[x + 1][y] == '1' && mode != up)
        return 0;
    if (table[x - 1][y] == '1' && mode != down)
        return 0;
    if (table[x + 1][y + 1] == '1' && mode != left && mode != up)
        return 0;
    if (table[x - 1][y - 1] == '1' && mode != right && mode != down)
        return 0;
    if (table[x + 1][y - 1] == '1' && mode != up && mode != right)
        return 0;
    if (table[x - 1][y + 1] == '1' && mode != left && mode != down)
        return 0;
    return 1;
}

void CreateMaze(int x, int y)
{
    table[x][y] = '1';
    bool left = isOk(x, y - 1, 0);
    bool up = isOk(x - 1, y, 1);
    bool right = isOk(x, y + 1, 2);
    bool down = isOk(x + 1, y, 3);
    while (left || up || right || down)
    {
        int way = rand() % 4;
        while (1)
        {
            if (way == 0 && left)
                break;
            if (way == 1 && up)
                break;
            if (way == 2 && right)
                break;
            if (way == 3 && down)
                break;
            way = rand() % 4;
        }
        if (way == 0)
            CreateMaze(x, y - 1);
        else if (way == 1)
            CreateMaze(x - 1, y);
        else if (way == 2)
            CreateMaze(x, y + 1);
        else
            CreateMaze(x + 1, y);

        left = isOk(x, y - 1, 0);
        up = isOk(x - 1, y, 1);
        right = isOk(x, y + 1, 2);
        down = isOk(x + 1, y, 3);
    }
}

int main()
{
    int m, n, t;
    scanf("%d %d %d", &m, &n, &t);
    srand(time(0));
    rows = 2 * m + 1;
    cols = 2 * n + 1;
    table = (char **)malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++)
        table[i] = (char *)malloc(sizeof(char) * cols);

    for (int i = 0; i < t; i++)
    {
        InitTable();
        int side = rand() % 4;
        if (side == 0 || side == 2)
        {
            int x = 2 * ((rand() % (m - 2)) + 2);
            if (side == 0)
                CreateMaze(x, 1);
            else
                CreateMaze(x, cols - 2);
        }
        else
        {
            int y = 2 * ((rand() % (n - 2)) + 2);
            if (side == 0)
                CreateMaze(1, y);
            else
                CreateMaze(rows - 2, y);
        }
        PrintMaze();
        printf("\n");
    }
    return 0;
}