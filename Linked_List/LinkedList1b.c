#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct LinkedList {
    Node* head;
};

typedef struct LinkedList LinkedList;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(LinkedList* list, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    Node* newNode = createNode(data);

    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    for (int i = 0; i < position - 1; ++i) {
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(LinkedList* list, int data) {
    Node* newNode = createNode(data);

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to display the contents of the linked list
void displayLinkedList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList list;
    list.head = NULL;

    insertAtBeginning(&list, 10);
    insertAtEnd(&list, 20);
    insertAtPosition(&list, 15, 1);

    displayLinkedList(&list);

    return 0;
}