#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

class Node 
{
    public:
        int data;
        Node *next;
};

class LinkedList
{
private:
     Node *first;
public:

    LinkedList()
    {
        first = NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList();

    void rDisplay();
    void Insert(int index, int x);
    int Delete(int index);

};

LinkedList::LinkedList(int A[],int n){
    struct Node *t,*last; //temp node and last node
    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for (int i =1; i<n;i++){
        t = new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

void LinkedList::rDisplay()
{
    Node *p=first;
    
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
    cout<<endl;
}

int main(){
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);

    l.rDisplay();

    return 0;



}