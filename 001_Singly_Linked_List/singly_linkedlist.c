/*
In this program, we define a struct Node that has two fields - 
data and next. data holds the value of the current node, and next points to the next node in the list.
*/

#include <stdio.h>
#include <stdlib.h>

/*

-> This is a definition of a struct in C called Node that represents a single node of a singly linked list. It has two fields:
-> data - This field holds the actual value or data that the node contains. In this example, it is an integer.
-> next - This field is a pointer to the next node in the linked list. It is a self-referential pointer, meaning that it points to another Node struct of the same type. If there is no next node, the next pointer is set to NULL.
-> By having a next pointer, we can link multiple Node structs together to form a singly linked list, where each node contains a value and a pointer to the next node in the list. This allows us to traverse the list starting from the first node (also known as the head of the list) and following the next pointers to visit each subsequent node until we reach the end of the list.

*/
struct Node {
    int data;
    struct Node* next;
};

/*
We also define a function createNode() that creates a new node with the given data and returns a pointer to it.
*/

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
The function insertAtEnd() inserts a new node at the end of the linked list. 
It takes a pointer to the head of the list, creates a new node with the given data, and adds it to the end of the list.
*/

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    printList(head);
    return 0;
}
