#include "functions.h"
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void printNode(const void *id, const void *data) {
    printf("Node ID: %d", *(int*)id);
    if (data != NULL)
        printf(", Data: %d", *(int*)data);
    printf("\n");
}

int compareInts(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void *createIntCopy(int value) {
    int *copy = (int*)malloc(sizeof(int));
    if (copy != NULL)
        *copy = value;
    return copy;
}

void testTreeOperations(void) {
    TreeNode *root = NULL;
    printf("Testing BST Operations:\n\n");

    // Test insertion
    printf("1. Inserting values: 5, 3, 7, 1, 9\n");
    root = insertNode(root, createIntCopy(5), createIntCopy(50), compareInts);
    root = insertNode(root, createIntCopy(3), createIntCopy(30), compareInts);
    root = insertNode(root, createIntCopy(7), createIntCopy(70), compareInts);
    root = insertNode(root, createIntCopy(1), createIntCopy(10), compareInts);
    root = insertNode(root, createIntCopy(9), createIntCopy(90), compareInts);

    printf("\nIn-order traversal after insertion:\n");
    traverseInOrder(root, printNode);

    // Test search
    printf("\n2. Searching for value 7:\n");
    TreeNode *found = searchNode(root, &(int){7}, compareInts);
    if (found) {
        printf("Found node: ");
        printNode(found->id, found->data);
    } else {
        printf("Node not found!\n");
    }

    // Test min/max
    printf("\n3. Finding min and max values:\n");
    TreeNode *min = findMin(root);
    TreeNode *max = findMax(root);
    printf("Minimum value: ");
    printNode(min->id, min->data);
    printf("Maximum value: ");
    printNode(max->id, max->data);

    // Test clone tree
    printf("\n4. Cloning tree...\n");
    TreeNode *clone = cloneTree(root);
    printf("In-order traversal of cloned tree:\n");
    traverseInOrder(clone, printNode);

    // Test deletion one child
    printf("\n5. Deleting value 3:\n");
    root = deleteNode(root, &(int){3}, compareInts);
    printf("In-order traversal after deletion:\n");
    traverseInOrder(root, printNode);
    printf("\nIn-order traversal of cloned tree:\n");
    traverseInOrder(clone, printNode);

    /// Test deletion two children
    printf("\n5. Deleting value 5:\n");
    root = deleteNode(root, &(int){5}, compareInts);
    printf("In-order traversal after deletion:\n");
    traverseInOrder(root, printNode);

    // Test tree size
    printf("\n7. Tree size: %d nodes\n", getSize(root));

    // Clean up
    printf("\n8. Destroying tree...\n");
    destroy(root);
    printf("Tree destroyed.\n");
}

