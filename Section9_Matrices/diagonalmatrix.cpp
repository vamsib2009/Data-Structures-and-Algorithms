#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

class Diagonal{
private:
    int *A;
    int n;
public:
    Diagonal(){
        n=1;
        A = new int[2];
    }
    Diagonal(int n){
        this->n=n; //left side means n above in class. Right n is local parameter
        A=new int[n];
    }
    ~Diagonal()
    {delete []A;} 

    void Set (int i, int j, int x);
    int Get(int i, int j);
    void Display();  
    
    };

void Diagonal::Set(int i, int j, int x){
    if(i==j)
        A[i-1]=x;
}

int Diagonal::Get(int i, int j){
    if(i==j)
        return A[i-1];
    return 0;
}

void Diagonal::Display()
{
    int i, j;
    for(i=0;i<n;i++){
        
        for (j=0;j<n;j++){
        if(i==j)
            printf("%d ", A[i]);
        else
            printf("0 "); }
        printf("\n");
    }

}

int main(){

    Diagonal d(4);
    d.Set(1,1,5);d.Set(2,2,8);d.Set(4,4,10);d.Set(3,3,9);
    d.Display();
    return 0;

}