#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int area(int length, int breadth){

    return length*breadth;
}

//int perimeter
int perimeter(int length, int breadth){

    return 2*(length+breadth);
}

int main(){

    int length=0,breadth=0;

    cin>>length>>breadth;

    int a= area(length,breadth);

    cout<<a<<endl;

}