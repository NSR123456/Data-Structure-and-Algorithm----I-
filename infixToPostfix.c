#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
char stk[20];
int top = -1;

int isEmpty() { return top == -1; }
int isFull() {
    return top == MAX - 1;
}
char peek()
{
    return stk[top];
}
char pop()
{
    if(isEmpty()) return -1;
    char ch = stk[top];
    top--;
    return ch;
}

void push(char opr)
{
    if(isFull())
        printf("Stack Full!!!");
    else{
        top++;
        stk[top] = opr;
    }
}

int checkIf(char ch)
{
    return ( (ch >='a' && ch <= 'z') || (ch>= 'A' && ch <= 'Z') );
}
int precedence(char ch)
{
    switch(ch)
    {
    case '+':
    case'-':
        return 1;
    case '*' :
    case '/':
        return 2;
    case '^' :
        return 3;
    }
    return -1;
}

int convert(char* exp)
{
    int i, j;
    for(i= 0, j = -1; exp[i]; ++i)
    {
        if(checkIf(exp[i]))
        {
            exp[++j] = exp[i];
        }
        else if(exp[i]=='(') push(exp[i]);
        else if(exp[i] == ')')
        {
            while(!isEmpty() && peek() != '(')
                    exp[++j] = pop();
            if(!isEmpty() && peek()!= '(') return -1;
            else pop();
        }
        else{
            while(!isEmpty() && precedence(exp[i] ) <= precedence(peek()))
                exp[++j] = pop();
            push(exp[i]);
        }
    }
    while(!isEmpty())
        exp[++j] = pop();
    exp[++j] = '\0';
    printf("%s", exp);
}

int main()
{
    char exp[] = "((x+(y*z))-w)";
    convert(exp);
    return 0;
}
