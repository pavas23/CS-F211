#include<stdio.h>
#include<stdlib.h>

int checkPossible(int* arr,int n,int k,int x){
    int numPlanks = 0;
    for(int i=0;i<n;i++){
        if(arr[i] >= x){
            numPlanks += arr[i]/x;
        }
    }
    if(numPlanks >= k){
        return 1;
    }
    return 0;
}

int main(void){
    int n=0,k=0;
    scanf("%d",&n);
    scanf("%d",&k);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",(arr+i));
    }
    int max = -1;
    for(int i=0;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int low = 1;
    int high = max;
    int maxLength = 0;
    while(low <= high){
        int midLength = (low+high)/2;
        if(checkPossible(arr,n,k,midLength)){
            maxLength = midLength;
            low = midLength+1;
        }
        else{
            high = midLength-1;
        }
    }
    printf("%d\n",maxLength);
    return 0;
}

