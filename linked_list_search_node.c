// Search a Node in the singly linked list
#include<stdio.h>
#include<stdlib.h>

// Our node
struct Node{
    int data;
    struct Node* next;
};

// Insert a node
void insertAtAnywhere(struct Node** head,int newdata){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = newdata;
    newNode -> next = NULL;

    // If there is no any node so newnode will be first node
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;

    // When new node data is less then first node, it insert at the biginning
    if(newNode -> data <= temp -> data){
        newNode -> next = *head;
        *head = newNode;
        return;
    }  

    // Find the perfect position to insert 
    while(temp -> next != NULL && temp -> next -> data <= newNode -> data){
        temp = temp -> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

// find element
void searchNode(struct Node* head, int key){
    struct Node* temp = head;
    int count = 1;

    while(temp -> next != NULL){
        if(temp -> data == key){
            printf("%d succesfully found at position %d",key,count);
            return;
        }
        temp = temp -> next;
        count++;
    }
    printf("%d not fount in the linked list",key);
}

int main(){
    // Initilize the head of the list as NULL
    struct Node* head = NULL;
    int n;

    // Insert node at various position
    insertAtAnywhere(&head, 40);
    insertAtAnywhere(&head, 20);
    insertAtAnywhere(&head, 30);
    insertAtAnywhere(&head, 25);

    printf("Enter a value: ");
    scanf("%d",&n);

    searchNode(head, n);

    return 0;
}