
//Balanced Parenthesis

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
int checkPair(char val1, char val2) {
    return ((val1 == '(' && val2 == ')') || (val1 == '[' && val2 == ']') || (val1 == '{' && val2 == '}') );
}

int checkBalanced(char expr[], int len) {
     for(int i=0; i< len; i++){
        if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(expr[i]);
           }
        else{
            if(top == -1) return 0;
            else if(checkPair(peek(), expr[i])) {
                pop(); continue;
            }
          }
        }
        if(top == -1) return 1;

     return 0;
}

int main()
{
    char exp[MAX] = "(({(([[[))}))";
    int len = strlen(exp);
    checkBalanced(exp, len)? printf("Balanced"): printf("Not Balanced");
    return 0;
}
