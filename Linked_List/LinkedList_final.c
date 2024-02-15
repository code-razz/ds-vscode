#include<stdio.h>
#include<stdlib.h>
#include<string.h>       //for strcpy(); function

typedef struct Node{      //Note:any Identifier can be put here
    char username[15];
    int key;
    struct Node* link;    //Note: Writing LinkedList* link; here will be errornous
}LinkedList;

//typedef struct Node LinkedList;

LinkedList* head=NULL;
LinkedList* current;

//Functions declarations
void delEle(int ele);

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

void addFirst(char user[15],int item){
    LinkedList* newNode=createNode(user,item);
    newNode->link=head;
    head=newNode;
}

void addPos(char user[15],int item,int pos){
    int c=1;
    current=head;
    if(pos==0){
        addFirst(user,item);
        return;
    }
    while(current){
        if(c==pos){
            LinkedList* newNode=createNode(user,item);
            newNode->link=current->link;
            current->link=newNode;
            return;
        }
        c++;
        current=current->link;
    }
    printf("The position %d doesnot exist in the list",pos);
}

void addBefore(char user[15],int item,int ele){
    current=head;
    if(head==NULL){
        printf("The Element %d is not found in the list",ele);
        return;
    }
    if(head->key==ele){
        addFirst(user,item);
        return;
    }
    while(current->link){
        if(current->link->key==ele){
            LinkedList* newNode=createNode(user,item);
            newNode->link=current->link;
            current->link=newNode;
            return;
        }
        current=current->link;
    }
    printf("The element %d doesnot exists in the list",ele);
}

void addAfter(char user[15],int item,int ele){
    current=head;
    while(current){
        if(current->key==ele){
            LinkedList* newNode=createNode(user,item);
            newNode->link=current->link;
            current->link=newNode;
            return;
        }
        current=current->link;
    }
    printf("The element %d doesnot exists in the list",ele);
}

void addInPlace(char user[15],int item,int ele){
    addAfter(user,item,ele);
    delEle(ele);
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
        printf("\nThe list is already empty\n");
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
        if(current->link==NULL){        //if current->link==NULL the current->link->link==INVALID in line 182
            printf("\nSegmentation Fault: Position %d doesnot occur in the list\n",pos);
            return;
        }
    }
    LinkedList* ptr=current->link;
    current->link=current->link->link;
    free(ptr);
}

void delBefore(int ele){
    current=head;
    if(head==NULL){
        printf("The element %d doesnot exists in the list",ele);
        return;
    }
    if(head->key==ele){
        printf("No element exists before %d as it is the 1st element of the list",ele);
        return;
    }
    if(head->link->key==ele){
        delFirst();
        return;
    }
    while(current->link->link){
        if(current->link->link->key==ele){
            LinkedList* temp=current->link;
            current->link=current->link->link;
            free(temp);
            return;
        }
        current=current->link;
    }
    printf("The element %d doesnot exist in the list",ele);
}

void delAfter(int ele){
    current=head;
    while(current){
        if(current->key==ele){
            if(current->link==NULL){
                printf("No element exists after %d",ele);
                return;
            }
            LinkedList* temp=current->link;
            current->link=current->link->link;
            free(temp);
            return;
        }
        current=current->link;
    }
    printf("The element %d doesnot exists in the list",ele);
}

void delEle(int ele){
    current=head;
    if(head==NULL){
        printf("The element %d does not exists in the list",ele);
        return;
    }
    if(head->key==ele){
        head=head->link;
        return;
    }
    while(current->link){
        if(current->link->key==ele){
            LinkedList* temp=current->link;
            current->link=current->link->link;
            free(temp);
            return;
        }
        current=current->link;
    }
    printf("The element %d doesnot exists in the list",ele);
}


void revList(){
    if(head==NULL){
        printf("The list is empty");
        return;
    }
    if(head->link==NULL){
        return;   //since single element list is alrady reversed;
    }
    current=head;
    LinkedList* next=NULL;
    LinkedList* prev=NULL;
    while(current!=NULL){
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head=prev;   //cannot do head=current;
}

void sortList(){     //By BHISAN
    LinkedList* end = NULL,*p = NULL;
    int temp;
    for(;end!= head->link;end = p){
        for(p = head;p->link!=end;p=p->link){
            if(p->key > p->link->key){
                temp = p->key;
                p->key = p->link->key;
                p->link->key = temp;
            }
        }
    }
   return;
}

int main(){
    // add("sham",7575);
    // add("raz",5733);
    // add("ayus",7567);
    // add("surya",5553);
    // add("bisan",5645);
    // add("manzil",5644);
    int ch;
    char user[15];
    int key;
    int ele;
    while(1){
        printf("\n\n********************COD BY RAZ****************************");
        printf("\nChoose any one of the options\n");
        printf("1.Insert at begining.\n2.Insert at the end.\n3.Insert at any position.\n4.Insert before element.\n5.Insert after element.\n6.Insert inplace of an element\n7.Delete the first element.\n8.Delete the last element.\n9.Delete at position.\n10.Delete before the element\n11.Delete after an element\n12.Delete an element.\n13.Display the list.\n14.Add multiple elements to the last\n15.Exit.\n16. Reverse list\n.17.sort list\n");
        scanf("%d",&ch);
        if(ch>=1 && ch<=6){
            printf("Enter the username and the key: ");
            scanf("%s%d",user,&key);
            switch(ch){
                case 1:
                addFirst(user,key);
                break;
            
                case 2:
                add(user,key);
                break;

                case 3:
                int pos;
                printf("Enter the position to insert the element: ");
                scanf("%d",&pos);
                addPos(user,key,pos);
                break;

                case 4:      
                printf("Enter the element before which to insert new element: ");
                scanf("%d",&ele);
                addBefore(user,key,ele);
                break;

                case 5:
                printf("Enter the element after which to insert new element: ");
                scanf("%d",&ele);
                addAfter(user,key,ele);
                break;

                case 6:
                printf("Enter the element inplace of which to insert new element: ");
                scanf("%d",&ele);
                addInPlace(user,key,ele);
                break;
            }
        }else{
            switch(ch){
                case 7:
                delFirst();
                break;

                case 8:
                delLast();
                break;

                case 9:
                int pos;
                printf("Enter the position to delete the element: ");
                scanf("%d",&pos);
                delPos(pos);
                break;

                case 10:
                printf("Enter the element before which to delete the element: ");
                scanf("%d",&ele);
                delBefore(ele);
                break;

                case 11:
                printf("Enter the element after which to delete the element: ");
                scanf("%d",&ele);
                delAfter(ele);
                break;

                case 12:
                printf("Enter the element to delete from the list:");
                scanf("%d",&ele);
                delEle(ele);
                break;

                case 13:
                display();
                break;

                case 14:
                addMulti();
                break;

                case 15:
                return 0;
                break;

                case 16:
                revList();
                break;

                case 17:
                sortList();
                break;

                default:
                printf("Invalid Entry");
            }
        }
    }
}
