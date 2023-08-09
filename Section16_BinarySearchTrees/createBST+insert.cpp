#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

struct Node 
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
    
}*root = NULL; //globally accessable

void Insert(int key)
{
    struct Node *t=root;
    struct Node *r,*p;

    if(root==NULL)
    {
        p= new Node;
        p->data=key;
        p->lchild=NULL;
        p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t; //tail pointer to help insert
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else 
            return;
    }
    p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;

    if(key<r->data) r->lchild=p;
    else r->rchild=p;
}

int Height(Node *p)
{
    int x,y;
    while(p!=NULL)
    {
        x = Height(p->lchild);
        y = Height(p->rchild);

        if(x>y)
            return x+1;
        else 
            return y+1;
    }
    return 0;
}

struct Node *InPre(Node *p)
{
    while(p && p->rchild!=NULL)
        p=p->rchild;
    
    return p;
}

struct Node *InSucc(Node *p)
{
    while(p && p->lchild!=NULL)
        p=p->lchild;
    
    return p;
}

struct Node *Delete(struct Node *p, int key)
{   
    struct Node *q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL) //leaf node
        {
            if(p==root)
                root=NULL;
            delete p;
            return NULL;
        }
    if(key<p->data)
        p->lchild=Delete(p->lchild, key);
    else if(key>p->data)
        p->rchild=Delete(p->rchild, key);
    else { //means a key is found
        //Decide predecessor or successor
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild); //inorder predeseccors (rightmost pointer of left subtree)
            p->data=q->data;
            p->lchild=Delete(p->lchild, q->data);
        }
        else{
            q=InSucc(p->lchild); //inorder predeseccors (rightmost pointer of left subtree)
            p->data=q->data;
            p->rchild=Delete(p->rchild, q->data);
        }
    }
    return p;
}


struct Node* Search(int key)
{
    struct Node *t=root;

    while(t!=NULL)
    {
        if(key==t->data)
            return t;
        else if (key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL;

}

void Inorder(struct Node *p) //print in inorder
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);

    }
}

int main(){
    
    Insert(10);
    Insert(20);
    Insert(5);
    Insert(30);
    Insert(40);
    Insert(15);

    Inorder(root);

    struct Node *temp;
    temp = Search(20);
    if (temp!=NULL)
        printf("\nelement %d is found \n", temp->data);
    else
        printf("\nnot found");

    Delete(root, 10);
    temp = Search(10);
    if (temp!=NULL)
        printf("\nelement %d is found \n", temp->data);
    else
        printf("\nnot found");
    Inorder(root);



    return 0;

}