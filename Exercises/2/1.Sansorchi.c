#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char* shiftRight(char* text, int count) {
    int len = strlen(text);
    char* ptr = text + len - 1;
    for (int i = 0; i < len; i++)
    {
        ptr[count] = *ptr;
        ptr--;
    }
    text[len + count] = '\0';
    return text;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char** blocks = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
        blocks[i] = (char*)malloc(sizeof(char) * MAX);

    char blockLine[MAX];
    scanf("%s", blockLine);
    getchar();

    char* result = (char*)malloc(sizeof(char) * MAX);
    fgets(result, MAX, stdin);
    result[strlen(result) - 1] = ' ';
    result = (char*)realloc(result, strlen(result) + 1);

    char* ptr = blockLine;
    int pos = 0;
    int charCount = 0;
    while (*ptr) {
        charCount++;
        if (*ptr == ',')
        {
            strncpy(blocks[pos], blockLine, charCount - 1);
            blocks[pos][charCount - 1] = '\0';
            strcpy(blockLine, ptr + 1);
            blocks[pos] = (char*)realloc(blocks[pos], strlen(blocks[pos]) + 1);
            ptr = blockLine;
            pos++;
            if (pos == n - 1)
                break;
            charCount = 0;
        }
        else
            ptr++;
    }
    strcpy(blocks[pos], blockLine);
    blocks[pos] = (char*)realloc(blocks[pos], strlen(blocks[pos]) + 1);

    for (int i = 0; i < n; i++)
    {
        char* ptr = NULL;
        do {
            if (!ptr)
                ptr = strstr(result, blocks[i]);
            else
                ptr = strstr(ptr + 1, blocks[i]);
            if (ptr)
            {
                if ((result == ptr || !(ptr[-1] >= 'A' && ptr[-1] <= 'z')) && (ptr[strlen(blocks[i])] == '\0' || !(ptr[strlen(blocks[i])] >= 'A' && ptr[strlen(blocks[i])] <= 'z')))
                {
                    shiftRight(ptr + strlen(blocks[i]) - 1, strlen(blocks[i]));
                    for (int j = 0; j < strlen(blocks[i]) * 2; j++)
                        ptr[j] = '*';
                }
            }
        } while (ptr);
    }

    printf("%s\n", result);
    for (int i = 0; i < n; i++)
        free(blocks[i]);
    free(blocks);
    return 0;
}