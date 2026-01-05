#include <stdio.h>

#define MAX 50

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void maxHeapifyUp(int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] > heap[parent]) {
        swap(&heap[index], &heap[parent]);
        maxHeapifyUp(parent);
    }
}

void insertMaxHeap(int value) {
    heap[size] = value;
    size++;
    maxHeapifyUp(size - 1);
}

void displayMaxHeap() {
    int i;
    printf("Max Heap: ");
    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}


void minHeapifyUp(int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] < heap[parent]) {
        swap(&heap[index], &heap[parent]);
        minHeapifyUp(parent);
    }
}

void insertMinHeap(int value) {
    heap[size] = value;
    size++;
    minHeapifyUp(size - 1);
}

void displayMinHeap() {
    int i;
    printf("Min Heap: ");
    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert Max Heap");
        printf("\n2. Display Max Heap");
        printf("\n3. Insert Min Heap");
        printf("\n4. Display Min Heap");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertMaxHeap(value);
            break;

        case 2:
            displayMaxHeap();
            break;

        case 3:
            size = 0; 
            printf("Enter value: ");
            scanf("%d", &value);
            insertMinHeap(value);
            break;

        case 4:
            displayMinHeap();
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
