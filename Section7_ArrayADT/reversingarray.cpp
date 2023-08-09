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

//method 1
void Reverse(struct Array *arr ){
    int *B;
    int i,j;

    B=new int[arr->length];
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];

}

int main(){
    struct Array arr={{2,3,4,5,6},20,5};

    Reverse(&arr);
    Display(arr);

    return 0;

}