//Circular Linked List
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* tail = NULL;

void InsertToEmpty(int data)
{
    if(tail ==  NULL){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = data;
    newnode ->next = newnode;
    tail = newnode;
    }
    else printf("The list is not empty.\n");
}

void insertBegin(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode -> data = data;
    newnode -> next = tail->next;
    tail->next = newnode;

}
void InsertEnd(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode -> next = tail->next;
    tail->next = newnode;
    tail = newnode;
}

void InsertAtPosition(int data,int pos){
    if(!tail) {
        printf("List is empty!\n");
        return;
    }
    if(pos==1) {
        insertBegin(data);
        return;
    }
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node* head = tail->next;
    for(int i=0;i<pos-2;i++) {
        head = head->next;
    }
    if(head == tail){
       InsertEnd(data);
       return;
    }
    newnode->next = head->next;
    head->next = newnode;
}

void DeleteFirst(){
    if(tail==NULL) {
            printf("List is empty");
            return;
    }
    struct Node* head = tail->next;
    if(head==tail){
        free(tail);
        tail = NULL;
    }
    tail->next= head->next;
    free(head);
}

void deleteAt(int pos) {
    struct Node* temp, *temp2;
    temp = tail->next;
    for(int i=0; i< pos-2; i++) {
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

int count(struct Node* tail){
    int count = 0;
    if(tail == NULL) {
        return count;
    }
    struct Node* head = tail->next;
    while(head != tail) {
        head = head -> next;
        count++;
    }
    count++;
    return count;
}

void printList(){
    struct Node* head = tail -> next;
    do{
        printf("%d ",head->data);
        head = head ->next;
    }while(head != tail->next);
    printf("\n");
}


int main()
{
    printf("No. of node = %d\n", count(tail));

    printf("\nInserting 5 to the empty list\n");
    InsertToEmpty(5);
    printList();

    printf("\nInserting 7 at the beginning\n");
    insertBegin(7);
    printList();

    printf("\nInserting 11 at the end\n");
    InsertEnd(11);
    printList();

    printf("\nInserting 9 at position 3\n");
    InsertAtPosition(9, 3);
    printList();

    printf("\nDeleting 1st element\n");
    DeleteFirst();
    printList();

    printf("\nDeleting element at position 2\n");
    deleteAt(2);
    printList();

    printf("\nNo. of node = %d\n", count(tail));


}
