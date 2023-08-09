#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle{
    int length;
    int breatdth;
};

int main(){

    //Create object in heap
    Rectangle *p;
    p = new Rectangle;

    p->length=15;



    return 0;
}