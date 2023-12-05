#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10
// Stack
typedef struct NodeStack{
    char Letter;
    struct NodeStack* next;
}NodeStack;

typedef struct Stack{
    struct NodeStack * top;
    int capacity;
    int elements;
}Stack;

// Queue
typedef struct NodeQueue{
    char Letters;
    struct NodeQueue* next;
}NodeQueue;

typedef struct Queue{
    struct NodeQueue* top;
    struct NodeQueue* end;
}Queue;

//Circular ARRAY
typedef struct NodeCircularArray{
    struct NodeCircularArray* front;
    struct NodeCircularArray* rear;
}NodeCircularArray;

typedef struct CircularArray{
    int count;
    int capacity;
}CircularArray;


// Functions

Stack* NewStack(int capacity){

    Stack* stack = malloc(sizeof (Stack));
    stack->top = NULL;
    stack->capacity = capacity;
    stack->elements = -1;
    return stack;
}
int EmptyStack(Stack* stack){
    return stack->top == NULL;
}

int FullStack(Stack* stack){
    return stack->capacity == stack->elements;
}

Stack* pushStack(Stack* stack, char letter){
    if (EmptyStack(stack)){
        NodeStack* newNode = malloc(sizeof(NodeStack));
        newNode->next = NULL;
        newNode->Letter = letter;
        stack->top = newNode;
        stack->elements = 1;
        return stack;
    }
    if (FullStack(stack)){
        printf("La pila esta llena");
        return stack;
    }

    NodeStack* newNode = malloc(sizeof(NodeStack));
    newNode->next = stack->top;
    newNode->Letter = letter;
    stack->top = newNode;
    stack->elements += 1;
    return stack;
}

char PopStack(Stack* stack){
    if(EmptyStack(stack)){
        return '\0';
    }
    NodeStack* temp = stack->top;
    char letra = temp->Letter;
    stack->top = stack->top->next;
    stack->elements -= 1;
    return letra;

}

Queue* CreateQueue(){
    Queue* NewQueue = malloc(sizeof(Queue));
    NewQueue->top = NULL;
    NewQueue->end = NULL;
    return NewQueue;

}

int EmptyQueue(Queue* queue){
    return queue->top == NULL;
}

Queue* PushQueue(Queue* queue, char Letra){
    NodeQueue* newNode = malloc(sizeof(NodeQueue));
    newNode->Letters = Letra;
    newNode->next = NULL;

    if (EmptyQueue(queue)){
        queue->top = queue->end = newNode;
        return queue;
    }
    queue->end->next = newNode;
    queue->end = newNode;
    return queue;
}

char PopQueue(Queue* queue){
    if(EmptyQueue(queue)){
        printf("The queue is empty!!");
        return '\0';
    }
    NodeQueue* Aux = queue->top;
    char Letra = Aux->Letters;
    queue->top = queue->top->next;
    if (queue->top == NULL){
        queue->end = NULL;
    }
    free(Aux);
    return Letra;
}

Queue* PushBetween(Stack* FirstStack, Stack* SecondStack) {
    Queue *NewQueue = CreateQueue();
    while((!EmptyStack(FirstStack)) && (!EmptyStack(SecondStack))){

        PushQueue(NewQueue, PopStack(FirstStack));
        PushQueue(NewQueue, PopStack(SecondStack));

    }
    while(!EmptyStack(FirstStack)){
        PushQueue(NewQueue, PopStack(FirstStack));
    }
    while(!EmptyStack(SecondStack)){
        PushQueue(NewQueue, PopStack(SecondStack));
    }
    return NewQueue;
}
void PrintQueue(Queue* queue){
    Queue* NewQueue = malloc(sizeof(Queue));
    *NewQueue = *queue;
    for (; NewQueue->top != NULL; NewQueue->top = NewQueue->top->next)
        printf("%c", NewQueue->top->Letters);
}
void PrintStack(Stack* stack){
    Stack* newStack = malloc(sizeof(Stack));
    *newStack = *stack;
    for (; newStack->top != NULL; newStack->top = newStack->top->next) {
        printf("%c", newStack->top->Letter);

    }
}

Queue* InvertPushQueue(Queue* queue, char Letra){
    NodeQueue* newNode = malloc(sizeof(NodeQueue));
    newNode->Letters = Letra;
    newNode->next = NULL;

    if (EmptyQueue(queue)){
        queue->top = queue->end = newNode;
        return queue;
    }
    newNode->next = queue->top;
    queue->top = newNode;

    return queue;}

Stack* InvertirPila(Stack* stack){

    Queue* Newqueue = CreateQueue();
    while (stack->top != NULL){
        InvertPushQueue(Newqueue, PopStack(stack));
    }
    Stack* newStack = NewStack(10);
    while (Newqueue->top != NULL){
        pushStack(newStack, PopQueue(Newqueue));
    }
    return newStack;
}

CircularArray* CrearBicola(){
    CircularArray* NewArray = malloc(sizeof(CircularArray));
    NewArray->capacity = MAX_SIZE;
    NewArray->count = 0;
}

int BicolaVacia(CircularArray* Array){
    return Array->count == 0;
}

int BicolaLlena(CircularArray* Array){
    return Array->count == MAX_SIZE;
}

int main() {
    Stack* FirstStack = NewStack(10);
    pushStack(FirstStack, 'O');
    pushStack(FirstStack, 'U');
    pushStack(FirstStack, 'A');

    Stack* SecondStack = NewStack(10);
    pushStack(SecondStack, 'T');
    pushStack(SecondStack, 'R');
    pushStack(SecondStack, 'I');
    pushStack(SecondStack, 'Q');

    Stack* stack = InvertirPila(SecondStack);
    PrintStack(stack);








    return 0;

}
