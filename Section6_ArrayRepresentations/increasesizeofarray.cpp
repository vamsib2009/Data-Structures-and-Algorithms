#include <stdio.h>



int main(){

    int *p,*q;

    p = new int[2];
    p[0]=3;
    p[1]=5;

    q= new int[4];
    for (int i=0;i<2;i++)
        q[i]=p[i]; //memcpy also work. This copy p elements to q

    delete []p;
    p=q;
    q=NULL;


    for (int i=0;i<2;i++)
        printf("%d \n", p[i]);
        printf("%u", &p);

    return 0;
}