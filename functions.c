#include "functions.h"

// Callback function to print nodes during traversal
void printTree(int id, void* data) {
    printf("Node ID: %d, Data: %s\n", id, (char*)data);
}