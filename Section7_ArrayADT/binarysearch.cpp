#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

struct Array{
    int A[10]; 
    int size;
    int length;
};

void Display(struct Array arr){

    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++){
        printf("%d ", arr.A[i]);
    }
}

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

//there is iterative as well but using recursive here
int rBinarySearch(int a[], int l, int h, int key){

   int mid;

   if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if (key<a[mid])
            return rBinarySearch(a,l,mid-1,key);
        else
            return rBinarySearch(a, mid+1, h, key);

    }

    return -1;
}

int main(){
    struct Array arr={{2,3,4,5,6},20,5};
    int n, i; //numbers that are going to be inside

    printf("%d\n", rBinarySearch(arr.A,0,arr.length,5));
    Display(arr);

    return 0;



}