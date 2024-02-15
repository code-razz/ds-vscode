#include<stdio.h>
#include<stdlib.h>
struct node{      //Instead of node you can give any identifier name here
    int marks;
    struct node* next_ptr;
};

void printlist(struct node* head){
    if(head==NULL){
        return;
    }
    printf("%d, ",head->marks);
    printlist(head->next_ptr);
}

void printlist2(struct node* head){
    struct node *current=head;
    printf("\n");
    while(current!=NULL){
        printf("%d ",current->marks);
        current=current->next_ptr;
    }
}

void add(int data, struct node** head){
    struct node* current=*head;
    while(current->next_ptr!=NULL){
        current=current->next_ptr;
    }
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->marks=data;
    newNode->next_ptr=NULL;
    current->next_ptr=newNode;
}

void main(){
    struct node* head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->marks=95;
    head->next_ptr=NULL;
    
    struct node* current=(struct node*)malloc(sizeof(struct node));
    current->marks=87;
    current->next_ptr=NULL;
    head->next_ptr=current;

    current=(struct node*)malloc(sizeof(struct node));
    current->marks=99;
    current->next_ptr=NULL;
    head->next_ptr->next_ptr=current;

    //printlist(head);
    printlist2(head);
    add(63,&head);
    add(45,&head);
    
    printlist2(head);
    add(48,&head);

    printlist2(head);


    return;

}