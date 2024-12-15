#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "binary_tree.h"

typedef struct Words {
    char *pt, *us;
} Words;

void buildTrees(TreeNode **ptree, TreeNode **ustree, const char *filename);
char *getWord();
char *translateWord(TreeNode *ptree, TreeNode *ustree, const char *word);
void dictionaryExe();



#endif // FUNCTIONS_H