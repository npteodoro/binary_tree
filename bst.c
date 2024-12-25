#include "bst.h"
#include <stdlib.h>
#include <string.h>

void *deepCopyData(const void *source, size_t size) {
    void *result = NULL;
    if (source != NULL && size > 0) {
        result = malloc(size);
        if (result != NULL)
            memcpy(result, source, size);
    }
    return result;
}

void freeNodeData(TreeNode *node) {
    if (node != NULL) {
        free(node->id);
        free(node->data);
    }
}

TreeNode *createNode(const void *id, const void *data) {
    TreeNode *result = NULL;
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        newNode->id = deepCopyData(id, sizeof(void *));
        newNode->data = deepCopyData(data, sizeof(void *));
        if (newNode->id != NULL && newNode->data != NULL) {
            newNode->left = NULL;
            newNode->right = NULL;
            result = newNode;
        }
        else {
            freeNodeData(newNode);
            free(newNode);
        }
    }
    return result;
}

TreeNode *insertNode(TreeNode *root, const void *id, const void *data, CompareFunction compare) {
    TreeNode *result = root;
    if (root == NULL)
        result = createNode(id, data);
    else {
        int cmp = compare(id, root->id);
        if (cmp < 0)
            root->left = insertNode(root->left, id, data, compare);
        else if (cmp > 0)
            root->right = insertNode(root->right, id, data, compare);
    }
    return result;
}

TreeNode *findMin(const TreeNode *root) {
    TreeNode *result = (TreeNode *)root;
    while (result != NULL && result->left != NULL)
        result = result->left;
    return result;
}

TreeNode *findMax(const TreeNode *root) {
    TreeNode *result = (TreeNode *)root;
    while (result != NULL && result->right != NULL)
        result = result->right;
    return result;
}

static TreeNode *deleteWithOneOrNoChild(TreeNode *root) {
    TreeNode *result = root->left != NULL ? root->left : root->right;
    freeNode(root);
    return result;
}

static TreeNode *deleteWithTwoChildren(TreeNode *root, CompareFunction compare) {
    TreeNode *result = root;
    TreeNode *minNode = findMin(root->right);
    void *newId = deepCopyData(minNode->id, sizeof(void *));
    void *newData = deepCopyData(minNode->data, sizeof(void *));
    if (newId != NULL && newData != NULL) {
        freeNodeData(root);
        root->id = newId;
        root->data = newData;
        root->right = deleteNode(root->right, minNode->id, compare);
    }
    return result;
}

TreeNode *deleteNode(TreeNode *root, const void *id, CompareFunction compare) {
    TreeNode *result = root;
    if (root != NULL) {
        int cmp = compare(id, root->id);
        if (cmp < 0)
            root->left = deleteNode(root->left, id, compare);
        else if (cmp > 0)
            root->right = deleteNode(root->right, id, compare);
        else {
            if (root->left == NULL || root->right == NULL)
                result = deleteWithOneOrNoChild(root);
            else
                result = deleteWithTwoChildren(root, compare);
        }
    }
    return result;
}

TreeNode *searchNode(const TreeNode *root, const void *id, CompareFunction compare) {
    TreeNode *result = (TreeNode *)root;
    while (result != NULL) {
        int cmp = compare(id, result->id);
        if (cmp == 0)
            break;
        result = cmp < 0 ? result->left : result->right;
    }
    
    return result;
}

int getSize(const TreeNode *root) {
    int result = 0;
    
    if (root != NULL)
        result = 1 + getSize(root->left) + getSize(root->right);
    
    return result;
}

void traverseInOrder(const TreeNode *root, TraversalCallback callback) {
    if (root != NULL) {
        traverseInOrder(root->left, callback);
        callback(root->id, root->data);
        traverseInOrder(root->right, callback);
    }
}

void traversePreOrder(const TreeNode *root, TraversalCallback callback) {
    if (root != NULL) {
        callback(root->id, root->data);
        traversePreOrder(root->left, callback);
        traversePreOrder(root->right, callback);
    }
}

void traversePostOrder(const TreeNode *root, TraversalCallback callback) {
    if (root != NULL) {
        traversePostOrder(root->left, callback);
        traversePostOrder(root->right, callback);
        callback(root->id, root->data);
    }
}

void destroy(TreeNode *root) {
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        freeNode(root);
    }
}

void freeNode(TreeNode *node) {
    if (node != NULL) {
        freeNodeData(node);
        free(node);
    }
}

TreeNode *cloneTree(const TreeNode *root) {
    TreeNode *result = NULL;
    if (root != NULL) {
        void *idCopy = deepCopyData(root->id, sizeof(void *));
        void *dataCopy = deepCopyData(root->data, sizeof(void *));
        if (idCopy != NULL && dataCopy != NULL) {
            result = createNode(idCopy, dataCopy);
            if (result != NULL) {
                result->left = cloneTree(root->left);
                result->right = cloneTree(root->right);
            }
            free(idCopy);
            free(dataCopy);
        } 
        
        else {
            free(idCopy);
            free(dataCopy);
        }
    }
    return result;
}