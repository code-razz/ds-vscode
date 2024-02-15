//post fix evaluation

#include<stdio.h>
#include<string.h>
#include<limits.h>
#define max 50
int stack[max];
int top=-1;

void push(int data){
    if(top>=max){
        printf("Stack overflow");
        return;
    }
    top++;
    stack[top]=data;
}

int pop(){
    if(top<0){
        printf("Stack Underflow");
        return 0;
    }
    int data=stack[top];
    top--;
    return data;
}

void display(){
    if(top<0){
        printf("The stack is already empty");
        return;
    }
    for(int i=0;i<top;i++){
        printf("%d\t",stack[i]);
    }
}

int evalExp(char exp[]){
    int len=strlen(exp);
    //printf("%d",len);
    char ch;
    int data1,data2,res;
    for(int i=0;i<len;i++){
        ch=exp[i];
        if(ch=='+' || ch=='-' || ch=='/' || ch=='*'){
            data1=pop();
            data2=pop();
            switch(ch){
                case '+':
                    res=data1+data2;
                    break;
                case '-':
                    res=data1-data2;
                    break;
                case '/':
                    res=data1/data2;
                    break;
                case '*':
                    res=data1*data2;
                    break;
            }
            push(res);    
            // printf("%d,",res);
            // display();
        }else{
            push(ch-48);
        }
    }
    return pop();
}

int main()
{
    char exp[30];
    int data,ch;
    char cha;
    while(1){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Evaluate post fix expression\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the item to be pushed: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                data=pop();
                printf("The popped data is %d : ",data);
                break;
            case 3:
                display();
                break;

            case 4:
                printf("Enter the postfix expression");
                
                scanf("%s",exp);
                int ans=evalExp(exp);
                printf("ans=%d",ans);
                break;

            case 5:
                printf("Thank you!!");
                return 0;
            default:
                printf("Select the mentioned option");
        }
    }
}