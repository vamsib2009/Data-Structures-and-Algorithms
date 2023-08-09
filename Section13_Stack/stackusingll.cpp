#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top=NULL; //top is global

void push(int x){
    struct Node *t;
    t= new Node;

    if(t==NULL)//heap is full
        cout<<"stack full";
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *t;
    int x = -1;
    if(top==NULL)
        cout<<"stack empty";
    else{
        t = top;
        top=top->next;
        x=t->data;
        delete t;
    }
    return x;
}

void Display(){
    
        struct Node *p;
        p=top;
        while(p!=NULL)
        {
            printf("%d ", p->data);
            p=p->next;
        }
        printf("\n");

}


int main(){
    struct Node *top2 = NULL;
    
    push(10);
    push(20);
    push(30);
    
    Display();
    
    printf("%d ",pop());
    
    return 0;


}