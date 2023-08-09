#include <stdlib.h>
#include <iostream>
#include <stdio.h>


using namespace std;

class UpperTri{
private:
    int *A;
    int n;
public:
    UpperTri(){
        n=2;
        A = new int[2*(2+1/2)]; //default constructor of dimension 2 by 2
    }
    UpperTri(int n){
        this->n=n; //left side means n above in class. Right n is local parameter
        A=new int[n*(n+1)/2];
    }
    ~UpperTri()
    {delete []A;} 

    void Set (int i, int j, int x);
    int Get(int i, int j);
    void Display();  
    int GetDimension(){return n;}
    
    };

void UpperTri::Set(int i, int j, int x){
    if(j>=i)
        A[(j*(j-1))/2 + i-1] = x;
}

int UpperTri::Get(int i, int j){
    if(i>=j)
        return  A[(j*(j-1))/2 + i-1];
    return 0;
}

void UpperTri::Display()
{
    int i, j;
    for(i=1;i<=n;i++){
        
        for (j=1;j<=n;j++){
        if(i<=j)
            printf("%d ",  A[(j*(j-1))/2 + i-1]);
        else
            printf("0 "); }
        printf("\n");
    }

}

int main(){

    int d;
    cout<<"Enter Dimensions";
    cin>>d;
    UpperTri lm(d);

    int x;
    cout<<"Enter all elements \n";
    for(int i=1; i<=d;i++){
        for(int j=1; j<=d;j++){
            cin>>x;
            lm.Set(i,j,x);
        }
    }

    lm.Display();
    return 0;

}