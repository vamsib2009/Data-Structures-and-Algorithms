#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void create()
{
    struct Node *t, *last;
    int num;

    printf("Enter number of terms");
    cin >> num;
    printf("Enter each term with coeff and exp");

    for (int i = 0; i < num; i++)
    {
        t = new Node;
        cin >> t->coeff >> t->exp;
        t->next = NULL;
        if (poly == NULL)
        {
            poly = last = t; // first node
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%dx%d +", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

long Eval(struct Node *p, int x)
{
 long val=0;
 
 while(p)
 {
 val+=p->coeff*pow(x,p->exp);
 p=p->next;
 }
 return val;
}

int main()
{
    create();
 Display(poly);
 printf("%ld\n",Eval(poly,30));
 return 0;
}