#include<stdio.h>
#include<stdlib.h>

int findSum(int** mat,int m,int n,int row,int col){
    int sum = 0;
    int y = col;
    if(y<n){
        y = n;
    }
    for(int i=0;i<=row;i++){
        for(int j=0;j<=y;j++){
            if(i == row){
                y = col;
            }
            sum += mat[i][j];
        }
    }
    return sum;
}

int main(void){

    // taking user input
    int m = 0,n= 0;
    int ri=0,ci=0,rh=0,ch=0;
    printf("Enter the value of m and n\n");
    scanf("%d %d",&m,&n);

    printf("Enter the matrix A\n");
    // declaring 2D array using pointers
    int** matrixA;
    // matrixA contains m pointers pointing to int datatype
    matrixA = (int**)malloc(m*sizeof(int*));
    // each pointer is allocated memory to point to n int values
    for(int i=0;i<m;i++){
        int* temp = (int*)malloc(n*sizeof(int));
        matrixA[i] = temp;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrixA[i][j]);
        }
    }

    printf("\nEnter the value of ri, ci, rh, ch\n");
    scanf("%d %d %d %d",&ri,&ci,&rh,&ch);

    // finding matrixB
    int matrixB[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            matrixB[i][j] = findSum(matrixA,m,n,i,j);
        }
    }

    // printing matrixB
    printf("\n");
    printf("Matrix B\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrixB[i][j]);
        }
        printf("\n");
    }

    int downRows = ri + rh;
    int rightCols = ci + ch;

    printf("\n");
    if(downRows > m || rightCols > n){
        printf("NOT POSSIBLE\n");
    }
    else{
        long int sum = 0;
        for(int i=ri;i<downRows;i++){
            for(int j=ci;j<rightCols;j++){
                sum += matrixB[i][j];
            }
        }
        printf("%ld\n\n",sum);
    }

    return 0;
}

