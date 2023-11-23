#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int x;
    struct Node* next;
}Node;

typedef struct Stack{

    int top;
    struct Node* first;
    unsigned capacity;

}Stack;

Stack* createStack(unsigned capacity){

    Stack* stack = malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    return stack;

}

int isFull(Stack* stack){

    return stack->top == stack-> capacity - 1;
}

int isEmpty(Stack* stack){

    return stack->top == -1;
}

int Count(Stack* stack){

    return stack->top + 1;
}

Stack* push(Stack* stack, int x){


    if (isFull(stack)){
        printf("No se pueden agregar mas elementos al stack ya que esta full!\n");
        return stack;
    }

    if(isEmpty(stack)){

        Node* newNode = malloc(sizeof (Node));
        newNode->x = x;
        newNode->next = NULL;
        stack->first= newNode;
        stack->top += 1;

    }
    else{
        Node* newNode = malloc(sizeof(Node));
        newNode->x = x;
        newNode->next = stack->first;
        stack->top += 1;
        stack->first = newNode;

    }

    return stack;

}

Stack* pop(Stack* stack){

    if(isEmpty(stack)){
        return stack;
    }
    stack->first = stack->first->next;
    stack->top -= 1;
    return stack;
}

void printStack(Stack* stack){

    Stack* new = malloc(sizeof(Stack*));
    *new = *stack;

    while (new->first->next != NULL){
        printf("%d\n", new->first->x);
        new->first = new->first->next;
    }
    printf("%d\n", new->first->x);
}




int main(){

    Stack* stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    printf("%d\n", Count(stack));

    printf("----------------\n");
    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    printf("%d", Count(stack));






    return 0;
}