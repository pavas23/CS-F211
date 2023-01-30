#include<stdio.h>
#include<stdlib.h>

// function for checking rows
int checkRow(int* arr1,int* arr2,int siA,int nA,int siB,int nB){

    // comparing two arrays
    for(int i=siA;i<=nA;i++){
        if(arr1[i] != arr2[i-siA]){
            return 0;
        }
    }
    return 1;
}

// function for checking columns
int checkCol(int** matB,int colB,int** matA,int colA,int siA,int nA,int siB, int nB){
    
    // finding the size of two columns
    int size = nA-siA+1;
    int* arr1 = (int*)malloc(size*sizeof(int));
    int* arr2 = (int*)malloc(size*sizeof(int));

    // making arr1 for col of matA
    for(int i=siA;i<=nA;i++){
        arr1[i-siA] = matA[i][colA];
    }

    // making arr2 for col of matB
    for(int j=siB;j<=nB;j++){
        arr2[j-siB] = matB[j][colB];
    }

    // comparing two arrays
    for(int i=0;i<size;i++){
        if(arr1[i] != arr2[i]){
            return 0;
        }
    }
    return 1;
}

int main(void){

    // taking input of matrix A
    int m=0,n=0;
    scanf("%d %d",&m,&n); 
    int** matA = (int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        int* temp = (int*)malloc(n*sizeof(int));
        matA[i] = temp;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matA[i][j]);
        }
    }

    //taking input of matrix B
    int p=0,q=0;
    scanf("%d %d",&p,&q);
    int** matB = (int**)malloc(p*sizeof(int*));
    for(int i=0;i<p;i++){ 
        int* temp = (int*)malloc(q*sizeof(int));
        matB[i] = temp;
    }

    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",&matB[i][j]);
        }
    }

    int rows_identical = 0;
    int cols_identical = 0;

    // checking number of identical rows
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            for(int x=0;x<m;x++){
                int ans = 0;
                for(int y=0;y<n;y++){
                    if(matB[i][j] == matA[x][y]){
                        // passing checkRow row of matA,row of matB, start index of A, end index of A, start index of B, end Index of B,
                        if(y+q-1<n){
                            // call function only if end index of matA < n i.e. both rows are of same size
                            ans = checkRow(matA[x],matB[i],y,y+q-1,0,q-1);
                        }
                        if(ans == 1){
                            rows_identical++;
                        }
                    }
                    if(ans == 1){
                        break;
                    }
                }
                // if that row is found identical to some row in matA then go to next row in matB
                if(ans == 1){
                    break;
                }
            }
            break;
        }
    }

    // checking number of indentical columns
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            for(int x=0;x<m;x++){
                int ans = 0;
                for(int y=0;y<n;y++){
                    if(matB[i][j] == matA[x][y]){
                        // passing checkCol matB, col of B, matA, col of A, start index of A, end index of A, start index of B, end index of B
                        if(x+p-1 < m){
                            // call function only if end index of matA < m i.e. both cols are of same size
                            ans = checkCol(matB,j,matA,y,x,x+p-1,0,p-1);
                        }
                        if(ans){
                            cols_identical++;
                        }
                    }
                }
                if(ans == 1){
                    break;
                }
            }
        }
        break;
    }

    if(rows_identical == p && cols_identical == q){
        printf("Number of Identical Rows: %d and Number of Identical Columns: %d\n",rows_identical,cols_identical);
        printf("YES\n");
        exit(0);
    }
    else if(rows_identical > 0 || cols_identical > 0){
        printf("Number of Identical Rows: %d and Number of Identical Columns: %d\n",rows_identical,cols_identical);
        printf("PARTIAL\n");
        exit(0);
    }
    else{
        printf("Number of Identical Rows: %d and Number of Identical Columns: %d\n",rows_identical,cols_identical);
        printf("NO\n");
    }
    return 0;
}

