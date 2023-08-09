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

void InsertSort(struct Array *arr, int x){
    int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int isSorted(struct Array arr){

    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1; //already sorted
    return 0;
}

//rearrange +ve and -ve

struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); //so that can use merge result in main function

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[i++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i]; //copy leftover elements 
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=11;

    return arr3;

}

int main(){
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,4,7,18,20},10,5};

    struct Array *arr3; 

    
    arr3 =Merge(&arr1,&arr2);
    Display(*arr3); //since call by value //maybe wrong

    return 0;

}