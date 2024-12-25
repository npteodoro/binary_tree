#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stddef.h>

// Node for the binary tree
typedef struct TreeNode {
    void *id;
    void *data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function pointer type for traversal callbacks
typedef void (*TraversalCallback)(const void *, const void *);

// Function pointer type for comparison functions
typedef int (*CompareFunction)(const void *, const void *);

/* ================= Core Functions ================= */

/**
 * @brief Creates a new tree node with given id and data
 * @param id Integer value to store in the node
 * @param data Pointer to data to associate with the node
 * @return TreeNode *Pointer to newly created node, NULL if allocation fails
 */
TreeNode *createNode(const void *, const void *);

/**
 * @brief Inserts a new node with given id and data into the binary search tree
 * @param root Pointer to root node of the tree
 * @param id Integer value to insert
 * @param data Pointer to data to associate with the node
 * @param compare Function to compare node values
 * @return TreeNode *Pointer to root node after insertion
 */
TreeNode *insertNode(TreeNode *, const void *, const void *, CompareFunction);

/**
 * @brief Deletes node with given id from the binary search tree
 * @param root Pointer to root node of the tree
 * @param id Integer value to delete
 * @param compare Function to compare node values
 * @return TreeNode *Pointer to root node after deletion
 */
TreeNode *deleteNode(TreeNode *, const void *, CompareFunction);

/**
 * @brief Searches for a node with given id in the binary search tree
 * @param root Pointer to root node of the tree
 * @param id Integer value to search for
 * @param compare Function to compare node values
 * @return TreeNode *Pointer to found node, NULL if not found
 */
TreeNode *searchNode(const TreeNode *, const void *, CompareFunction);

/* ================= Utility Functions ================= */

/**
 * @brief Finds the node with minimum value in the tree/subtree
 * @param root Pointer to root node of the tree/subtree
 * @return TreeNode *Pointer to node with minimum value
 */
TreeNode *findMin(const TreeNode *);

/**
 * @brief Finds the node with maximum value in the tree/subtree
 * @param root Pointer to root node of the tree/subtree
 * @return TreeNode *Pointer to node with maximum value
 */
TreeNode *findMax(const TreeNode *);

/**
 * @brief Returns the number of nodes in the tree
 * @param root Pointer to root node of the tree
 * @return int Number of nodes in the tree
 */
int getSize(const TreeNode *);

/* ================= Memory Management ================= */

/**
 * @brief Creates a deep copy of node data
 * @param source Pointer to source data
 * @param size Size of data to copy
 * @return void* Pointer to new copy, NULL if allocation fails
 */
void *deepCopyData(const void *source, size_t size);

/**
 * @brief Creates a deep copy of the entire tree
 * @param root Pointer to root node of the tree to copy
 * @return TreeNode* Pointer to root of new copied tree
 */
TreeNode *cloneTree(const TreeNode *);

/**
 * @brief Frees a single node and its contents
 * @param node Pointer to node to free
 */
void freeNode(TreeNode *node);

/**
 * @brief Recursively frees all nodes in the tree
 * @param root Pointer to root node of the tree
 */
void destroy(TreeNode *);

/* ================= Traversal Functions ================= */

/**
 * @brief Performs in-order traversal of the tree, applying function to each node
 * @param root Pointer to root node of the tree
 * @param callback Function pointer to apply to each node's id and data
 */
void traverseInOrder(const TreeNode *, TraversalCallback);

/**
 * @brief Performs pre-order traversal of the tree, applying function to each node
 * @param root Pointer to root node of the tree
 * @param callback Function pointer to apply to each node's id and data
 */
void traversePreOrder(const TreeNode *, TraversalCallback);

/**
 * @brief Performs post-order traversal of the tree, applying function to each node
 * @param root Pointer to root node of the tree
 * @param callback Function pointer to apply to each node's id and data
 */
void traversePostOrder(const TreeNode *, TraversalCallback);

#endif // BINARY_TREE_H
