#include<stdio.h>
#include<stdlib.h>

int findTrailingZeros(int n){
    if(n<0){
        return -1;
    }
    int count = 0;
    for(int i=5;n/i>=1;i*=5){
        count += n/i;
    }
    return count;
}

int findPairs(int n){
    return n*(n-1)/2;
}

int main(void){
    int n = 0;
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int* trailingZeros = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        trailingZeros[i] = findTrailingZeros(arr[i]);
    }
    int maxTrailingZeros = -1;
    for(int i=0;i<n;i++){
        if(trailingZeros[i]>maxTrailingZeros){
            maxTrailingZeros = trailingZeros[i];
        }
    }
    int count[maxTrailingZeros+1];
    for(int i=0;i<maxTrailingZeros+1;i++){
        count[i] = 0;
    }
    for(int i=0;i<n;i++){
        count[trailingZeros[i]]++;
    }
    int numPairs = 0;
    for(int i=0;i<maxTrailingZeros+1;i++){
        numPairs += findPairs(count[i]);
    }
    printf("%d\n",numPairs);
    return 0;
}
