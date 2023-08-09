#include <stdio.h>
#include <iostream>

using namespace std;

struct Rectangle{
    int length;
    int breadth;
    char x;
} r1,r2,r3;


int main()
{   
    r1 = {10,5};


    printf("%d", sizeof(r1));
    cout<<endl<<r1.length<<endl;

    return 0;
}
