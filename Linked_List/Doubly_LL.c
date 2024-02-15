#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node Node;

Node* head=NULL;

Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

void insertFirst(int data){
    Node* newNode=createNode(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}

void insertBef(int Ele,int data){
    if(head==NULL){
        printf("The list is empty");
        return;
    }
    Node* current=head;
    Node* newNode=createNode(data);
    if(current->data==Ele){
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return;
    }
    while(current->next){
        if(current->next->data==Ele){
            Node* temp=current->next;
            current->next=newNode;
            newNode->prev=current;
            newNode->next=temp;
            return;
        }
        current=current->next;
    }
    printf("The element %d is not found in the list",Ele);
}

void delEle(int Ele){
    if(head==NULL){
        printf("The list is already empty");
        return;
    }
    if(head->data==Ele){
        //free(head);  
        head=head->next;
        if(head!=NULL){   //Only execute if it is not the last element
            head->prev=NULL;  //i.e. previous of new Head
        }
        
        return;
    }
    Node* current=head;
    while(current->next){
        if(current->next->data==Ele){
            //Node* temp=current->next;
            current->next=current->next->next;
            // free(temp);   //NOTE: This throws error;
            if(current->next!=NULL){   // i.e. don't do this operation if it is the last emlement :: now last ele is current->next;
                current->next->prev=current;   //NOTE: here current->next  is equi to current->next->next by previous line 
            }
            return;
        }
        current=current->next;
    }
    printf("The data is not found in the List");
}

void display(){
    Node* current=head;
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    while(current){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

int main(){
    // insertFirst(1);
    // insertFirst(0);
    // insertFirst(-1);
    // insertFirst(-2);
    // insertFirst(-3);
    // display();
    int data;
    int ch;
    while(1){
        printf("\n\nChoose among menu.\n1.Display\n2.Insert at first\n3.Insert before Node\n4.Delete specific node by value\n12.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            display();
            break;

            case 2:
            printf("Enter data: ");
            scanf("%d",&data);
            insertFirst(data);
            break;

            case 3:
            int Ele;
            printf("Enter the node data at left of which new data to be added: ");
            scanf("%d",&Ele);
            printf("Enter data: ");
            scanf("%d",&data);
            insertBef(Ele,data);
            break;

            case 4:
            // int Ele;
            printf("Enter the node data to be deleted: ");
            scanf("%d",&Ele);
            delEle(Ele);
            break;

            case 5:
            
            break;

            case 12:
            return 0;
        }
        
    }
    
}