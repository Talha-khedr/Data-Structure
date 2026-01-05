#include <stdio.h>

#define MAX 50

int tree[MAX];   
int n;           

void preorder(int index) {
    if (index >= n)
        return;

    printf("%d ", tree[index]);
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

void inorder(int index) {
    if (index >= n)
        return;

    inorder(2 * index + 1);
    printf("%d ", tree[index]);
    inorder(2 * index + 2);
}

void postorder(int index) {
    if (index >= n)
        return;

    postorder(2 * index + 1);
    postorder(2 * index + 2);
    printf("%d ", tree[index]);
}

int main() {
    int i;

    printf("Enter number of nodes in tree: ");
    scanf("%d", &n);

    printf("Enter tree elements (level-wise):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &tree[i]);

    printf("\nPreorder Traversal: ");
    preorder(0);

    printf("\nInorder Traversal: ");
    inorder(0);

    printf("\nPostorder Traversal: ");
    postorder(0);

    printf("\n");

    return 0;
}
