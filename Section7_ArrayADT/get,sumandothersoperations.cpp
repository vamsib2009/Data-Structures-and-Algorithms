#include <stdlib.h>
#include <iostream>
#include <stdio.h>

//Haven't tried these functions, try try.

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

void Set(struct Array *arr, int index, int x){
    if(index>=0 && index <arr->length)
        arr->A[index]=x;

}

int Max(struct Array arr) //similar for min
{
    int max = arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]>max)
            max=arr.A[i];}
    return max;

}

int Sum(struct Array arr){
    int s=0;
    int i;
    for(i=0;i<arr.length;i++)
        s+=arr.A[i];
    return s;
}

int Get(struct Array arr, int index){
    if(index>=0 && index <arr.length)
        return arr.A[index];
    return -1;
}

float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}


int main(){
    struct Array arr={{2,3,4,5,6},20,5};

    Display(arr);

    return 0;

}
