#include<stdio.h>
#include<stdlib.h>

#define MAX 112345
#define ERROR 0
#define SUCCESS 1
#define IMPOSSIBLE 0xffffffff

typedef int item_type;

typedef struct node{
    item_type info;
    struct node *next;
}node;

void init(node *top){
    top->next = NULL;
}

int emptyStack(node *top){
    return top == NULL;
}

int push(node *top, item_type value){
    node *new_node = (node*)malloc(sizeof(node));
    if(!new_node){
        return ERROR;
    }else{
        new_node->next= top;
        new_node->info = value;
        top = new_node;

        return SUCCESS;
    }
}

int pop(node *top){

    if(emptyStack(top)){
        return IMPOSSIBLE;
    }

    node* popped_node = top;
    top = top->next;
    free(popped_node);

    return SUCCESS;
}

item_type top(node *top){
    
    item_type i;
    if(emptyStack(top)){
        i = ERROR;
        return i;
    }

    return top->info;
}

int main(void){
    return 0;
}
