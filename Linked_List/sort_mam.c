#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node *next;
}NODE;

 NODE *s1=NULL;
  NODE *s2=NULL;

NODE *create(NODE *start)
{
NODE *temp,*ptr;
int n;
printf("enter the no of nodes to be created\n");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
  temp=(struct node*)malloc(sizeof(struct node));
  printf("Enter the value to be inserted in node %d\n",(i+1));
  scanf("%d",&temp->data);
  temp->next=NULL;
  if(start==NULL)
  start=temp;
  else{
    ptr=start;
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;

    }
    ptr->next=temp;
  }
}
return start;
}

NODE *sort(NODE *s)
{
  NODE *t1,*t2;
  int temp;
  for(t1=s;t1->next!=NULL;t1=t1->next)
  {
    for(t2=t1->next;t2!=NULL;t2=t2->next)
    {
      if(t1->data>t2->data)
      {
        temp=t1->data;
        t1->data=t2->data;
        t2->data=temp;
      }
    }
  }
  return s;
}

void display(struct node *p)
{
 struct node *ptr1;
 ptr1=p;
 while(ptr1!=NULL)
 {
   printf("%d\n",ptr1->data);
   ptr1=ptr1->next;
 }
 }


int main()
{
  int choice;
 
  while(1)
  {
    printf("1.to create a list\n 2. to sort the list\n 3. to display the list\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:s1=create(s1);
             break;
      case 2:if(s1==NULL)
             s1=create(s1);
             s1= sort(s1);
                 break;
      case 3:display(s1);
             break;              
    }
  }
  return 0;
}
