#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void Missing(struct Array arr){
    int diff;
    diff = arr.A[0]-0;
    for(int i=0; i<arr.length-1;i++){
        if (arr.A[i]-i!=diff)
            while(diff<arr.A[i]-i){
                printf("%d \n", i+diff);
                diff++;
            }
    }
}

//element pair add to 10 (with hash table)
void Elementpair(struct Array arr){
    struct Array hash = {{0},14,14};
    int k;
    k =10;
    for(int i=0 ;i<arr.length-1;i++){
        if(hash.A[k-arr.A[i]]!=0 && (k-arr.A[i])>0){
            printf("%d+%d=%d \n",arr.A[i],k-arr.A[i],k);

        }
        hash.A[arr.A[i]]++;
    }
}

int main(){
    struct Array arr = {{2,4,5,6,8,10,11,12,13,14},20,10};
    Missing(arr); //success
    Elementpair(arr); //success



}