#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>


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

int isBalance(char *exp)
{
    //stack of type array
   // struct Stack st;
    //st.size = strlen(exp); //max size of string is size of stack
   // st.s = new char[st.size];

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
            {
                push(exp[i]);
            }
        else if(exp[i]==')')
            {
                if(top==NULL)
                    return false;
                pop();
            }
    }
    //once came outside for loop
    return (top==NULL)?true:false;
}

int pre(char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='/'||x=='*')
        return 2;
    return 0;
    
}

int isOperand(char x){
    if(x=='+'||x=='-'||x=='/'||x=='*') 
        return 0;
    else 
        return 1;
}

char* InToPost(char *infix)
{
    int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=new char[len+2]; //so can return to main fx

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++]=infix[i++];
        else{
            if(pre(infix[i])>pre(top->data))
                push(infix[i++]);
            else{
                postfix[j++]=pop();

            }
        }
    }
    while(top!=NULL)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int Eval(char *postfix)
{
    int i =0;
    int x1,x2,r;

    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2=pop(), x1=pop();
            switch(postfix[i])
            {
                case '+':
                    r=x1+x2;
                    break;
                case '-':
                    r=x1-x2;
                    break;
                case '/':
                    r=x1/x2;
                    break;
                case '*':
                    r=x1*x2;
                    break;
            }
            push(r);
        }
    }
    return top->data;
}


int main(){
    char *exp = "((a+b)*(c-d)))";

    printf("%d", isBalance(exp));

    push('#'); //prevent error due to empty stack
    char *infix ="a+b*c";

    char *postfix = InToPost(infix);
    printf("\n%s ", postfix);

    char *postfix2 = "234*+82/-";
    printf("\nResult is %d\n", Eval(postfix2));

    return 0;


}