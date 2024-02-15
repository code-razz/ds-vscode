#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}node;
node* head=NULL;
node* getnode(int val)
{
    node* ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL)
    {
        printf("\n Memory allocation not happened\n");
        return ptr;
    }
    ptr->data=val;
    ptr->next=NULL;
    return ptr;
}
void insertatbegin( int datav)
{
     
     struct Node* new_node=getnode(datav);
     if(head==NULL)
     {
        head=new_node;
     }
     else{
    
        new_node->next=head;
        head=new_node;
     }
     
    return;
}
void insertatlast(int datav)
{
     node* l_node=getnode(datav);
     node* last=head;
     

     if(head==NULL)
     {
     head=l_node;
     }
     else
     {
    while(last->next!=NULL)
          {
               last=last->next;
          }
     last->next=l_node;
     }
     return;
}
void insertatgivenposition(int datav,int pos)
{
    node* newnode=getnode(datav);
    node* temp=head;
    if (pos==1)
     {
         newnode->next=temp;
         head=newnode;
         return;
     }
     for (int i=1;i<pos-1;i++)
     {
         
         temp=temp->next;
        if(temp==NULL)
        {
            printf("position doesnot exist\n");
            return;
        }
         
     }
     newnode->next=temp->next;
     temp->next=newnode;
     return;

}
void deletionatbegin()
{
    node* temp;
     if(head==NULL)
    {
        printf("The list is already empty\n");
        return;

    }
    temp=head;
    head=temp->next;
    free(temp);
    return;
}
void deletionatlast()
{
    
    node* temp=head;
    node* ptr;
    if(head==NULL)
    {
        printf("The list is already empty\n");
        return;

    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
        printf("only node of list is deleted\n");
        return;
    }
    else
    {
        while(temp->next!=NULL)
    {
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=NULL;
    free(temp);
    return;
    }
}
void deletionatgivenplace(int pos)
{
    node* temp;
    node* ptr=head;
    node* current_node;
    if(head==NULL)
    {
        printf("The list is already empty\n");
        return;

    }
    if (pos==1)
     {
        temp=head;
        head=temp->next;
        free(temp);
        return;
     }
     for (int i=1;i<pos-1;i++)
     {
         ptr=ptr->next;
         if(ptr->next==NULL)
        {
            printf("position doesnot exist\n");
            return;
        }
     }
     
     current_node=ptr->next;
     ptr->next=current_node->next;
     free(current_node);
     return ;
}
void insertionafterele(int data,int key)
{
    node* newnode1=getnode(data);
    node *temp;
    if(head==NULL)
    {
        printf("\n the list is empty\n");
        return;
    }
    temp=head;
    while(temp!=NULL&& temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\nThe given element doesnot exist on list\n");
        return;
    }
    newnode1->next=temp->next;
    temp->next=newnode1;
    return;

}
void insertionbeforeele(int data,int key)
{
    node* newnode2=getnode(data);
    node *temp,*ptr;
    if(head==NULL)
    {
        printf("\n The list is empty");
        return;
    }
    temp=head;
    if(temp->data==key)
    {
        newnode2->next=temp;
        head=newnode2;
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        ptr=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\n The element doesnot exist on list\n");
        return;
    }
    newnode2->next=ptr->next;
    ptr->next=newnode2;
    return;
}
void deletionafterele(int key)
{
    node *temp,*deletingnode;
    if(head==NULL)
    {
        printf("\nThe list is already empty\n");
        return;
    }
    temp=head;
    if(temp->next==NULL && temp->data==key)
    {
        printf("\n only this element is present in the list\n");
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\n The given element doesnot found in the list\n");
        return;
    }
    deletingnode=temp->next;
    temp->next=deletingnode->next;
    free(deletingnode);
    return;
}
void deletionbeforeele(int key)
{
    node* temp,*ptr,*prev_node,*current;
    if(head==NULL)
    {
        printf("\n The list is alredy empty\n");
        return;
   }
   {
   temp=head;
   if(temp->next->data==key)
    {
    head=temp->next;
    free(temp);
    return;
    }
while(temp!=NULL && temp->data!=key)
{
    ptr=temp;
    temp=temp->next;
}
if(temp==NULL)
{
    printf("\nThe key doesnot found\n");
    return;
}
current=head;
while(current!=ptr)
{
    prev_node=current;
    current=current->next;
}
prev_node->next=temp;
free(current);
return;

    

}
}

void deletionofgivenele(int key)
{
    node* temp,*ptr;
    if(head==NULL)
    {
        printf("\n The list is already empty");
        return;
    }
    temp=head;
    if(temp->next==NULL&& temp->data==key)
    {
        printf("\nthe only element on list is deleted\n");
        free(temp);
        return;
    }
    else if(temp->data==key)
    {
        head=temp->next;
        free(temp);
        return;
    }
    else{
    while(temp!=NULL && temp->data!=key)
    {
        ptr=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\nElement not found\n");
        return;
    }
    ptr->next=temp->next;
    
    free(temp);
    return;
    
 }
 }



void display()
{
    node *temp;
    temp=head;
    if(temp==NULL)
    {
        printf("\nThe list is empty\n");
        return;
    }
   while(temp!=NULL)
   {
    printf("%d,",temp->data);
    temp=temp->next;
   }
   printf("\n");
}
int main()
{
    int op,pos,loc,key;
    while(1){
    printf("choose the number from given menu \n1.Insert the first node \n2.Append the node \n3.Insert the node on given position \n4.Delete the node at begining \n5.Delete the node at last \n6.Delete the Node of given position \n7.Insert after given element \n8.Insert before given element\n9.Delete after given element\n10.Delete before given element\n11.Delete given element\n12.Display\n13.Exit \n");
    scanf("%d",&op);
    int data;
    switch(op)
    {
        case 1: 
        printf("Enter the data you want to enter in first node\n");
        scanf("%d",&data);
        insertatbegin(data);
                
                break;
        case 2: 
        printf("Enter the data you want to enter in last node\n");
        scanf("%d",&data);

        insertatlast(data);
                 break;
        case 3: 
        printf("Enter the data you want to enter in node and its location\n");
        scanf("%d%d",&data,&pos);
        insertatgivenposition(data,pos);
        break;

        case 4:
        deletionatbegin();
        break;

        case 5:
        deletionatlast();
        break;

        case 6:
        printf("Enter the position of node you want to delete \n");
        scanf("%d",&loc);
        deletionatgivenplace(loc);
        break;

        case 7: 
        printf("Enter the data you want to enter and elemnt after which it should inserted?");
        scanf("%d%d",&data,&key);
        insertionafterele(data,key);
        break;

        case 8:
        printf("Enter the data you want to enter and elemnt before which it should inserted?");
        scanf("%d%d",&data,&key);
        insertionbeforeele(data,key);
        break;

        case 9:
        printf("Enter the element you want to dlete the node after it?");
        scanf("%d",&key);
        deletionafterele(key);
        break;

        case 10:
        printf("Enter the element you want to delete the node before it?");
        scanf("%d",&key);
        deletionbeforeele(key);
        break;

        case 11:
        printf("Enter the element you want to delete?");
        scanf("%d",&key);
        deletionofgivenele(key);
        break;

        case 12:
        display();
        break;

        case 13:
        printf("Thankyou");
        return 0;


    
    
    }
    }

}