#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h> //searches only in default directories
#include "Queue.h" //searches everything, but mostly user defined


using namespace std;

struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter root value");
    scanf("%d", &x);
    root = new Node;
    root->data=x;
    root->lchild=root->rchild=0;
    enqueue(&q, root);
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("\nEnter left child of %d ", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=0; //create t
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("\nEnter Right child of %d", p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=0; //create t
            p->rchild=t;
            enqueue(&q,t); //insert t inside queue q
        }

    }
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}



void Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int count(Node *p)
{
    int x,y;
    while(p!=NULL)
    {
        x = count(p->lchild);
        y = count(p->rchild);

        return x + y + 1; 
        //return x+y+p->data (sum of all nodes)
        
        /*
        if(p->lchild &&p->rchild)
            return x+y+1
        else 
            return x + y; (counts the nodes with degree 2 only)
        */
    }
    return 0;
}

//count with only degree 1
int countdeg1(Node *p)
{
    int x,y;
    while(p!=NULL)
    {
        x = count(p->lchild);
        y = count(p->rchild);


    
        if(p->lchild!=NULL^p->rchild!=NULL)
            return x+y+1;
        else 
            return x + y;
    }
    return 0;
}

int height(Node *p)
{
    int x,y;
    while(p!=NULL)
    {
        x = height(p->lchild);
        y = height(p->rchild);

        if(x>y)
            return x+1;
        else 
            return y+1;
    }
    return 0;
}

void Levelorder(struct Node *p)
{
    struct Queue q;
    create(&q,100);

    printf("%d ", root->data);
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        root=dequeue(&q);
        if(root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }

    }
}


int main(){
    Treecreate();

    printf("\nPre Order\n ");
    Preorder(root);
    printf("\n In Order\n ");
    Inorder(root);
    printf("\nPost Order\n ");
    Postorder(root);
    printf("\nLevel Order: \n ");
    Levelorder(root);

    return 0;


}