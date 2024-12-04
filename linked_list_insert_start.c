// Insert the element at the start of linked list
#include<stdio.h>
#include<stdlib.h>

// Our node
struct Node{
    int data;
    struct Node* next;
};

// Insert an element at biginning
void insertAtBiginning(struct Node** head, int newData){
    // memory allocate to the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = newData;
    newNode -> next = *head;
    *head = newNode;
}

// Display all the element of the linked list
void printList(struct Node* node){
    while(node != NULL){
        printf("%d -> ",node -> data);
        node = node -> next;
    }
    printf("NULL\n");
}

int main(){
    // Initilize the head of the list as NULL
    struct Node* head = NULL;

    // Insert node at various position
    insertAtBiginning(&head, 20);
    insertAtBiginning(&head, 30);
    insertAtBiginning(&head, 40);

    printf("Data of linked list: \n");
    printList(head);

    return 0;
}