//code for Postfix Evaluation.
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 40

float stack[SIZE];
int top = -1;

void push(float n)
{
	if (top < SIZE -1)
	{
		stack[++top] = n;
	}
	else
	{
		printf("Stack is full!\n");
		exit(-1);
	}
}
float pop()
{	
    float n;
	if (top > -1)
	{
		n = stack[top];
		stack[top--] = -1;
		return n;
	}
	else
	{
		printf("Invalid Postfix expression!\n");
		exit(-1);
	}
}	

int main()
{
	int i;
	float a, b, result, pEval;
	char ch;
	
	char postfix[SIZE];
	
	
	printf("\nEnter a postfix expression: ");
	scanf("%s",postfix);

	for(i=0; postfix[i] != '\0'; i++)
	{
		ch = postfix[i];

		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			b = pop();
			a = pop();
			
			switch(ch)
			{
				case '+': result = a+b;
					  break;
				case '-': result = a-b;
					  break;
				case '*': result = a*b;
					  break;
				case '/': result = a/b;
					  break;
			}
			
			push(result);
		}		
	
	}
    
    if(top==0)
    {
	    pEval = pop();
		printf("\nThe postfix evaluation is: %f\n",pEval);
    }
    else 
        printf("Invalid Postfix expression");
	
	return 0;
}