#include<stdio.h>
#include<string.h>
#define MAX 1000000
#define SUCCESS 1
#define ERROR -1
#define IMPOSSIBLE 0xFFFFFFFF

//change type here, if needed
typedef int item_type;

typedef struct stack{
	item_type body[MAX];
	int end;
}stack;


void init(stack* s){
	memset(s->body,(item_type)0, MAX);
	s->end = -1;
}

int put(stack* s, item_type item){
	if(s->end == MAX)
		return ERROR;

	s->end += 1;
	s->body[s->end] = item;
	return SUCCESS;
}

item_type top(stack* s){
	return s->body[s->end];
}

int emptyStack(stack *s){
	return s->end == -1;
}

//Ideal scenario would be passing top as a reference
//and returning the successfulness of the pop() operation
//Or top() and then pop()
//but that's not convenient sometimes

int pop(stack* s){
	if(emptyStack(s)){
		//printf("Empty Stack\n");
		return IMPOSSIBLE;
	}
	s->end--;
	return SUCCESS;
}

int pop(stack* s, item_type* reference){
	if(emptyStack(s)){
		//printf("Empty Stack\n");
		return IMPOSSIBLE;
	}
	*reference = s->body[s->end];
	s->end--;
	return SUCCESS;
}

//if user instantiate a non int stack, return types will be different
/*
item_type pop(stack* s){
	if(emptyStack(s)){
		//printf("Empty Stack\n");
		return IMPOSSIBLE;
	}
	s->end--;
	return s->body[s->end + 1];
}
*/

void clearStack(stack* s){
	s->end = -1;
}

