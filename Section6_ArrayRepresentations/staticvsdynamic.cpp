#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    int A[5] = {2,4,6,8,10};
    int *p;
    int i;

    p = new int[5];
    p[0]=3;
    p[3]=9;

    for (i=0;i<5;i++)
        printf("%d \n", A[i]);

    for (i=0;i<5;i++)
        printf("%d \n", p[i]);

}