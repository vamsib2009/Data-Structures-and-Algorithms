#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

struct Queue
{
    int size;
    int front;
    int Rear;
    int *Q;
};

void enqueue(Queue *q, int x){
    if((q->Rear+1)%q->size==q->front)
        printf("full queue");
    else
    {
        q->Rear=(q->Rear+1)%q->size;  //edited to make circular
        q->Q[q->Rear]=x;
    }
}

int dequeue(Queue *q)
{
    int x=-1;
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



int main(){
    struct Queue st;
    st.size = 7;
    st.front=0;
    st.Rear=0;
    st.Q = new int[st.size];

    enqueue(&st,10);
    enqueue(&st,15);
    enqueue(&st,19);
    enqueue(&st,26);
    enqueue(&st,287);

    Display(st);

    dequeue(&st);
    Display(st);

}