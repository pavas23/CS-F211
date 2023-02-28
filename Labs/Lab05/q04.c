#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n=0,k=0,t=0;
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&t);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int start = 0;
    int end = k;
    int sum = 0;
    int numTeams = 0;
    int index = 0;
    int* prefixSum = (int*)calloc(n,sizeof(int));

    for(int i=0;i<k;i++){
        sum += arr[i];
    }
    
    prefixSum[index] = sum;
    index++;
    while(start<n && end<n){
        sum = sum - arr[start] + arr[end];
        prefixSum[index] = sum;
        index++;
        start++;
        end++;
    }
    for(int i=0;i<index;i++){
        if(prefixSum[i]/k >= t){
            numTeams++;
        } 
    }
    printf("%d\n",numTeams);
    return 0;
}