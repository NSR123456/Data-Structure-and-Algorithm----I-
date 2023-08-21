#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data);
void pop();
void peek();
void display();
int isFull();
int isEmpty();

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
int isFull(){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if(newnode == NULL)
        return 1;
    else return 0;
}
int isEmpty()
{
    if(top == NULL)
        return 1;
    else return 0;
}
void push(int data) {
        if(isEmpty()) printf("\nThe Stack is empty now.\n");
        if(isFull()) printf("\nStack is Full.%d cannot be pushed.\n",data);
        else{
            struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
            newnode->data = data;
            if(isEmpty()) {

                newnode->next = NULL;
                top = newnode;
            }
            else{
                newnode->next = top;
                top = newnode;
            }
        }
}
void pop()
{
    if(isEmpty()){
        printf("\nThe Stack is empty now.\n");
        return;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
    printf("\nDeleted top element.\n");
}

void peek(){

    if(isEmpty()){
            printf("Underflow\n");
            return;
    }
     printf("\nThe top element: %d ",top->data);
}

void display()
{
    printf("\nCurrent state of stack:\n");
    struct Node* temp = top;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

