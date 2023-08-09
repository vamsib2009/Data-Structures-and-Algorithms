#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Node{
    int data;
    struct Node *next;
}*front= NULL, *rear=NULL;

void enqueue(int x)
{
    struct Node *t;
    t = new Node;

    if(t==NULL)
        printf("queue is full");
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else{
            rear->next=t;
            rear = t;
            }
    }
}

int dequeue()
{
    int x=-1;
    struct Node* t;

    if(front==NULL)
        printf("Queue is Empty");
    else 
        {
            x=front->data;
            t=front;
            front=front->next;
            delete t;

        }
        return x;
}

void Display()
{
    struct Node *p;
    p=front;
    while(p){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
}


int main(){
    
    enqueue(10);
    enqueue(90);
    enqueue(70);
    enqueue(50);
    enqueue(40);

    Display();

    dequeue();
    dequeue();

    Display();  //success





}