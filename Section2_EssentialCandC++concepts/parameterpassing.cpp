#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int add(int *x, int *y){

    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int main(){
    int num1=10, num2=15,sum;

    sum =add(&num1,&num2); //will modify the values of actual parameters



    cout <<"Sum is"<<sum;

    return 0;

}