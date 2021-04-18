#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* CreateNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void PrintNode(Node* node)
{
    printf("%d\n", node->data);
}

void PrintLinkedList(Node* head)
{
    while (head != NULL)
    {
        PrintNode(head);
        head = head->next;
    }
}

void ReversePrint(Node* head)
{
    Node** nodes = (Node**)malloc(sizeof(Node*));
    int pos = 0;
    while (head != NULL)
    {
        nodes[pos++] = head;
        nodes = (Node**)realloc(nodes, sizeof(Node*) * pos + 1);
        head = head->next;
    }
    for (int i = pos - 1; i >= 0; i--)
        PrintNode(nodes[i]);
    free(nodes);
}

void push_front(Node** head, int data)
{
    Node* newNode = CreateNode(data);
    newNode->next = *head;
    *head = newNode;
}

void push_back(Node** head, int data)
{
    Node* newNode = CreateNode(data);
    Node* tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newNode;
}

void pop_front(Node** head)
{
    if (*head)
    {
        Node* tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}

void pop_back(Node** head)
{
    Node* tmp = *head;
    Node* before = *head;
    while (tmp->next != NULL)
    {
        before = tmp;
        tmp = tmp->next;
    }
    before->next = NULL;
    free(tmp);
}

void insert(Node** head, int index, int data)
{
    if (index < 0)
        printf("Index out of range\n");
    else if (index == 0)
        push_front(head, data);
    else
    {
        int pos = 0;
        Node* tmp = *head;
        Node* before = *head;
        while (pos != index)
        {
            if (tmp == NULL)
                break;
            pos++;
            before = tmp;
            tmp = tmp->next;
        }
        if (tmp == NULL && index == pos)
            push_back(head, data);
        else if (index == pos && tmp != NULL)
        {
            Node* newNode = CreateNode(data);
            newNode->next = tmp;
            before->next = newNode;
        }
        else
            printf("Index out of range\n");
    }
}

void delete (Node** head, int index)
{
    if (index < 0)
        printf("Index out of range\n");
    else
    {
        if (index == 0)
            pop_front(head);
        else
        {
            int pos = 0;
            Node* tmp = *head;
            Node* before = *head;
            while (pos != index)
            {
                if (tmp->next == NULL)
                    break;
                pos++;
                before = tmp;
                tmp = tmp->next;
            }
            if (tmp == NULL && index == pos)
                pop_front(head);
            else if (index == pos && tmp != NULL)
            {
                before->next = tmp->next;
                free(tmp);
            }
            else
                printf("Index out of range\n");
        }
    }
}

int search(Node* head, int data)
{
    int index = 0;
    while (head->data != data)
    {
        if (head->next == NULL)
            break;
        head = head->next;
        index++;
    }
    if (head->data == data)
        return index;
    else
        return -1;
}

Node* searchNode(Node* head, int index)
{
    Node* tmp = head;
    int pos = 0;
    while (pos != index)
    {
        tmp = tmp->next;
        pos++;
    }
    return tmp;
}

void swap(Node** head, int index1, int index2)
{
    Node* nd1 = searchNode(*head, index1);
    Node* nd2 = searchNode(*head, index2);
    int tmp = nd1->data;
    nd1->data = nd2->data;
    nd2->data = tmp;
}

void reversed(Node** head)
{
    Node** nodes = (Node**)malloc(sizeof(Node*));
    Node* tmp = *head;
    int pos = 0;
    while (tmp != NULL)
    {
        nodes[pos++] = tmp;
        nodes = (Node**)realloc(nodes, sizeof(Node*) * pos + 1);
        tmp = tmp->next;
    }
    (*head)->next = NULL;
    *head = nodes[pos - 1];
    for (int i = pos - 1; i > 0; i--)
        nodes[i]->next = nodes[i - 1];
    free(nodes);
}

int main(int c, char** v)
{
    Node* head = CreateNode(20);
    push_back(&head, 40);
    push_front(&head, 0);
    push_front(&head, -20);
    push_front(&head, -40);
    push_back(&head, 60);
    insert(&head, 3, 10);
    delete (&head, 3);
    PrintLinkedList(head);
    printf("////////////////////////////\n");
    printf("%d\n", search(head, 10));
    printf("%d\n", search(head, 60));
    printf("////////////////////////////\n");
    swap(&head, 0, 5);
    PrintLinkedList(head);
    printf("////////////////////////////\n");
    reversed(&head);
    PrintLinkedList(head);
    printf("////////////////////////////\n");
    return 0;
}