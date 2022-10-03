#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"BST.h"
#include"Stack.h"

Node* createEXTNode(char data, Node *left, Node *right) {
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = left;
	newNode->right = right;
	return newNode;
}

int is_operator(char data) {
	switch(data) {
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 1;
		case '/':
			return 1;
	}
	return 0;
}

int precedance(char ch) {
	if(ch == '+' || ch == '-') {
		return 1;
	} else if(ch == '*' || ch == '/') {
		return 2;
	} else if(ch == '^') {
		return 3;	
	} else {
		return 0;
	}	
}

int isAlNum(char ch) {
	//48-57 0-9
	//65-90 A-Z
	//97-122 a -z

	if(((int)ch) >= 48 && ((int)ch) <= 57) {
		return 1;
	}
	if(((int)ch) >= 65 && ((int)ch) <= 90) {
		return 1;
	}
	if(((int)ch) >= 97 && ((int)ch) <= 122) {
		return 1;
	}
	return 0;
}

char* convertToPostFix(char* inputString, int size) {
	int index = 0;
	CharStackList stack;
	initCharStack(&stack);

	char* postfix = malloc(sizeof(char) * size);
	char *temp = postfix;
	while(*inputString != '\0') {
		if(isAlNum(*inputString)) {
			*postfix = *inputString;
			postfix++;
		} else if(*inputString == '(') {
			pushChar(&stack, *inputString);
		} else if(*inputString == '^') {
			pushChar(&stack, *inputString);
		} else if(*inputString == ')') {
			while(peekChar(stack) != '(') {
				*postfix = peekChar(stack);
				postfix++;
				popChar(&stack);
			}
			popChar(&stack);
		}
		else {
			if(precedance(*inputString) > precedance(peekChar(stack))) {
				pushChar(&stack, *inputString);
			} else {
				while(precedance(*inputString) <= precedance(peekChar(stack))) {
					*postfix = peekChar(stack);
					postfix++;
					popChar(&stack);
				}
				pushChar(&stack, *inputString);
			}
		}
		
		inputString++;
	}
	
	while(peekChar(stack) != '\0') {
		*postfix = peekChar(stack);
		postfix++;
		popChar(&stack);
	}
	*postfix = '\0';
	postfix = temp;
	
	return postfix;
}

void disp(char* str) {
	while(*str != '\0') {
		printf("%c", *str);
		str++;
	}
}

void initTree(EXT *tree, char* inputString, int size) {
	inputString = convertToPostFix(inputString, size);

	int index = 0;
	StackList stack;
	initStack(&stack);
	while(inputString[index] != '\0') {
		if(!is_operator(inputString[index])) {
			push(&stack, (void *) createEXTNode(inputString[index], NULL, NULL));
		} else {
			Node* element2 = (Node *)peek(stack);
			pop(&stack);
			
			Node* element1 = (Node *)peek(stack);
			pop(&stack);
		
			push(&stack, (Node *)createEXTNode(inputString[index], element1, element2));
		}
		index++;
	}

	Node* finalTree = (Node *) peek(stack);
	pop(&stack);

	*tree = finalTree;

}

void traverse(EXT tree) {
	if(tree != NULL) {
		traverse(tree->left);
		printf("%c \n", tree->data);
		traverse(tree->right);
	}
}

int compute(EXT tree) {
	if(tree == NULL) 
		return 0;
	
	if(tree->left == NULL && tree->right == NULL) 
		return ((int)tree->data) - 48;

	int left = compute(tree->left);
	int right = compute(tree->right);
	
	if(tree->data == '+') 
		return left + right;
	if(tree->data == '-') 
		return left - right;
	if(tree->data == '*') 
		return left * right;
	if(tree->data == '/') 
		return left / right;

	return -1;
}


