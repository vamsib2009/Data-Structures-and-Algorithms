#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    int a =10;
    int *p; //declaration   used during declaration or dereferencing
    p=&a;   //initialization

    //cout<<a<<endl;
    //printf("using pointer %d %d", *p, &a); //only p will print address

    //pointer to an array in stack
    int A[5]={2,4,6,8,10};
    int *q;
    q=A;

    for(int i=0;i<5;i++)
    cout<<q[i]<<endl; //can act as name of an array

    //Creating in a heap --> malloc function or for C++:
    //p = new int[5]  ;  p[0]=10, etc...
    //delete [ ] p; //release the pointer



    return 0;
}