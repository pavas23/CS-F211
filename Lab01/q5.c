#include<stdio.h>

int main(void){
    int n=0;
    scanf("%d",&n);
    int count = 0;
    for(int i=n*n-1;i>=0;i--){
        count++;
        if(count%n != 0){
            printf("%d - ",2+i*2);
        }
        else if(count%n == 0){
            printf("%d | ",2+i*2);
        }
        if(count%n == 0){
            printf("\n");
        }
    }
    printf("\n");
}



