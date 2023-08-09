#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;


struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{   
    struct Node *t,*last; //temp node and last node
    first = new Node;
    first->data=A[0];
    first->next=first->prev=NULL;
    last=first;
    for (int i =1; i<n;i++){
        t = new Node;
        t->data=A[i];
        t->next=last->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;

    }
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index==0)
    {
        t = new Node;
        t->data=x;
        t->prev=NULL;
        first->prev=t;
        t->next=first;
        first =t;
    }
    else{
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t=new Node;
        t->data=x;
        t->next=p->next;
        t->prev=p;
        if(p->next)
            p->next->prev=t;
            p->next=t;
    }
}

void Delete(int pos)
{
    //assuming pos>1 and less than length
    struct Node *p;
    int i;

    p=first;
    for(i=0;i<pos-1;i++){
        p=p->next;
    }
    p->prev->next=p->next;
    if(p->next)
        p->next->prev=p->prev;
    delete p;

}

void Display(struct Node *p)
{
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
} 

void Reverse(struct Node *p)
{
    struct Node *temp;
    while(p!=NULL){
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;
    p=p->prev;
    if(p->next==NULL)
        first=p;
    
    }
}

//student challenge 1
int middle()
{
    struct Node *p,*q;
    q=p=first;
    while(p)
    {
        p=p->next;
        if(p)
        {
            p=p->next;
            q=q->next;
        }

    }
    return q->data;
}


int main(){
    int A[] = {3, 5, 7, 7, 15, 25, 33};
    create(A, 7);
    Display(first);
    cout<<endl;
    Delete(2);
    Display(first);
    cout<<endl<<"middle of node:" <<middle();


}