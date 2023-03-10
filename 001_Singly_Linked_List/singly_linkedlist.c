/*

Step 1:
In this program, we define a struct Node that has two fields - 
data and next. data holds the value of the current node, and next points to the next node in the list.
*/

#include <stdio.h>
#include <stdlib.h>

/*
Step 2:
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

Step 3:
We also define a function createNode() that creates a new node with the given data and returns a pointer to it.
*/

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
Step 4:
The function insertAtEnd() inserts a new node at the end of the linked list. 
It takes a pointer to the head of the list, creates a new node with the given data, and adds it to the end of the list.

--> This is a function in C called insertAtEnd() that adds a new node with the given data value to the end of a singly linked list. 
Here is what each line of the function does:

--> struct Node* newNode = createNode(data); - This calls a function called createNode() to create a new Node struct with the given data value. 
The new node will be the last node in the linked list.

--> if (*head == NULL) { *head = newNode; return; } - This checks if the head pointer is NULL, which means that the list is empty. 
If so, the head pointer is updated to point to the new node, and the function returns.

--> struct Node* temp = *head; - This declares a pointer called temp and initializes it to the head pointer. 
This pointer will be used to traverse the linked list and find the last node.

--> while (temp->next != NULL) { temp = temp->next; } - This loops through the linked list using the temp pointer until it reaches the last node. 
The loop condition checks if the next pointer of the current node is NULL, which means that it is the last node in the list.

--> temp->next = newNode; - This updates the next pointer of the last node to point to the new node, 
effectively adding the new node to the end of the linked list.

--> The function takes in a double pointer head as its first argument because it needs to modify the head pointer itself. 
By passing in a pointer to the head pointer, we can update the head pointer to point to the first node in the list 
if it was previously NULL, or leave it unchanged if there were already nodes in the list.



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

/*
Step 5:
This is the main() function of a C program that demonstrates the use of a singly linked list. Here is what each line does:

struct Node* head = NULL; - This declares a pointer to a Node struct called head and initializes it to NULL. This will be the starting point of our linked list.

--> insertAtEnd(&head, 1); - This calls the insertAtEnd() function with the address of the head pointer and the value 1. 
The insertAtEnd() function creates a new node with the value 1 and appends it to the end of the linked list.

--> insertAtEnd(&head, 2); - This calls the insertAtEnd() function again with the address of the head pointer and the value 2. 
The insertAtEnd() function creates a new node with the value 2 and appends it to the end of the linked list.

--> insertAtEnd(&head, 3); - This calls the insertAtEnd() function again with the address of the head pointer and the value 3. 
The insertAtEnd() function creates a new node with the value 3 and appends it to the end of the linked list.

--> insertAtEnd(&head, 4); - This calls the insertAtEnd() function again with the address of the head pointer and the value 4. 
The insertAtEnd() function creates a new node with the value 4 and appends it to the end of the linked list.

--> printList(head); - This calls the printList() function with the head pointer as an argument. 
The printList() function traverses the linked list starting from the head and prints out the data in each node.

return 0; - This returns an exit status of 0, indicating that the program has run successfully.

--> Overall, this main() function creates a linked list with four nodes containing 
the values 1, 2, 3, and 4, and then prints out the contents of the list.

*/

int main() {
    struct Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    printList(head);
    return 0;
}
