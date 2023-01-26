// left
#include<stdio.h>

int main(void){
    int n=0;
    scanf("%d",&n);
    int arr[n*n];
    for(int i=0;i<n*n;i++){
        arr[i] = 2+2*i;
    }
    for(int i=0;i<n*n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // if n is even
            if(n%2 == 0){
                // first row
                if(i == 0){
                    matrix[i][j] = arr[n*n-1]-(2*j);
                }
                // last row
                else if(i == n-1){
                    matrix[i][n-j-1] = arr[n*n-(2*n-1)]-(2*j);
                }
                // middle row
                else if(i == n/2){

                }
                // remaining rows
                else{
                    if(j == 0){

                    }
                    else if(j == n-1){

                    }
                    else{

                    }
                }
            }
            // if n is odd
            else{
                // first row
                if(i == 0){
                    matrix[i][j] = arr[n*n-(2*n-1)]-(2*j);
                }
                // last row
                else if(i == n-1){
                    matrix[i][n-j-1] = arr[n*n-1]-(2*j);
                }
                // middle row
                else if(i == n/2){
                    if(j == 0){
                        matrix[i][j] = arr[(n*n)-((2*n)-(i+1))];
                    }
                    else if(j == n-1){
                        matrix[i][j] = arr[n*n-(2*n+i+(n-2))];
                    }
                    else{

                    }
                }
                // remaining rows
                else{
                    if(j == 0){
                        matrix[i][j] = arr[(n*n)-((2*n)-(i+1))];
                    }
                    else if(j == n-1){
                        matrix[i][j] = arr[n*n-(2*n+i+(n-2))];
                    }
                    else{
                        if(i < n/2){
                            matrix[i][j] = arr[(n-i)*i] - (2*(j-1));
                        }
                        else if(i>n/2){
                            matrix[i][j] = arr[(n-i)*i] + (2*(j-1));
                        }
                    }
                }
                
            }
        }
    }

    printf("\n");
    int flag = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-1;j++){
            if(matrix[i][j]-matrix[i][j+1] == 2 || matrix[i][j]-matrix[i][j+1] == -2){
                printf("%d - ",matrix[i][j]);
            }
            flag++;
        }
        if(flag%2 == 0){
            printf("\n");
            for(int j=0;j<n;j++){
                if(matrix[i][j] - matrix[i-1][j] == 2 || matrix[i][j] - matrix[i-1][j] == -2){
                    printf("|");
                }
                else{
                    printf(" ");
                }
            }
            flag++;
        }
    }
    printf("\n");
}



