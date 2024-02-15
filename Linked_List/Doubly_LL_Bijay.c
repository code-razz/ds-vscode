#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *prev;
    struct Node *next;
};
void insertAtHead(struct Node **head, int val)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->val = val;
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    struct Node *temp = *head;
    temp->prev = new_node;
    new_node->next = temp;
    *head = new_node;
}
void insertAtTail(struct Node **head, int val)
{
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    new_node->val = val;
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    struct Node *tail = *head;
    while (tail->next)
    {
        tail = tail->next;
    }
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
}
void insertAtpos(struct Node **head, int val, int pos)
{
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    new_node->val = val;
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    struct Node *temp = *head;
    int curr = 0;
    while (curr != pos - 1)
    {
        temp = temp->next;
        curr++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    temp->next->prev = new_node;
}

void delAtHead(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    struct Node *temp = *head;
    if(temp->next==NULL){
        printf("linklist is empty: \n");
        *head=NULL;
        return;
    }
    *head = temp->next;
    temp->next->prev = NULL;
    *head = temp->next;
    free(temp);
}
void delAtTail(struct Node **head){
    if (*head == NULL)
    {
        return;
    }

    struct Node*tail=*head;
    if(tail->next==NULL){
        printf("linklist is empty: \n");
        *head=NULL;
        return;
    }
    while(tail->next){
        tail=tail->next;
    }
    tail->prev->next=NULL;
    free(tail);
}
void delAtPosition(struct Node **head,int pos){
    if (*head == NULL)
    {
        return;
    }
    struct Node*temp=*head;
    int curr=0;
    while(curr<pos){
        temp=temp->next;
        curr++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    
}


void display(struct Node **head)
{
    struct Node *temp = *head;
    while (temp)
    {
        printf("%d", temp->val);
        printf("<->");
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    struct Node *head = NULL;
    insertAtTail(&head,11);
    // insertAtTail(&head,12);
    // insertAtTail(&head,13);
    // insertAtTail(&head,14);
    // insertAtTail(&head,15);
    int swt;
    while (1)
    {
        printf("\nenter 1 for insert at head: \nenter 2 for insert at tail: \nenter 3 for insert at pos: \nenter 4 for del at head :\nenter 5 for del at tail: \nenter 6 for del at pos : \nenter 7 for display: \nenter 8 for exit:\n");
        int m, n;
        scanf("%d", &swt);
        switch (swt)
        {
        case 1:
            printf("enter the elem to insert at head: \n");
            scanf("%d", &n);
            insertAtHead(&head, n);
            break;
        case 2:
            printf("enter the elem to insert at tail: \n");
            scanf("%d", &n);
            insertAtTail(&head, n);
            break;
        case 3:
            printf("enter the elem to insert at position: \n");
            scanf("%d", &n);
            printf("enter the elem to insert: \n");
            scanf("%d", &m);
            insertAtpos(&head, n,m);
            break;
        case 4:
            delAtHead(&head);
            break;
        case 5:
            delAtTail(&head);
            break;
        case 6:
            printf("enter the pos to del: \n");
            scanf("%d", &m);
            delAtPosition(&head,m);
            break;
        case 7:
            display(&head);
            break;

        case 8:
            printf("program exits...");
            exit(0);
            break;
        default:
            printf("enter the valid input:\n");
            break;
        }
    }
}