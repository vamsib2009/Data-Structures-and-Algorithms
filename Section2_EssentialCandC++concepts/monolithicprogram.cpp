#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


//everything inside main function
int main(){

    int length=0,breadth=0;

    cin>>length>>breadth;

    int area=length*breadth;
    int peri=2*(length+breadth);

    cout<<area;

    return 0;
}