#include<stdio.h>
#include<stdlib.h>

int printBracketsHelper(int pos,int n,int openCount,int closeCount,int* k,char*** matrixRef){
    char** matrix = *matrixRef;
    static char arr[14];
    if(closeCount == n/2){
        arr[pos] = '\0';
        (*k)++;
        matrix = (char**)realloc(matrix,(*k)*sizeof(char*));
        matrix[(*k)-1] = (char*)malloc(14*sizeof(char));
        int x = 0;
        while(arr[x] != '\0'){
            matrix[(*k)-1][x] = arr[x];
            x++;
        }
        matrix[(*k)-1][x] = '\0';
        *matrixRef = matrix;
        return *k;
    }
    else{
        if(openCount > closeCount){
            arr[pos] = ')';
            printBracketsHelper(pos+1,n,openCount,closeCount+1,k,matrixRef);
        }
        if(openCount < n/2){
            arr[pos] = '(';
            printBracketsHelper(pos+1,n,openCount+1,closeCount,k,matrixRef);
        }
    }
    return *k;
}

int printBrackets(int n,int* k,char*** matrix){
    if(n>0){
        return printBracketsHelper(0,n,0,0,k,matrix);
    }
    return 0;
}

int main(void){
    int n = 0;
    scanf("%d",&n);
    int k = 0;
    char** matrix;
    k = printBrackets(n,&k,&matrix);
    printf("%d\n",k);
    for(int i=0;i<k;i++){
        int j = 0;
        while(matrix[i][j] != '\0'){
            printf("%c",matrix[i][j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}
