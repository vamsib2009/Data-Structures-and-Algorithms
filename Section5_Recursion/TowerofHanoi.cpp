#include <iostream>
#include <stdio.h>

using namespace std;

void TOH(int n, int A, int B, int C){
    if (n>0){
        TOH(n-1, A,C,B); //A to B using C
        printf("(%d,%d)\n", A,C);
        TOH(n-1, B,A,C); //B to C using A

    }
}


int main(){

    TOH(3,1,2,3); //giving the steps for moving the disks
    return 0;
}