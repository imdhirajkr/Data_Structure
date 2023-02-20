"""
In this program, we define a struct Node that has two fields - 
data and next. data holds the value of the current node, and next points to the next node in the list.
"""

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

"""
We also define a function createNode() that creates a new node with the given data and returns a pointer to it.
"""

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

"""
The function insertAtEnd() inserts a new node at the end of the linked list. 
It takes a pointer to the head of the list, creates a new node with the given data, and adds it to the end of the list.
    
"""

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
