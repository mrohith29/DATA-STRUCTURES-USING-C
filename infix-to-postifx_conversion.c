#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define stacksize 100
char stack[stacksize];
int top=-1;


void push(char element)
{
    top=top+1;
    stack[top]=element;
}

char pop()
{
    char delement;
    delement=stack[top];
    top=top-1;
     return (delement);
}

int priority(char element)
{
    switch (element)
    {
    case '#': return 0;
        
    case '(': return 1;
        
    case '+':
    case '-': return 2;

    case '*':
    case '/':
    case '%': return 3;

    case '^': return 4;
    }
}
void main()
{
    char infix[stacksize],postfix[stacksize],ch,element;
    int i=0,k=0;
    printf("Enter the infix expression\n");
    scanf("%s",infix);
    push('(');
    while((ch=infix[i++])!='\0')
    {
        if(ch=='(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            postfix[k++]=ch;
        }
        else if(ch==')')
        {
            while(stack[top]!='(')
            {
                postfix[k++]=pop();
            }
            pop(); 
        }
        else 
        {
            while(priority(stack[top])>=priority(ch))
            {
                postfix[k++]=pop();
            }
            push(ch);
        }
    }
    while(stack[top]!='(')
        {
            postfix[k++]=pop();
        }
    postfix[k]='\0';
    printf("\n%s",postfix);
}



