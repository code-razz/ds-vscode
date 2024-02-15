#include<stdio.h>
#include<stdlib.h>
struct Node{
    int val;
    struct Node*next;
};

void insertAtHead(struct Node**head,int val){
    struct Node*new_node;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->next=*head;
    new_node->val=val;
    *head=new_node;
}

void insertAtTail(struct Node**head,int val){
    struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));

    new_node->val=val;
    new_node->next=NULL;
    if(*head==NULL){
        *head=new_node;
        return;
    }
    struct Node*last_node=*head;

    while(last_node->next!=NULL){
        last_node=last_node->next;
    }
    last_node->next=new_node;
}

void insertAtPosition(struct Node**head,int val,int pos){
    struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->val=val;
    if(pos==0){
        insertAtHead(head,val);
        return;
    }
    int curr=0;
    struct Node*temp=*head;
    while(curr!=pos-1){
        temp=temp->next;
        curr++;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}


void insertAfter(struct Node **head, int elem, int val)
{
    struct Node *temp = *head;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->val = val;
    if (temp == NULL)
    {
        new_node = *head;
    }
    while (temp)
    {
        temp = temp->next;
        if (temp->val == elem)
        {
            new_node->next = temp->next;
            temp->next = new_node;
            break;
        }
    }
}

void insertBefore(struct Node**head,int elem,int val){
    struct Node*new_node;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    new_node->val = val;
    if (temp == NULL)
    {
        new_node = *head;
    }
    while(temp->next->val!=elem){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void delAtHead(struct Node**head){
    struct Node*temp=*head;
    *head=temp->next;
    free(temp);
}

void delAtTail(struct Node**head){
    struct Node *secondLast=*head;
    if(head==NULL){
        return;
    }
    while(secondLast->next->next!=NULL){
        secondLast=secondLast->next;
    }
    secondLast->next=NULL;
    free(secondLast->next);
}

void delAtPos(struct Node**head,int pos){
    struct Node*prev=*head;
    int curr=0;
    if(pos==0){
        delAtHead(head);
        return;
    }
    while(curr!=pos-1){
        prev=prev->next;
        curr++;
    }
   struct Node*temp=prev->next;
   prev->next=prev->next->next;
   free(temp); 
}


void delElem(struct Node**head,int elem){
    struct Node*temp=*head;
    if(head==NULL){
        return;
    }
    while(temp->next->val!=elem){
        temp=temp->next;
    }
    struct Node*cur=temp->next;
    temp->next=temp->next->next;
    free(cur);
}

void delAfter(struct Node**head,int elem){
    struct Node*temp=*head;
    if(head==NULL){
        return;
    }
    while(temp->val!=elem){
        temp=temp->next;
    }
    struct Node*cur=temp->next;
    temp->next=temp->next->next;
    free(cur);
}

void delBefore(struct Node**head,int elem){
    struct Node*temp=*head;
    if(head==NULL){
        return;
    }
    while(temp->next->next->val!=elem){
        temp=temp->next;
    }
    struct Node*cur=temp->next;
    temp->next=temp->next->next;
    free(cur);
}

void display(struct Node*head){
    while(head!=NULL){
        printf("%d",head->val);
        printf("->");
        head=head->next;
    }
    printf("NULL");
}

int main(){
    struct Node*head=NULL;
    int linkedList;
    int m,n,p;
    insertAtHead(&head,9);
    insertAtHead(&head,8);
    insertAtHead(&head,7);
    printf("\nEnter 1 to insert at head: \nEnter 2 to insert at tail:\nEnter 3 to insert at position:\nEnter 4 for insert After:\nEnter 5 for insert Before:\nEnter 6 to delete from Head:\nEnter 7 to delete from Tail:\nEnter 8 to delete From position:\nEnter 9 for delete Element:\nEnter 10 for delete after elem:\nEnter 11 for delete before element:\nEnter 12 to Exit Program:");
    scanf("%d",&linkedList);
    switch (linkedList)
    {
    case 1:
    printf("enter the element to insert at Head: ");
    scanf("%d",&n);
    insertAtHead(&head,n); 
    display(head); 
    break;

    case 2:
    printf("enter the element to insert at tail");
    scanf("%d",&n);
    insertAtTail(&head,n);
    display(head);
    break;

    case 3:
    printf("enter the element to insert at position");
    scanf("%d",&n);
    printf("enter the position to enter the elem: ");
    scanf("%d",&p);
    insertAtPosition(&head,n,p);
    display(head);
    break;

    case 4:
    printf("Enter element after which you want to insert:");
    scanf("%d",&p);
    printf("Enter the elem you want to insert:");
    scanf("%d",&n);
    display(head);
    printf("\n");
    insertAfter(&head,p,n);
    display(head);
    break;


    case 5:
    printf("Enter element before which you want to insert:");
    scanf("%d",&p);
    printf("Enter the elem you want to insert:");
    scanf("%d",&n);
    display(head);
    printf("\n");
    insertBefore(&head,p,n);
    display(head);
    break;

    case 6:
    display(head);
    printf("\n");
    delAtHead(&head);
    display(head);
    break;

    case 7:
    display(head);
    printf("\n");
    delAtTail(&head);
    display(head);
    break;

    case 8:
    printf("enter the position to delete:");
    scanf("%d",&p);
    display(head);
    printf("\n");
    delAtPos(&head,p);
    display(head);
    break;


    case 9:
    printf("enter the Element to delete:");
    scanf("%d",&p);
    display(head);
    printf("\n");
    delElem(&head,p);
    display(head);
    break;

     case 10:
    printf("enter the Element after which you want to delete:");
    scanf("%d",&p);
    display(head);
    printf("\n");
    delAfter(&head,p);
    display(head);
    break;

    case 11:
    printf("enter the element before which you want to delete:");
    scanf("%d",&p);
    display(head);
    printf("\n");
    delBefore(&head,p);
    display(head);
    break;

    case 12:
    printf("program exit\n");
    exit(0);

    default:
    printf("enter the valid key:");
        break;
    }
    return 0;
}