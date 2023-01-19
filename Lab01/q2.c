// left

#include<stdio.h>
#include<stdlib.h>

int main(void){

    // taking input of matrix A
    int m=0,n=0;
    scanf("%d %d",&m,&n); 
    int** matA = (int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        matA[i] = (int*)malloc(n*sizeof(int));
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matA[i][j]);
        }
    }

    // taking input of matrix B
    int p=0,q=0;
    scanf("%d %d",&p,&q);
    int** matB = (int**)malloc(p*sizeof(int*));
    for(int i=0;i<p;i++){
        matB[p] = (int*)malloc(q*sizeof(int));
    }

    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",&matB[i][j]);
        }
    }








}