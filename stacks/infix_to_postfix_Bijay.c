#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    char *arr;
};
int isFull(struct stack*sp){
    if(sp->top==sp->size){
        return 1;
    }
    return 0;
}
int isEmpty(struct stack*sp){
    if(sp->top==-1){
        return 1;
    }
    return 0;
}
void push(struct stack*sp,int val){
    if(sp->top==sp->size-1){
        printf("overflow\n");
        return;
    }
    sp->top++;
    sp->arr[sp->top]=val;
}
char pop(struct stack*sp){
    if(sp->top==-1){
        printf("underflow\n");
        return -1;
    }
    char val=sp->arr[sp->top];
    sp->top--;
    return val;
}

char peak(struct stack*sp){
    if(sp->top==-1){
        return -1;
    }
    return sp->arr[sp->top];
}

int isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
        return 1;
    }
    return 0;
}
int presidence(char ch){
    if(ch=='*'||ch=='/'){
        return 3;
    }
    else if(ch=='+'||ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}

char* infixTOpostfix(struct stack*sp,char*infix){
    char*postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(presidence(infix[i])>presidence(peak(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';

    return postfix;
}
int main(){
    struct stack*sp=(struct stack*)malloc(sizeof (struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));

    char* infix="x-y/z-k*d";
    printf("%s",infixTOpostfix(sp,infix));
    return 0;
}