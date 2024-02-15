//circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node Node;
Node* head=NULL;

Node* createNode(int item){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=item;
    newNode->next=NULL;
    return newNode;
}

void display(){
    Node* current=head;
    if(head==NULL){
        printf("The list is empty");
        return;
    }
    while(current->next!=head){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("%d->",current->data);
    printf("NULL");
}

void insertFirst(int item){
    Node* current=head;
    Node* newNode=createNode(item);
    if(current==NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    while(current->next!=head){
        current=current->next;
    }
    current->next=newNode;
    newNode->next=head;
    head=newNode;
}

void insertLast(int item){
    Node* current=head;
    Node* newNode=createNode(item);
    if(current==NULL){
        head=newNode;
        newNode->next=head;
        return;
    }
    while(current->next!=head){
        current=current->next;
    }
    current->next=newNode;
    newNode->next=head;
}

void deleteFirst(){
    Node* current=head;
    if(current==NULL){
        printf("The list is already empty");
        return;
    }
    if(current->next==head){
        free(head);
        head=NULL;
        return;
    }
    while(current->next!=head){
        current=current->next;
    }
    Node* temp=head;
    current->next=head->next;
    head=head->next;
    free(temp);
}

void deleteEnd(){
    Node* current=head;
    if(current==NULL){
        printf("The List is already empty");
        return;
    }
    if(current->next==head){
        free(head);
        head=NULL;
        return;
    }
    while(current->next->next!=head){
        current=current->next;
    }
    Node* temp=current->next;
    current->next=head;
    free(temp);
}

void main(){
    int data;
    int ch;
    while(1){
        printf("\n\nChoose among menu.\n1.Display\n2.Insert at first\n3.Insert at end\n4.Delete first\n5.Delete last\n12.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            display();
            break;

            case 2:
            printf("Enter data");
            scanf("%d",&data);
            insertFirst(data);
            break;

            case 3:
            printf("Enter data");
            scanf("%d",&data);
            insertLast(data);
            break;

            case 4:
            break;

            case 5:
            deleteEnd();
            break;

            case 12:
            return;
        }
        
    }
    
}