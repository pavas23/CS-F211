#include <stdio.h>

int main(void)
{
    int n=0;
    scanf("%d", &n);

    // 2n-1*2n-1 matrix as n elements and n-1 dashes in each row and each column.
    int a = 2*n - 1;
    int arr[a][a];

    // intializing the matrix to -5
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            arr[i][j] = -5;
        }
    }

    // f is the last element
    int f = 2 * n * n;
    int top = 0, left = 0, right = a - 1, bottom = a - 1;

    // if n is odd
    if(n%2 != 0){
        while (top <= bottom && left <= right && f >= 0){

            // for filling bottom row from right to left
            for (int i = right; i >= left; i -= 2){
                arr[bottom][i] = f;
                f -= 2;
            }
            bottom -= 2;

            // for filling left column from bottom to top
            for (int i = bottom; i >= top; i -= 2){
                arr[i][left] = f;
                f -= 2;
            }
            left += 2;

            // for filling top row from left to right
            for (int i = left; i <= right; i += 2){
                arr[top][i] = f;
                f -= 2;
            }
            top += 2;

            // for filling right column from top to bottom
            for (int i = top; i <= bottom; i += 2){
                arr[i][right] = f;
                f -= 2;
            }
            right -= 2;
    }
    }

    // if n is even
    else{
        while (top <= bottom && left <= right && f >= 0){

            // for filling top row from left to right
            for (int i = left; i <= right; i += 2){
                arr[top][i] = f;
                f -= 2;
            }
            top += 2;

            // for filling right column from top to bottom
            for (int i = top; i <= bottom; i += 2){
                arr[i][right] = f;
                f -= 2;
            }
            right -= 2;

            // for filling bottom row from right to left
            for (int i = right; i >= left; i -= 2){
                arr[bottom][i] = f;
                f -= 2;
            }
            bottom -= 2;

            // for filling left column from bottom to top
            for (int i = bottom; i >= top; i -= 2){
                arr[i][left] = f;
                f -= 2;
            }
            left += 2;
    }

    }
    
    // adding dashes
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
             // checking at even indices in a row if the diff between numbers is 2 or -2 then at odd index '-' will come
            if(j != 2*n-2){
                if(i%2 == 0 && j%2 == 0){
                    if(arr[i][j]-arr[i][j+2] == 2 || arr[i][j]-arr[i][j+2] == -2){
                        arr[i][j+1] = -1;
                    }
                }
            }
            // checking at even indices in a cloumns if the diff between numbers is 2 or -2 then at odd index '|' will come
            if(i != 2*n-2){
                if(i%2 == 0 && j%2 == 0){
                    if(arr[i][j]-arr[i+2][j] == 2 || arr[i][j]-arr[i+2][j] == -2){
                        arr[i+1][j] = -2;
                    }
                }
            }
        }
    }

    printf("\n");
    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            // at even index number will be there
            if (i % 2 == 0 && j % 2 == 0){
                printf("%3d", arr[i][j]);
            }
            if (arr[i][j] == -1){
                printf(" - ");
            }
            if (arr[i][j] == -2){
                printf(" | ");
            }
            // those indicies with -5 have nothing so empty space
            if (arr[i][j] == -5){
                printf("   ");
            }
        }
        printf("\n");
    }
    return 0;
}



