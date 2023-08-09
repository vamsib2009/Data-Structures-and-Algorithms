#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

void Insert(int A[], int n)
{
    int temp;
    int i=n;
    temp=A[n];  //temp<i/2 for min heap
    while(i>1 && temp>A[i/2]) //check greater than parent
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;

}

void CreateHeap()
{
    int A[]={0,10,20,30,25,5,40,35};
    int i;
    for(i=2;i<=7;i++)
        {
            Insert(A,i);
        }
}

//generally we tried to insert in Heap
int main(){


}