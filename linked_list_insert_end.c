// Insert an element at the end of the linked list
#include<stdio.h>
#include<stdlib.h>

// Our node 
struct Node{
    int data;
    struct Node* next;
};

// Insert a node at last
void insertAtEnd(struct Node** head,int newdata){
    // Memory allocate to the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = newdata;
    newNode -> next = NULL;

    // If there is no any node so newnode will be first node
    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

// Display all element of the linked list
void printList(struct Node* node){
    while (node != NULL){
        printf("%d -> ",node -> data);
        node = node -> next;
    }
    printf("NULL");
}

int main(){
    // Initilize the head of the list as NULL
    struct Node* head = NULL;

    // Insert node at various position
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Data of linked list: ");
    printList(head);

    return 0;
}