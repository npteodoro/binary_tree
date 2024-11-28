#include "functions.h"
#include "binary_tree.h"

void printTree(int id, void* data) {
    printf("Node ID: %d, Data: %s\n", id, (char*)data);
}

void testTreeOperations() {
    TreeNode* root = NULL;
    
    // Test insertion
    printf("\n=== Testing Insertion ===\n");
    root = insertNode(root, 50, strdup("Root"));
    root = insertNode(root, 30, strdup("Left"));
    root = insertNode(root, 70, strdup("Right"));
    root = insertNode(root, 20, strdup("Left-Left"));
    root = insertNode(root, 40, strdup("Left-Right"));
    root = insertNode(root, 60, strdup("Right-Left"));
    root = insertNode(root, 80, strdup("Right-Right"));
    
    // Test size
    printf("\nTree size: %d\n", getSize(root));
    
    // Test traversals
    printf("\n=== In-Order Traversal ===\n");
    traverseInOrder(root, printTree);
    
    printf("\n=== Pre-Order Traversal ===\n");
    traversePreOrder(root, printTree);
    
    printf("\n=== Post-Order Traversal ===\n");
    traversePostOrder(root, printTree);
    
    // Test search
    printf("\n=== Testing Search ===\n");
    TreeNode* found = searchNode(root, 30);
    if (found)
        printf("Found node 30: %s\n", (char*)found->data);
    
    found = searchNode(root, 99);
    if (!found)
        printf("Node 99 not found (correct)\n");
    
    // Test min/max
    printf("\n=== Testing Min/Max ===\n");
    TreeNode* min = findMin(root);
    TreeNode* max = findMax(root);
    printf("Minimum value: %d (%s)\n", min->id, (char*)min->data);
    printf("Maximum value: %d (%s)\n", max->id, (char*)max->data);
    
    // Test deletion
    printf("\n=== Testing Deletion ===\n");
    printf("Deleting node 30 (has two children)...\n");
    root = deleteNode(root, 30);
    printf("After deletion (In-Order):\n");
    traverseInOrder(root, printTree);
    
    printf("\nDeleting node 20 (leaf node)...\n");
    root = deleteNode(root, 20);
    printf("After deletion (In-Order):\n");
    traverseInOrder(root, printTree);
    
    // Clean up
    printf("\n=== Cleaning Up ===\n");
    destroy(root);
    printf("Tree destroyed successfully\n");
}
