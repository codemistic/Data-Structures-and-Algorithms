#include<stdio.h>
#include <string.h>
#include"BST.h"

int main() {
	EXT tree;
	char data[100];

	printf("\n Enter the input Expression : ");
	scanf("%s", data);

	initTree(&tree, data, strlen(data));

	printf("\n Expression Tree Traversal is : ");
	traverse(tree);

	printf("\n Computed Result is : %d", compute(tree));
		
	return 0;
}

