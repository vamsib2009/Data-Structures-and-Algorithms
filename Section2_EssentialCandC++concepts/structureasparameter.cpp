#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

void fun(struct Rectangle *p) //void means it doesnt return anything
{
    p->length=25;
    cout<<"Length "<<p->length<<endl;
    cout<<"Breadth "<<p->breadth<<endl;
}

int main(){

    struct Rectangle r={10,5};
    fun(&r);
    cout<<r.length<<endl;
    
    //struct Rectanngle *ptr =fun();  #Create an object inside heap and accessing it through main function
    //cout<<ptr->length;
    
    return 0;
}

//for creating in heap
/*
struct Rectangle *fun(){

    struct Rectangle *p;
    p=new Rechtangle;
    p->length=15;
    p->breadth=26;
    return p;
}

*/