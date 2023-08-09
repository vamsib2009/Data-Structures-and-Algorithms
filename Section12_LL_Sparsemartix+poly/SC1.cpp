#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

//Sparse matrix using LL
struct Node 
{
    int col;
    int val;
    struct Node *next;
}*head = NULL;

void Display(int m, int n, struct Node *A[]){
    for(int i=0;i<m;i++){
        Node *p;
        p=A[i];
        for(int j=0;j<n;j++)
        {
            if(p != NULL &&j==p->col)
            {
                printf("%d ", p->val);
                p=p->next;
            }
            else {
                printf("0 ");
            }
        }
        cout << endl;

    }
}


int main(){
    int m,n;
    cout<<"Please enter the rows";
    cin>>m;
    Node *A[m];
    cout<<"Please enter the columns";
    cin>>n;

        // Initializing all pointers with NULL
    for (int i = 0; i < m; i++)
    {
        A[i] = NULL;
    }

    int a,b;  //a col b = val
    cout<<"Please enter some sample data";

 int num;
    Node *temp;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the number of non zero elements in row " << i << "- ";
        cin >> num;
        if (num != 0)
        {
            cout << "Enter Column number and value" << endl;
            head = new Node;
            cin >> head->col >> head->val;
            head->next = NULL;
            temp = head;
 
            for (int j = 1; j < num; j++)
            {
                Node *newnode = new Node;
                cin >> newnode->col >> newnode->val;
                newnode->next = NULL;
                temp->next = newnode;
                temp = newnode;
            }
            A[i] = head;
        }
    }

    Display(m,n,A);

    return 0;


}