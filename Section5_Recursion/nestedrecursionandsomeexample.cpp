#include <iostream>
#include <stdio.h>

using namespace std;

int fun(int n){ 

    if(n>100)
        return n-10;
    return fun(fun(n+11));
}

//sum of natural numbers
int sum(int n){
    if (n==0)
        return 0;
    return sum(n-1) +n;
}
//sum of factorial
int fact(int n){
    if (n==0)
        return 1;
    return fact(n-1) *n;
}

//iterative function for factorial for reference
int Ifact(int n){
    int f=1;
    int i;
    for(i=1;i<=n;i++)
        f=f*i;
        return f;
}

//iterative fuction for power
int pow(int m, int n){
    int ans = 1;
    for (int i=0; i<n;i++){
        ans = ans*m;
    }
    return ans;
}

//Taylor series basic
double e(int x, int n){
    static double p=1,f=1;
    double r; //result
    if (n==0)
        return 1;
    if (n!=0)
        r = e(x,n-1);
        p = p*x;
        f=f*n;
        return r+p/f;

}


int main(){

    int r;
    //r=fun(101); 
    //r = pow(9,3);

    printf("%lf\n",e(1,10)); //Taylor series
    return 0;

}
