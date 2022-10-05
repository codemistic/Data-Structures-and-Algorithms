#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node* left;
	struct Node* right;
	char data;
}Node;
typedef Node* EXT;

char* convertToPostFix(char* inputString, int size);
void initTree(EXT *tree, char *inputString, int size);
void traverse(EXT tree);
int compute(EXT tree);

