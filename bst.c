#include "bst.h"

TreeNode *createNode(void *id, void* data) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));

    newNode->id = id;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

TreeNode *insertNode(TreeNode *root, void *id, void *data, CompareFunction compare) {
    TreeNode *result = root;

    if (root == NULL)
        result = createNode(id, data);
    else if (compare(id, root->id) < 0)
        root->left = insertNode(root->left, id, data, compare);
    else if (compare(id, root->id) > 0)
        root->right = insertNode(root->right, id, data, compare);

    return result;
}


TreeNode *findMin(TreeNode *root) {
    TreeNode *result = root;

    if (root != NULL) {
        while (result->left != NULL)
            result = result->left;
    }

    return result;
}

TreeNode *findMax(TreeNode *root) {
    TreeNode *result = root;

    if (root != NULL) {
        while (result->right != NULL)
            result = result->right;
    }

    return result;
}


TreeNode *deleteWithOneOrNoChild(TreeNode *root) {
    TreeNode *child = (root->left != NULL) ? root->left : root->right;

    if (root->id != NULL)
        free(root->id);
    if (root->data != NULL)
        free(root->data);
    free(root);

    return child;
}



TreeNode *deleteWithTwoChildren(TreeNode *root, CompareFunction compare) {
    TreeNode *minNode = findMin(root->right);

    if (root->id != NULL)
        free(root->id);
    if (root->data != NULL)
        free(root->data);

    root->id = minNode->id;
    root->data = minNode->data;

    root->right = deleteNode(root->right, minNode->id, compare);

    return root;
}


TreeNode *deleteNode(TreeNode *root, void *id, CompareFunction compare) {
    TreeNode *result = root;

    if (root != NULL) {
        if (compare(id, root->id) < 0)
            root->left = deleteNode(root->left, id, compare);
        else if (compare(id, root->id) > 0)
            root->right = deleteNode(root->right, id, compare);
        else
            result = (root->left == NULL || root->right == NULL)
                     ? deleteWithOneOrNoChild(root)
                     : deleteWithTwoChildren(root, compare);
    }

    return result;
}


TreeNode *searchNode(TreeNode *root, void *id, CompareFunction compare) {
    TreeNode *result = root;

    while (result != NULL && compare(id, result->id) != 0)
        result = compare(id, result->id) < 0 ? result->left : result->right;

    return result;
}

int getSize(TreeNode *root) {
    return (root == NULL) ? 0 : 1 + getSize(root->left) + getSize(root->right);
}

void traverseInOrder(TreeNode *root, TraversalCallback callback) {
    if (root != NULL) {
        traverseInOrder(root->left, callback);
        callback(root->id, root->data);
        traverseInOrder(root->right, callback);
    }
}

void traversePreOrder(TreeNode *root, TraversalCallback callback) {
    if (root != NULL) {
        callback(root->id, root->data);
        traversePreOrder(root->left, callback);
        traversePreOrder(root->right, callback);
    }
}

void traversePostOrder(TreeNode *root, TraversalCallback callback) {
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
        if (root->id != NULL)
            free(root->id);
        if (root->data != NULL)
            free(root->data);
        free(root);
    }
}


