#include<stdio.h>
#include<stdlib.h>
#define size 5
int pri_Q[size];

int rear=-1;
int front=-1;
void Display();
void check(int);
void Priority_insertion(int);
void delete_front();


int main()
{
    int choice,ch;
    while(1)
    {
        printf("1.To Insert\n");
        printf("2.To Delete\n");
        printf("3.To Display\n");
        printf("4.Exit \n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value to be inserted\n");
                   scanf("%d",&ch);
                   Priority_insertion(ch);
                   break;
            case 2:delete_front();
                   break;
            case 3:Display();
                   break;
            case 4:exit(1);
                   break;
            default:printf("Invalid input\n");
    
        }
    }
}


 
void Priority_insertion(int item)
{
    if(rear>=(size-1))
    {
    printf("Queue Overflow\n");
    return;
    }
    else if(front ==-1 && rear==-1)
    {
      front++;
      rear++;
      pri_Q[rear]=item;
      return;
    }
    else
    check(item);
    rear++;
}
void check(int item)
{
    int i,j;
    //<= ascending priority queue
    //>= descending priority queue
    for(i=0;i<=rear;i++)
    {
        if(item<pri_Q[i])
        {
            for(j=rear+1;j>i;j--)
            {
                pri_Q[j]=pri_Q[j-1];
            }
            pri_Q[i]=item;
            return;
        }
    }
    pri_Q[i]=item;   //in case that item is greater than all the elements 
}


//for deleting a given value in priority queue
void Priority_deletion(int item)
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("Queue underflow\n");
        return;
    }
    else
    {
        for(i=0;i<=rear;i++)
        {
            if(item==pri_Q[i])
            {
                while(i<rear)
                {
                    pri_Q[i]=pri_Q[i+1];
                    i++;
                }
                //pri_Q[i]=-99;      //What is the need of this line?
                rear--;
                if(rear==-1)
                front=-1;;
            return;
            }
        }
        printf("%d element to be deleted not found",item);
    }
}


void delete_front()     // Won’t it create error becoz display is printing from i=0 and also enqueue, dequeue are from i=0 not i=front;     //What is the use of this line?
{
  if(front==-1 && rear==-1)
  {
    printf("Queue empty\n");
    return;
  }
  else
  {
    printf("Queue item deleted=%d\n",pri_Q[front++]);
 
    
  }
}
void Display()
{
    if(front==-1 && rear==-1)
    printf("Queue is Empty\n");
    else
    {
        printf("Queue elements:\n");
        while(front<=rear)
        {
        printf("%d",pri_Q[front]);
        printf("\n");
        front++;
        }
        front=0;      //Won’t the initial front position is distorted?

    }
}
