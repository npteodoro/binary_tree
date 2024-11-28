#include "binary_tree.h"

void handleAllocationError() {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
}

TreeNode* createNode(int id, void* data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    TreeNode* result;

    if (!newNode)
        handleAllocationError();

    newNode->id = id;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    result = newNode;

    return result;
}

TreeNode* insertNode(TreeNode* root, int id, void* data) {
    TreeNode* result = root;

    if (root == NULL)
        result = createNode(id, data);
    else if (id < root->id)
        root->left = insertNode(root->left, id, data);
    else if (id > root->id)
        root->right = insertNode(root->right, id, data);

    return result;
}


TreeNode* findMin(TreeNode* root) {
    TreeNode* result = root;

    if (root != NULL) {
        while (result->left != NULL)
            result = result->left;
    }

    return result;
}

TreeNode* findMax(TreeNode* root) {
    TreeNode* result = root;

    if (root != NULL) {
        while (result->right != NULL)
            result = result->right;
    }

    return result;
}


TreeNode* deleteWithOneOrNoChild(TreeNode* root) {
    TreeNode* child = (root->left != NULL) ? root->left : root->right;

    if (root->data != NULL)
        free(root->data);
    free(root);

    return child;
}



TreeNode* deleteWithTwoChildren(TreeNode* root) {
    TreeNode* minNode = findMin(root->right);

    root->id = minNode->id;

    if (root->data != NULL)
        free(root->data);

    root->data = strdup((char*)minNode->data);

    root->right = deleteNode(root->right, minNode->id);

    return root;
}


TreeNode* deleteNode(TreeNode* root, int id) {
    TreeNode* result = root;

    if (root != NULL) {
        if (id < root->id)
            root->left = deleteNode(root->left, id);
        else if (id > root->id)
            root->right = deleteNode(root->right, id);
        else
            result = (root->left == NULL || root->right == NULL) 
                     ? deleteWithOneOrNoChild(root) 
                     : deleteWithTwoChildren(root);
    }

    return result;
}


TreeNode* searchNode(TreeNode* root, int id) {
    TreeNode* result = root;

    while (result != NULL && result->id != id)
        result = (id < result->id) ? result->left : result->right;

    return result;
}

int getSize(TreeNode* root) {
    return (root == NULL) ? 0 : 1 + getSize(root->left) + getSize(root->right);
}

void traverseInOrder(TreeNode* root, TraversalCallback callback) {
    if (root != NULL) {
        traverseInOrder(root->left, callback);
        callback(root->id, root->data);
        traverseInOrder(root->right, callback);
    }
}

void traversePreOrder(TreeNode* root, TraversalCallback callback) {
    if (root != NULL) {
        callback(root->id, root->data);
        traversePreOrder(root->left, callback);
        traversePreOrder(root->right, callback);
    }
}

void traversePostOrder(TreeNode* root, TraversalCallback callback) {
    if (root != NULL) {
        traversePostOrder(root->left, callback);
        traversePostOrder(root->right, callback);
        callback(root->id, root->data);
    }
}


void destroy(TreeNode* root) {
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        if (root->data != NULL)
            free(root->data);
        free(root);
    }
}


