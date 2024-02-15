#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;  //pointer to next node in the list
    struct node * prev;
};

typedef struct node Node;
//Node* head=NULL;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

Node* insertFirst(int data,Node* head){
    Node *newNode = createNode(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    return head;
}

Node* insertBef(int Ele,int data,Node* head){
    if(head==NULL){
        printf("The list is empty");
        return head ;
    }
    if(head->data==Ele){
        head=insertFirst(data,head);
        return head;
    }
    Node* current=head;
    Node *newNode=createNode(data);
    while(current->next!=NULL){
        if(current->next->data==Ele){
            newNode->next=current->next; 
            current->next->prev=newNode;
            newNode->prev=current;
            current->next=newNode;
            return head;
        }
        current=current->next;
    }
    printf("The element %d is not found in the list",Ele);
    return head;
}

Node* delEle(int Ele,Node* head){
    if(head==NULL){
        printf("The list is empty");
        return head;
    }
    if(head->data==Ele){
        Node* temp=head;
        head=head->next;
        if(temp->next!=NULL){
            head->next->prev=NULL;
        }
        free(temp);
        return head;
    }
    Node * current=head;
    while(current->next!=NULL){
        if(current->next->data==Ele){
            Node* temp=current->next;
            current->next=current->next->next;
            if(current->next!=NULL){
                current->next->prev=current;
            }
            
            return head;
        }
        current=current->next;
    }
    printf("The element %d is not found in list",Ele);
    return head;
}

void display(Node * head){
    Node * current=head;
    if(current==NULL){
        printf("List is empty\n");
        return;
    }
    while(current != NULL) {
        printf("%d -> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}



void main(){
    Node* head=NULL;
    int data;
    int Ele;
    int ch;
    while(1){
        printf("\n\nChoose among menu.\n1.Display\n2.Insert at first\n3.Insert at the left of an element\n4.Delete the specific node by value\n5.Delete last\n12.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            display(head);
            break;

            case 2:
            printf("Enter data: ");
            scanf("%d",&data);
            head=insertFirst(data,head);
            break;

            case 3:
            printf("Enter the data before which to insert new data: ");
            scanf("%d",&Ele);
            printf("Enter data: ");
            scanf("%d",&data);
            head=insertBef(Ele,data,head);
            break;

            case 4:
            printf("Enter the data to be deleted: ");
            scanf("%d",&Ele);
            head=delEle(Ele,head);
            break;

            case 5:
            //deleteEnd();
            break;

            case 12:
            return;
        }
        
    }
    
}