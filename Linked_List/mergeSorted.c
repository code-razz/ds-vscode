#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to merge two sorted linked lists
Node* MergeLists(Node* list1, Node* list2) {
    Node* mergedList = NULL; // Initialize mergedList to NULL

    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    // Choose the head of the merged list based on the smaller first element
    if (list1->data < list2->data) {
        mergedList = list1;
        list1 = list1->next;
    } else {
        mergedList = list2;
        list2 = list2->next;
    }

    Node* current = mergedList; // Pointer to the current node in the merged list

    // Merge the two lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // Append the remaining nodes from list1 or list2, if any
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return mergedList;
}

// Function to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Example usage
    Node* list1 = createNode(1);
    list1->next = createNode(3);
    list1->next->next = createNode(5);

    Node* list2 = createNode(2);
    list2->next = createNode(4);
    list2->next->next = createNode(6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    Node* mergedList = MergeLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
