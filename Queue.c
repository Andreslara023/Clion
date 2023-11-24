#define MAX_COLA 10
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int x;
    struct Node* next;
}Node;

typedef struct Queue{
    struct Queue* first;
    struct Queue* end;
}Queue;

struct Queue* CreateQueue(){
    Queue * queue = malloc(sizeof(Queue));
    queue->first = NULL;
    queue->end = NULL;
}

int Front(Queue* queue, int* value){
    if(queue && queue->first){
        *value = queue->first->x;
        return 1;
    }
    return 0;
}







int main(){

    return 0;
}