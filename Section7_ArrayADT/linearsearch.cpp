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

int LinearSearch(struct Array *arr, int key)
{
    int i;
    for(i=0;i<arr->length;i++){
        if (key==arr->A[i]){
            swap(&arr->A[i],&arr->A[i-1] ); //transposition
            return i;

        }
    }
    return -1;
}

int main(){
    struct Array arr={{2,3,4,5,6},20,5};
    int n, i; //numbers that are going to be inside

    printf("%d\n", LinearSearch(&arr,4));
    Display(arr);

    return 0;



}