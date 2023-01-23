#include<stdio.h>

int main(void){
    int n=0;
    scanf("%d",&n);
    int top = n*n-n;
    int bottom  = 2*n+2;
    int count_top = 0;
    int count_bottom = 0;
    for(int i=0;i<n*n;i++){
        if(i%2 != 0){
            if(count_top != 0){
            top -= 2;
            }
            printf("%d ",top);
            count_top++;
        }
        else{
            if(count_bottom != 0){
                bottom -= 2;
            }
            printf("%d ",bottom);
            count_bottom++;
        }
    }
    printf("\n");
}



