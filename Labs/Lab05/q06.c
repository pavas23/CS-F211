#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n=0,m=0;
    scanf("%d",&n);
    int* arr1 = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    scanf("%d",&m);
    int* arr2 = (int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        scanf("%d",&arr2[i]);
    }
    int xorA = 0;
    for(int i=0;i<n;i++){
        xorA = xorA^arr1[i];
    }
    int xorB = 0;
    for(int i=0;i<m;i++){
        xorB = xorB^arr2[i];
    }
    int nxorB = 0;
    for(int i=0;i<n;i++){
        nxorB = nxorB^xorB;
    }
    int mxorA = 0;
    for(int i=0;i<m;i++){
        mxorA = mxorA^xorA;
    }
    printf("%d\n",mxorA^nxorB);
    return 0;
}