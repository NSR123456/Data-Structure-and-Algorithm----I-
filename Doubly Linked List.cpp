//Doubly Linked List Class Work

#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
    struct Node* prev;
    struct Node* next;
    int data;
 };

struct Node* head;

struct Node* getnewnode(int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    //new_node->data = (struct Node*) malloc(sizeof(struct Node));
    new_node-> data = new_data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
};


void InsertAtHead(int new_data)
{
    struct Node* new_node = getnewnode(new_data);
    if(head == NULL){
        head = new_node;
        return;
    }
    head->prev = new_node;
    new_node -> next = head;
    head = new_node;
}
void printlist(struct Node* node){
    while(node != NULL)
    {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}
//Insert At a Position
void Insert(int data, int pos){
    if(pos==1){
            InsertAtHead(data);
            return;
    }
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* prev = head;
    newnode->data = data;
    newnode->next =NULL;
    for(int i=0; i< pos-2; i++){
        if(prev){
            prev = prev -> next;
        }
        newnode ->next = prev -> next;
        prev->next = newnode;
    }
}
void InsertAtEnd(int data)
{
    struct Node* new_node = getnewnode(data);
    struct Node* last = head;
    if(head== NULL)
    {
        head = new_node;
        return;
    }
    while(last ->next != NULL)
        last = last -> next;
    last ->next = new_node;
    new_node-> prev = last;
    return;
}
//Delete At First Position
void deletefirst()
{
    struct Node* copy1 = head;
    head = head ->next;
    free(copy1);
    head ->prev = NULL;
    return;
}
//Delete At a Position
void deleteAt(int position) {
    struct Node* temp = head;
    struct Node* temp1 = NULL;
    int i;

    for(i=0;i<position-2;i++) {
        temp = temp->next;
    }
    temp1= temp->next;
    if(temp1->next == NULL){
        temp->next = NULL;
        free(temp1);
        return;
    }

    temp->next = temp1->next;
    temp1->next->prev = temp;
    free(temp1);
}
/*void deleteend(){
    struct Node* temp2 = head;
    while(temp2 != NULL){

        temp2 = temp2->next;
    }
    temp ->next = NULL;
    free(temp2);
}*/

int main()
{

    InsertAtHead(2);
    InsertAtHead(3);
    cout<<"Raw List:"<<endl;
    printlist(head);
    cout<<"Insrting 1 at first:"<<endl;
    InsertAtHead(1);
    printlist(head);
    cout<<"Inserting 9 at end:"<<endl;
    InsertAtEnd(9);
    printlist(head);
    cout<<"Insering 5 at 3rd pos:"<<endl;
    Insert(5, 3);
    printlist(head);
    cout<<"Deleting 1st element:"<<endl;
    deletefirst();
    printlist(head);
    cout<<"Deleting 2nd element:"<<endl;
    deleteAt(2);
    printlist(head);
    //deleteend()
    //printlist(head);
}
