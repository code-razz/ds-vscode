#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 40
char stack[MAX];
int top = -1;

int prec(char x) {
    int p;
    switch(x) {
        case '+':
        case '-':
            p = 3;
            break;
        case '*':
        case '/':
            p = 4;
            break;
        case '(':
            p = 2;
            break;
        case '#':
            p = 1;
            break;
    }
    return p;
}

void push(char n) {
    if (top < MAX - 1) {
        top++;
        stack[top] = n;
    } else {
        printf("Stack is full!\n");
        exit(-1);
    }
}

char pop() {
    char n;
    if (top > -1) {
        n = stack[top];
        top--;
        return n; 
    }
}

int main() {
    push('#');
    int i, x, count = 0;
    char ch;
    char postfix[MAX], infix[MAX];

    printf("\nEnter an infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isalnum(ch))
            x = 1;
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            x = 2;
        else
            x = ch;

        switch (x) {
            case 1:
                postfix[count] = ch;
                count++;
                break;
            case 2:
                if (prec(stack[top]) < prec(ch))
                    push(ch);
                else {
                    while (prec(stack[top]) >= prec(ch)) {
                        postfix[count] = pop();
                        count++;
                    }
                    push(ch);
                }
                break;
            case ')':
                while (stack[top] != '(') {
                    postfix[count] = pop();
                    count++;
                }
                pop(); // Discard '('
                break;
            case '(':
                push(ch);
                break;
        }
    }

    // Pop any remaining operators from the stack
    while (stack[top] != '#') {
        postfix[count] = pop();
        count++;
    }

    postfix[count] = '\0'; // Null-terminate the postfix expression

    if (stack[top] == '#') {
        printf("\nThe postfix expression is: %s\n", postfix);
    } else {
        printf("Invalid Infix expression\n");
    }

    return 0;
}