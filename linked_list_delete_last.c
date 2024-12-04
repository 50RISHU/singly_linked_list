// Delet the last node from the linked list
#include<stdio.h>
#include<stdlib.h>

// Our node
struct Node{
    int data;
    struct Node* next;
};

// insert a node
void insertAtAnywhere(struct Node** head,int newdata){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> data = newdata;
    newNode -> next = NULL;

    // If there is no any node so newnode will be first node
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // When new node data is less then first node, it insert at the biginning
    struct Node* temp = *head;
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

// Delete a node from last
void deleteLastNode(struct Node** head){
    // Check node is empty or not
    if(head == NULL){
        printf("linked list is enppty!");
        return;
    }

    // declare temperery variable
    struct Node* temp = *head;
    struct Node* pre;

    // When there is only one node, delete this node
    if(temp -> next == NULL){
        head = NULL;
        free(head);
    }
    else{
        // Traverse to the last node
        while(temp -> next != NULL){
            pre = temp; // pre variable store second last node 
            temp = temp -> next;
        }
        pre -> next = NULL;
        free(temp); // Delete the last node
    }

}

// Display the all the element of the linked list
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
    insertAtAnywhere(&head, 40);
    insertAtAnywhere(&head, 20);
    insertAtAnywhere(&head, 30);
    insertAtAnywhere(&head, 25);

    printf("original linked list...");
    printList(head);
    printf("\n");
    
    printf("After deleting last node...");
    deleteLastNode(&head);
    printList(head);

    return 0;
}