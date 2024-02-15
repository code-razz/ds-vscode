#include<stdio.h>
#include<stdlib.h>
#include<string.h>       //for strcpy(); function

typedef struct Node{      //Note:any Identifier can be put here
    char username[15];
    int key;
    struct Node* link;    //Note: Writing LinkedList* link; here will be errornous
}LinkedList;

//typedef struct myLis LinkedList;


LinkedList* head=NULL;
LinkedList* current;

LinkedList* createNode(char user[15],int item){
    LinkedList* newNode=(LinkedList*)malloc(sizeof(LinkedList));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error in createNode\n");
        exit(EXIT_FAILURE);
    }
    newNode->key=item;
    strncpy(newNode->username, user, sizeof(newNode->username) - 1);//strcpy(newNode->username,user);
    newNode->link=NULL;
    return newNode;
}

void display(){
    current=head;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    printf("\nUSERNAME->\tKEY\n");
    while(current!=NULL){
        printf("%s\t->\t%d\n",current->username,current->key);
        current=current->link;
    }
}

void add(char user[15],int item){
    current=head;
    LinkedList* newNode=createNode(user,item);
    if(current==NULL){
        head=newNode;      //Note: writing here current=newNode don't work;
        return;
    }
    while(current->link!=NULL){
        current=current->link;
    }
    current->link=newNode;
}

void addMulti(){
    char user[15];
    int key;
    printf("Enter the username(To stop adding data type exit): ");
    scanf("%s",user);
    if(strcmp(user,"exit")==0 || strcmp(user,"EXIT")==0){
        return;
    }
    printf("Enter the key: ");
    scanf("%d",&key);
    add(user,key);
    addMulti();
}

void delFirst(){
    if(head==NULL){
        printf("\nSementation Fault: The list is already empty\n");
        return;
    }
    LinkedList* ptr=head;
    head=head->link;
    free(ptr);
}

void delLast(){
    if(head==NULL){
        printf("\nSementation Fault: The list is already empty\n");
        return;
    }
    if(head->link==NULL){
        free(head);
        head=NULL;
        return;
    }
    current=head;
    while(current->link->link!=NULL){
        current=current->link;
    }
    //LinkedList* ptr;
    free(current->link);
    current->link=NULL;
}

void delPos(int pos){
    if(pos==0){
        delFirst();
        return;
    }
    current=head;
    int c=0;
    while(c<(pos-1)){
        current=current->link;
        c++;
        if(current->link==NULL){        //if current->link==NULL the current->link->link==INVALID in line 78
            printf("\nSegmentation Fault: Position %d doesnot occur in the list\n",pos);
            return;
        }
    }
    LinkedList* ptr=current->link;
    current->link=current->link->link;
    free(ptr);
}

int main(){
    // add("sham",7575);
    // add("raz",5733);
    // add("ayus",7567);
    // add("surya",5553);
    // add("bisan",5645);
    // add("manzil",5644);
    // display();
    // delFirst();
    // display();
    // delLast();
    // delPos(0);
    // display();
    // delLast();
    // display();
    addMulti();
    display();
    return 0;
}