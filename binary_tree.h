#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for the binary tree
typedef struct TreeNode {
    int id;
    void* data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function pointer type for traversal callbacks
typedef void (*TraversalCallback)(int, void*);

/* ================= Core Functions ================= */

/**
 * @brief Creates a new tree node with given id and data
 * @param id Integer value to store in the node
 * @param data Pointer to data to associate with the node
 * @return TreeNode* Pointer to newly created node, NULL if allocation fails
 */
TreeNode* createNode(int id, void* data);

/**
 * @brief Inserts a new node with given id and data into the binary search tree
 * @param root Pointer to root node of the tree
 * @param id Integer value to insert
 * @param data Pointer to data to associate with the node
 * @return TreeNode* Pointer to root node after insertion
 */
TreeNode* insertNode(TreeNode* root, int id, void* data);

/**
 * @brief Deletes node with no or one child
 * @param root Pointer to node to delete
 * @return TreeNode* Pointer to child node
 */
TreeNode* deleteWithOneOrNoChild(TreeNode* root);

/**
 * @brief Deletes node with two children
 * @param root Pointer to node to delete
 * @return TreeNode* Pointer to root node after deletion
 */
TreeNode* deleteWithTwoChildren(TreeNode* root);

/**
 * @brief Deletes node with given id from the binary search tree
 * @param root Pointer to root node of the tree
 * @param id Integer value to delete
 * @return TreeNode* Pointer to root node after deletion
 */
TreeNode* deleteNode(TreeNode* root, int id);

/**
 * @brief Searches for a node with given id in the binary search tree
 * @param root Pointer to root node of the tree
 * @param id Integer value to search for
 * @return TreeNode* Pointer to found node, NULL if not found
 */
TreeNode* searchNode(TreeNode* root, int id);

/* ================= Utility Functions ================= */

/**
 * @brief Finds the node with minimum value in the tree/subtree
 * @param root Pointer to root node of the tree/subtree
 * @return TreeNode* Pointer to node with minimum value
 */
TreeNode* findMin(TreeNode* root);

/**
 * @brief Finds the node with maximum value in the tree/subtree
 * @param root Pointer to root node of the tree/subtree
 * @return TreeNode* Pointer to node with maximum value
 */
TreeNode* findMax(TreeNode* root);

/**
 * @brief Returns the number of nodes in the tree
 * @param root Pointer to root node of the tree
 * @return int Number of nodes in the tree
 */
int getSize(TreeNode* root);

/* ================= Memory Management ================= */

/**
 * @brief Prints an error message and exits the program
 */
void handleAllocationError();

/**
 * @brief Recursively frees all nodes in the tree
 * @param root Pointer to root node of the tree
 */
void destroy(TreeNode* root);

/* ================= Traversal Functions ================= */

/**
 * @brief Performs in-order traversal of the tree, applying function to each node
 * @param root Pointer to root node of the tree
 * @param func Function pointer to apply to each node's id and data
 */
void traverseInOrder(TreeNode* root, TraversalCallback);

/**
 * @brief Performs pre-order traversal of the tree, applying function to each node
 * @param root Pointer to root node of the tree
 * @param func Function pointer to apply to each node's id and data
 */
void traversePreOrder(TreeNode* root, TraversalCallback);

/**
 * @brief Performs post-order traversal of the tree, applying function to each node
 * @param root Pointer to root node of the tree
 * @param func Function pointer to apply to each node's id and data
 */
void traversePostOrder(TreeNode* root, TraversalCallback);

#endif // BINARY_TREE_H
