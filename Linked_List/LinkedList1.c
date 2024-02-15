#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{              //You can give any identifier name here 
    //char username[20];
    int key;
    struct Node *next;
};
typedef struct Node myList;

myList* createNode(int key){
    myList* newNode=(myList*)malloc(sizeof(myList));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error in createNode\n");
        exit(EXIT_FAILURE);
    }
    //strcpy(newNode->username,uname);
    newNode->key=key;
    newNode->next=NULL;
    return newNode;
}

void offerFirst(myList** head,int k){
    //myList* current=*head;
    myList* newNode=createNode(k);
    newNode->next=*head;   //updating the null to initial first item
    *head=newNode;
}

void offerLast(myList** current,int k){
    myList* newNode=createNode(k);
    if(*current==NULL){
        *current=newNode;
        return;
    }
    myList* temp=*current;    //NOte using *current below here won't work;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void offerPos(myList** head,int pos,int k){
    myList* current=*head;
    if(pos==0){
        offerFirst(head,k);    //NOTE head is passed without any &. HOW??
        return;
    }
    int c=0;
    
    while(c<pos-1){
        
        current=current->next;
        c++;
        if(current==NULL){
            printf("\nInvalid Position");
            return;
        }
    }
    myList* newNode=createNode(k);
    newNode->next=current->next;
    current->next=newNode;
}

void display(myList** head){
    printf("\n");
    myList* current=*head;
    while(current!=NULL){
        printf("%d, ",current->key);
        current=current->next;
        
    }
}


void main(){
    myList* head=NULL;
    //char un="raj";
    // head->key=54;
    // head->next=(myList*)malloc(sizeof(myList));
    // head->next->key=76;
    // head->next->next=NULL;
    int k=15;
    //offerFirst(&head,99);
    offerLast(&head,77);
    
    offerLast(&head,15);
    offerFirst(&head,5);
    offerFirst(&head,43);
    offerLast(&head,65);
    display(&head);
    offerPos(&head,4,76);
    display(&head);
}
