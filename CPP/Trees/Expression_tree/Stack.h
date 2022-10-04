#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode {
	struct StackNode* next;
	void* data;
}StackNode;
typedef StackNode* StackList;

void initStack(StackList *list);

// To work as a stack
void push(StackList *list, void *data);
int pop(StackList *list);

void* peek(StackList list);


typedef struct CharStackNode {
	struct CharStackNode* next;
	char data;
}CharStackNode;
typedef CharStackNode* CharStackList;

void initCharStack(CharStackList *list);

// To work as a stack
void pushChar(CharStackList *list, char data);
int popChar(CharStackList *list);

char peekChar(CharStackList list);

