// Insert a node at the perticular position in the ordered linked list
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

void deleteNode(struct Node** head, int dataitem) {
    if (*head == NULL) {
        printf("Linked list is empty...\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* pre = NULL;

    // If the node to be deleted is the first node
    if (temp != NULL && temp->data == dataitem) {
        *head = temp->next;  // Change head
        free(temp);  // Free the node
        printf("Node deleted succesfully\n");
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != dataitem) {
        pre = temp;
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        printf("Node with value %d not found.\n", dataitem);
        return;
    }

    // Unlink the node from the list
    pre->next = temp->next;
    free(temp);  // Free the memory of the deleted node
    printf("Middel Node deleted succesfully\n");
}

// display all the element of the linked list
void printList(struct Node* node){
    while (node != NULL){
        printf("%d -> ",node -> data);
        node = node -> next;
    }
    printf("NULL\n");
}
int main(){
    // Initilize the head of the list as NULL
    struct Node* head = NULL;

    // Insert node at various position
    insertAtAnywhere(&head, 40);
    insertAtAnywhere(&head, 20);
    insertAtAnywhere(&head, 30);
    insertAtAnywhere(&head, 25);
    insertAtAnywhere(&head, 50);

    printf("Data of linked list: ");
    printList(head);

    deleteNode(&head, 30);
    printf("After deleting middel(30) Node: ");
    printList(head);

    return 0;
}