#include<stdio.h>
#include<stdlib.h>
struct Nodes{
    int data;
    struct Nodes* next;
};
typedef struct Nodes*  Node;

Node insertFront(Node first);
Node insertRear(Node first);
Node insertAfter(Node first);
Node insertBefore(Node first);
Node deleteAfter(Node first);
Node deleteBefore(Node first);
Node deleteElement(Node first);
void display(Node first){
    if(first==NULL){
        printf("empty list");
        return;
    }
    Node current=first;
    while(current){
        printf("%d, ",current->data);
        current=current->next;
    }
}

void display(Node first);

int main(){
    // Node first=(Node)malloc(sizeof(struct Nodes));
    // first->data=56;
    // first->next=NULL;
    // first=insertAfter(first);
    // first=insertAfter(first);
    // first=insertAfter(first);
    Node first=NULL;
    first=(Node)malloc(sizeof(struct Nodes));
    first->data=95;
    first->next=NULL;
    
    Node current=(Node)malloc(sizeof(struct Nodes));
    current->data=87;
    current->next=NULL;
    first->next=current;

    current=(Node)malloc(sizeof(struct Nodes));
    current->data=99;
    current->next=NULL;
    first->next->next=current;
    display(first);
    first=insertBefore(first);
    display(first);
}

Node insertAfter(Node first){
    int value,posVal;
    printf("Enter the data to be inserted: ");
    scanf("%d",&value);
    printf("Enter the data after which %d is to be palced: ",value);
    scanf("%d",&posVal);

    Node current=first;
    while(current!=NULL){
        if(current->data==posVal){
            Node newNode=(Node)malloc(sizeof(struct Nodes));
            newNode->data=value;
            newNode->next=current->next;
            current->next=newNode;
            return first;

        }
        current=current->next;
    }
    printf("The element %d doesnot exists in the list",posVal);
    return first;
}

Node insertBefore(Node first){
    int value,posVal;
    printf("Enter the data to be inserted: ");
    scanf("%d",&value);
    printf("Enter the data before which %d is to be palced: ",value);
    scanf("%d",&posVal);
    Node current=first;
    Node newNode=(Node)malloc(sizeof(struct Nodes));
    newNode->data=value;
    if(first==NULL){
        printf("The element %d doesnot exists in the list",posVal);
    }else if(first->data==posVal){
        newNode->next=first;
        first=newNode;
    }else if(first->next->data==posVal){
        newNode->next=first->next;
        first->next=newNode;

    }else{
        while(current->next->next!=NULL){
        if(current->next->next->data==posVal){
            newNode->next=current->next;
            current->next=newNode;
            return first;
        }
        current=current->next;
        }
        printf("The element %d doesnot exists in the list",posVal);

    }
    return first;
    
}