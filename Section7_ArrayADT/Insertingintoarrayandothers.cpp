#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

struct Array{
    int A[10]; 
    int size;
    int length;
};

void Append(struct Array *arr, int x) //modify the array - thus call by address
{

    if(arr->length<arr->size) //check if free space
        arr->A[arr->length++]=x; //insert in position length and also increment length

}

void Display(struct Array arr){

    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++){
        printf("%d ", arr.A[i]);
    }
}

void Insert(struct Array *arr, int index, int x){
    if(index>=0 && index<=arr->length){
        for (int i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index){

    int x=0;
    int i;

    if(index>=0 && index<arr->length){
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x; //deleted value
    }

    return 0;
}

//containing all the operations on arrays
int main(){
    struct Array arr={{2,3,4,5,6},20,5};
    int n, i; //numbers that are going to be inside

    //Append(&arr,10);
    Insert(&arr,1,10);
    printf("%d\n", Delete(&arr,4));
    Display(arr);

    return 0;
    }

