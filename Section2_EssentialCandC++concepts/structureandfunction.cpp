#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle{

    int length;
    int breadth;
};

void initialise(Rectangle *r, int l, int b){

    r->length=l;
    r->breadth=b;


}

int area(struct Rectangle r){

    return r.length*r.breadth;
}

//int perimeter
int perimeter(struct Rectangle r){

    return 2*(r.length+r.breadth);
}

//can write a initialize function later with reference to video
int main(){

    Rectangle r={0,0};

    int l, b;
    cin>>l>>b;

    initialise(&r, l, b);


    int a= area(r);

    cout<<a<<endl;

}