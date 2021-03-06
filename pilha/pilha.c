#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    struct Node* next;
    int value;
    char cvalue;
}Node;

typedef struct _stack{
    Node* top;
    int size;
}Stack;

Node* newNode(int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    node->cvalue = NULL;
    return node;
}

Node* newNodeC(char cvalue){
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = NULL;
    node->value = NULL;
    node->cvalue = cvalue;
    return node;
}

Stack* newStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int isEmpty(Stack* stack){
    if(stack == NULL)return 1;
    return stack->size == 0;
}

int getTop(Stack* stack){
    return stack->top->value;
}

char getTopC(Stack* stack) {
    return stack->top->cvalue;
}

void push(Stack* stack, int value){
    if(stack == NULL)return;
    Node* node = newNode(value);
    stack->size++;
    if(stack->top == NULL){
        stack->top = node;
    }else {
        node->next = stack->top;
        stack->top = node;
    }
}

void pushC(Stack* stack, char value){
    if(stack == NULL)return;
    Node* node = newNodeC(value);
    stack->size++;
    if(stack->top == NULL){
        stack->top = node;
    }else {
        node->next = stack->top;
        stack->top = node;
    }
}

void pop(Stack* stack) {
    if(stack == NULL || stack->size == 0)return;
    stack->size--;
    Node* node = stack->top;
    if(node->next != NULL){
        stack->top = node->next;
    } else {
        stack->top = NULL;
    }
    free(node);
}

int main()
{

    Stack* _stack = newStack();
    push(_stack,23);
    push(_stack,24);
    
    pop(_stack);

    printf ("%c",peek(_stack));
    return 0;
}