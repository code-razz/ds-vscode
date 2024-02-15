#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define max 100
char stack[max];
int top=-1;

void push(char ch){
    if(top<max-1){
        top++;
        stack[top]=ch;
    }
}

char pop(){
    if(top<0){
        printf("The stack is empty");
        exit(-1);
    }
    char ch=stack[top];
    top--;
    return ch;
}

int prec(char ch){
    if(ch=='^'){
        return 4;
    }else if(ch=='/' || ch=='*'){
        return 3;
    }else if(ch=='+' || ch=='-'){
        return 2;
    }else if(ch=='('){
        return 1;
    }else if(ch=='#'){
        return 0;
    }
    else{
        printf("invalid parameter");
        exit(-1);
    }
}

int main(){
    char infix[100],postfix[100];
    char ch;
    char x;
    int count=0;
    push('#');
    printf("Enter the expression: ");
    gets(infix);                //scanf("%s",infix);
    for(int i=0;infix[i]!='\0';i++){
        ch=infix[i];
        // printf("%c\n",ch);
        if(isalnum(ch)){
            postfix[count]=ch;
            count++;
            // printf("rakfj\n");
            // printf("%s\n",postfix);
            
        }else if(ch=='('){
            push(ch);
            // printf("afav\n");
        }else if(ch==')'){
            while((x=pop())!='('){
                postfix[count]=x;
                count++;
            }
        }else{
            while(prec(ch)<=prec(stack[top])){
                postfix[count]=pop();
                count++;
            }
            push(ch);
        }
    }
    while(stack[top]!='#'){
        ch=pop();
        postfix[count]=ch;
        count++;
    }
    postfix[count]='\0';

    printf("\n\nPostfix: %s",postfix);
    // printf("\nstack: %s",stack);
    return 0;
}