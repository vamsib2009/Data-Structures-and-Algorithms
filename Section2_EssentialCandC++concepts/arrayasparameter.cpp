#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void fun(int *A, int n){ //or can use A[]
    A[0] = 15; //call by address
    for (int i=0; i<n; i++)
    cout<<A[i]<<endl; //any change here will change the overall value

}


int main(){
    int A[]={2,4,6,8,10};
    int n = 5;
    fun (A,n);



}