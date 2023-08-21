#include<stdio.h>
#include<stdlib.h>
int arr[10];
int top = -1, size = 10;

void push(int data);
void pop();
void peek();
void display();

int main()
{
    push(5);
    push(3);
    push(6);
    push(9);
    push(2);
    push(1);
    display();
    pop();
    display();
    pop();

    peek();
    pop();
    display();
    pop();
    pop();

    peek();
    pop();
    pop();

    peek();
    return 0;
}
void push(int data) {
        if(top == -1) printf("\nThe Stack is empty now.\n");
        if(top == size-1) printf("\nStack is Full.%d cannot be pushed.\n",data);
        else{
            top=top + 1;
        arr[top] = data;
        }
}
void pop()
{
    if(top == -1){
        printf("\nThe Stack is empty now.\n");
        return;
    }
    top--;
    printf("\nDeleted top element.\n");
}

void peek(){

    if(top== -1){
            printf("Underflow\n");
            return;
    }
     printf("\nThe top element: %d ",arr[top]);
}

void display()
{
    printf("\nCurrent state of stack:\n");
    for(int i=top;i>=0;i--)
        printf("%d ",arr[i]);
}

