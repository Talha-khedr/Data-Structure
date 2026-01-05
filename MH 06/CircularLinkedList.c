#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode;  
    return newNode;
}

void insertEnd(int value) {
    struct Node *newNode = createNode(value);
    struct Node *temp;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->data == value && head->next == head) {
        free(head);
        head = NULL;
        printf("Node deleted\n");
        return;
    }

    if (head->data == value) {
        prev = head;
        while (prev->next != head)
            prev = prev->next;

        prev->next = head->next;
        free(head);
        head = prev->next;
        printf("Node deleted\n");
        return;
    }

    prev = head;
    temp = head->next;
    while (temp != head && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted\n");
}

void search(int value) {
    struct Node *temp = head;
    int pos = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        if (temp->data == value) {
            printf("Value found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Value not found\n");
}

void traverse() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Traversal: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Traverse");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            search(value);
            break;

        case 4:
            traverse();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
