#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <iostream>
#include <stdio.h>

//circular Queue
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int Rear;
    Node **Q;  //second pointer for original array. First is pointer of type node
};

void create(struct Queue *q, int size)
{
    q->size=size;
    q->front=0;
    q->Rear=0;  
    q->Q = new Node*[q->size];
}

void enqueue(Queue *q, Node* x){
    if((q->Rear+1)%q->size==q->front)
        printf("full queue");
    else
    {
        q->Rear=(q->Rear+1)%q->size;  //edited to make circular
        q->Q[q->Rear]=x;
    }
}

Node* dequeue(Queue *q)
{
    Node* x=NULL;
    if(q->Rear==q->front)
    {
        printf("queue is empty");
    }
    else{
        q->front=(q->front+1)%q->size;
        x =  q->Q[q->front];
    }
    return x;

}

/*
void Display(struct Queue q)
{
    int i=0;
    for(i=q.front+1;i<=q.Rear;i++)
        printf("%d ",q.Q[i]);
    printf("\n");
}*/

void Display(struct Queue q)
{
    int i = q.front+1;

    do {
        printf("%d ",q.Q[i]);
        i=(i+1)%q.size;
    }while (i!=(q.Rear+1)%q.size);

    printf("\n");
    
}

int isEmpty(struct Queue q)
{
    return q.front==q.Rear;
}



#endif /* QUEUE_H */