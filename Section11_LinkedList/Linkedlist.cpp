#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first;



//Concatenating 2 linked lists
//Merging linked lists

void create(int A[], int n)
{   
    struct Node *t,*last; //temp node and last node
    first = new Node; //create the first node in heap
    
    first->data=A[0]; //insert first data
    first->next=NULL; //make the pointer null as there is only 1
    last=first;
    for (int i =1; i<n;i++){
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

void Insert(int pos, int x){
    Node *t, *p;
    if(pos==0)
    {
        t= new Node;
        t->data=x;
        t->next=first;
        first=t;
    }
    else if(pos>0){
        p = first;
        for (int i=0;i<pos-1 &&p;i++){
            p=p->next;
        }
        if(p) //check not null
        {
            t = new Node;
            t->data=x;
            t->next=p->next;
            p->next=t;

        }
    }
}

/*
void InsertLast(int x){
    Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if(first == NULL){
        first = last = t;
    }
    else{
        last->next = t;
        last = t;
    }
}*/


void Display(struct Node *p)
{
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void rDisplay(struct Node *p)
{
    if(p!=NULL){
        printf("%d ", p->data);
        rDisplay(p->next);
    }
}

int count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}

int rsum(struct Node *p)
{
    if(p==NULL)
        return 0;
    else
        return rsum(p->next) + p->data;

}

int max(Node *p){
    int m=-32768;
    while(p){
        if(p->data>m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int rmax(Node *p){
    int x = 0;
    if(p==0)
        return -32768;
    x = rmax(p->next);
    return x>p->data ?x:p->data;
}

Node* linearsearch(Node *p, int key) //return type is node pointer
{
    Node *q = NULL; //for move to head
    while(p!=NULL){
        if (key==p->data){
            q->next=p->next;
            p->next = first; 
            first = p;
             return (p);
        }
        else
            q = p;
            p=p->next;
    }
    return NULL;
    /*
    if p == NUll
        return NULL
    if key == p-> data
        return p
    else
        return Search(p->next,key)
    
    */
}

void SortedInsert(struct Node *p, int x){
    struct Node *t, *q=NULL;
    t = new Node;
    t->data=x;
    t->next=NULL;

    if(first==NULL){
        first = t;
    }
    else 
    {
        while(p &&p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t; 
        }
    }

}

void lldelete(int pos){
    Node *p,*q;
    int x=-1,i;
    if(pos==1)
    {
        x=first->data;
        p=first;
        first=first->next;
        delete p;
    }
    else
    {
        p=first;
        q=NULL;
        for(i=0;i<pos-1&&p;i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            q->next=p->next;
            x=p->data;
            delete p;
        }
    }

}

int issorted(Node *p){
    int x = -32768;
    //Node *p=first;
    while(p!=NULL)
    {
        if(p->data<x)
            return false;
        else{
            x=p->data;
            p=p->next;

        }
    }
    return true;
}

void removeduplicates(Node *a){
    Node *p = first;
    Node *q = first->next;
    while(q!=NULL){
        if (p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q= p->next;
        }

    }

}

void reverselist(struct Node *p){
    
    struct Node *q=NULL;
    struct Node *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

int isLoop(Node*f)
{
    Node *p,*q;
    p=q=f;
    do 
    {
        p=p->next;
        q=q->next;
        q=q!=NULL ?q->next:NULL;
    }
    while(p&&q);
    if (p==q)
        return true;
    else 
        return false;


}

int main(){
    int A[]={3,5,7,7,15,25, 33};
    create(A,7);
    printf("Length is %d \n",count(first));
    rDisplay(first);
    removeduplicates(first);
    printf("\n Sorted?: %d \n",issorted(first)); //write if statements for better printing


    printf("Sum is %d \n",rsum(first));
    printf("Max no is %d \n",rmax(first));
    printf("Searched Key %d \n", linearsearch(first,25)->data);
    Insert(6, 99);  //can also used to create linked list
    //InsertLast(87);
    //SortedInsert(first,35); //only for sorted list
    lldelete(2);
    rDisplay(first);
    cout<<endl;
    reverselist(first);
   
    if(!isLoop(first))
        printf("\nNot a loop\n");
    
    rDisplay(first);
    
    
    
    return 0;
}