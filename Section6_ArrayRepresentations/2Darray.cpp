#include <stdio.h>
#include <stdlib.h>

int main(){

//second method
int *B[3];
B[0] = new int[4];
B[1] = new int[4];
B[2] = new int[4];

//third method
int **C;
C= new int*[3];
C[0] = new int[4];
C[1] = new int[4];
C[2] = new int[4];

int i,j;

for (i = 0; i<3; i++){
    for (j=0;j<4;j++){
        printf("%d ",C[i][j]);
    }
    printf("\n");
}





}