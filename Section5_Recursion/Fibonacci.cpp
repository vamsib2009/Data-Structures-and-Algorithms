#include <iostream>
#include <stdio.h>

using namespace std;

int F[10];


//Memoir fibonacci function: most efficient method with array
int mfib(int n){

    if(n<=1){
        F[n]=n;
        return n;
    }
    else{
        if(F[n-2]==-1)
            F[n-2]=mfib(n-2);
        if(F[n-1]==-1)
            F[n-1]=mfib(n-1);

        return F[n-2]+F[n-1];
    }
}

//factorial function
int nCr(int n, int r){

    if(n==r || r==0)
        return 1;
    return nCr(n-1,r-1)+nCr(n-1,r);
}


int main(){
int i;
for (i=0;i<10;i++)
    F[i]=-1;

printf("%d \n", mfib(8));
printf("%d", nCr(5,1) );

}