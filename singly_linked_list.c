#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void createNode(struct Node** head,int newdata){
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
    printf("Node deleted succesfully\n");
}

// Display all the element of the linked list
void printList(struct Node* node){
    while(node != NULL){
        printf("%d -> ",node -> data);
        node = node -> next;
    }
    printf("NULL\n");
}

void countNode(struct Node* node){
    if(node == NULL){
        printf("The Linked list is empty\n");
        return;
    }
    
    int count = 1;
    // Traverse to the last of the linked list
    while(node -> next != NULL){
        count++;
        node = node -> next;
    }
    printf("Total number of node = %d\n",count);
}

// find element
void searchNode(struct Node* head, int key){
    if(head == NULL){
        printf("The linked list is empty\n");
        return;
    }
    struct Node* temp = head;
    int count = 1;

    while(temp != NULL){
        if(temp -> data == key){
            printf("%d succesfully found at position %d\n",key,count);
            return;
        }
        temp = temp -> next;
        count++;
    }
    printf("%d not fount in the linked list\n",key);
}

int main(){
    // Initilize the head of the list as NULL
    struct Node* head = NULL;
    int choice, newdata, dataitem, key;
    while(1){
        printf("1. Create a node\n");
        printf("2. Delete a node\n");
        printf("3. Displaty all the data of node\n");
        printf("4. Count node\n");
        printf("5. Search a data\n");
        printf("6. Exit\n");
        printf("chose an option : ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter a data for a node: ");
                scanf("%d",&newdata);
                createNode(&head, newdata);
                break;
            case 2:
                printf("Enter a value of which node want to delete: ");
                scanf("%d",&dataitem);
                deleteNode(&head, dataitem);    
                break;
            case 3:
                printList(head);
                break;
            case 4:
                countNode(head);
                break;
            case 5:
                printf("Enter the value to be search: ");
                scanf("%d",&key);
                searchNode(head, key);
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Invalid choice...\nTry again");        

        }
    }
}