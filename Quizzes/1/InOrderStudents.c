//Arash Sameni
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 150

typedef struct student {
    char* name;
    int age;
} student;

char* getFamily(char* name) {
    while (*name != ' ')
        name++;
    return name + 1;
}

int main()
{
    int count, sum = 0;
    scanf("%d", &count);
    student* stds = (student*)malloc(sizeof(student) * count);

    for (int i = 0; i < count; i++)
    {
        student* newStd = stds + i;

        //Get Name
        char* name = (char*)malloc(sizeof(char) * MAX);
        scanf("%s", name);
        int len = strlen(name);
        *(name + len) = ' ';
        *(name + len + 1) = '\0';

        char* tmp = (char*)malloc(sizeof(char) * MAX);
        scanf("%s", tmp);
        strcat(name, tmp);
        free(tmp);
        newStd->name = name;

        //Get Age
        scanf("%d", &(newStd->age));
        sum += newStd->age;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            char* fam1 = getFamily((stds + i)->name);
            char* fam2 = getFamily((stds + j)->name);
            if (strcmp(fam2, fam1) < 0) // faghat baraie harf avval : *fam2 < *fam1
            {
                student temp = *(stds + i);
                *(stds + i) = *(stds + i + 1);
                *(stds + i + 1) = temp;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%s\n", (stds + i)->name);
        free((stds + i)->name);
    }
    free(stds);

    printf("%f", (float)sum / count);
    return 0;
}