#include<stdio.h>
#include<stdlib.h>

int minimum(int a,int b){
    if(a<=b){
        return a;
    }
    return b;
}

int maximum(int a,int b){
    if(a>=b){
        return a;
    }
    return b;
}

int minUnfairness(int* buckets,int currBucket,int n,int maxPieces,int* pieces,int k){
    if(currBucket == n){
        return maxPieces;
    }
    int currMinUnfairness = 99999999;
    for(int i=0;i<k;i++){
        pieces[i] += buckets[currBucket];
        currMinUnfairness = minimum(currMinUnfairness,minUnfairness(buckets,currBucket+1,n,maximum(maxPieces,pieces[i]),pieces,k));
        pieces[i] -= buckets[currBucket];
    }
    return currMinUnfairness;
}

int main(void){
    int n=0,k=0;
    scanf("%d",&n);
    scanf("%d",&k);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int* pieces = (int*)malloc(k*sizeof(int));
    for(int i=0;i<k;i++){
        pieces[i] = 0;
    }
    int ans = minUnfairness(arr,0,n,0,pieces,k);
    printf("%d\n",ans);
    return 0;
}

