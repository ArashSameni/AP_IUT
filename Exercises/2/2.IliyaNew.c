#include <stdio.h>
#include <stdlib.h>

typedef struct rational
{
    int a;
    int b;
} rational;

union data
{
    int integer;        // 1
    float decimal;      // 2
    rational ratNumber; // 3
};

typedef struct node
{
    int id;
    union data Data;
    struct node *next;
    struct node *before;
} node;

void addRight(node **last, int id, union data Data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->id = id;
    newNode->Data = Data;
    newNode->before = *last;
    newNode->next = NULL;
    (*last)->next = newNode;
    *last = newNode;
}

void deleteRight(node **last){
    node *tmp = (*last)->before;
    free(*last);
    *last = tmp;
}

void print(node *head){
    while(head != NULL)
    {
        if(head->id == 1)
            printf("%d\n", head->Data.integer);
        else if(head->id == 2)
            printf("%f\n", head->Data.decimal);
        else
            printf("%d/%d\n", head->Data.ratNumber.a, head->Data.ratNumber.b);
        head = head->next;
    }
}

int main(int c, char **v)
{
    union data tempData;
    tempData.integer = 13;

    node *head = (node *)malloc(sizeof(node));
    head->id = 1;
    head->Data = tempData;
    head->next = NULL;
    head->before = NULL;

    node *last = head;
    tempData.decimal = 8.5;
    addRight(&last, 2, tempData);

    tempData.decimal = 9.35;
    addRight(&last, 2, tempData);
    deleteRight(&last);

    rational rat;
    rat.a = 2;
    rat.b = 3;
    tempData.ratNumber = rat;
    addRight(&last, 3, tempData);

    print(head);
    return 0;
}