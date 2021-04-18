#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150

typedef struct book
{
    char *name;
    struct book *next;
} book;

void addRight(book **last, char *name)
{
    if (*last == NULL)
    {
        *last = (book *)malloc(sizeof(book));
        (*last)->name = name;
        (*last)->next = NULL;
    }
    else
    {
        book *newBook = (book *)malloc(sizeof(book));
        newBook->name = name;
        newBook->next = NULL;
        (*last)->next = newBook;
        *last = newBook;
    }
}

void addLeft(book **head, char *name)
{
    if (*head != NULL)
    {
        book *newBook = (book *)malloc(sizeof(book));
        newBook->name = name;
        newBook->next = *head;
        *head = newBook;
    }
    else
        addRight(head, name);
}

void deleteLeft(book **head)
{
    if (*head != NULL)
    {
        free((*head)->name);
        book *next = (*head)->next;
        free(*head);
        (*head) = next;
    }
}

void printBooks(book *head)
{
    while (head != NULL)
    {
        printf("%s\n", head->name);
        head = head->next;
    }
}

int main()
{
    int count;
    scanf("%d", &count);
    getchar();
    book *head = NULL;
    book *last = NULL;

    for (int i = 0; i < count; i++)
    {
        char *name = (char *)malloc(sizeof(char) * (MAX + 1));
        fgets(name, MAX, stdin);
        name[strlen(name) - 1] = '\0';
        addRight(&last, name);
        if (i == 0)
            head = last;
    }

    char command[200] = {};
    while (strcmp(command, "Exit") != 0)
    {
        scanf("%s", command);
        getchar();
        if (strcmp(command, "AddRight") == 0)
        {
            char *name = (char *)malloc(sizeof(char) * (MAX + 1));
            fgets(name, MAX, stdin);
            name[strlen(name) - 1] = '\0';
            addRight(&last, name);
            count++;
        }
        else if (strcmp(command, "AddLeft") == 0)
        {
            char *name = (char *)malloc(sizeof(char) * (MAX + 1));
            fgets(name, MAX, stdin);
            name[strlen(name) - 1] = '\0';
            addLeft(&head, name);
            count++;
        }
        else if (strcmp(command, "DeleteLeft") == 0)
        {
            deleteLeft(&head);
            count--;
        }
    }
    printf("%d\n", count);
    printBooks(head);
    return 0;
}