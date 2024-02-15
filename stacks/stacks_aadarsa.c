#include <stdio.h>
#define max 5
int A[max];
int top=-1;
void push(int value)
{
    if(top==max-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        A[top]=value;
    }
}
void pop()
{
    if (top== -1){
        printf("Stack underflow");
        return;
    }
    top--;
}
void peek()
{
    if(top== -1){
        printf("Stack empty");
    }
    else{
        printf("%d",A[top]);
    }
}
void display()
{
    int i;
    if(top== -1){
        printf("Stack is empty");
        return;
    }
    for(i=top;i>=0;i--){
        printf("%d\n",A[i]);
    }
}
int main()
{
    int data,ch;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Thank you!!");
                return 0;
            default:
                printf("Select the mentioned option");
        }
    }
}