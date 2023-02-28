#include<stdio.h>
#include<stdlib.h>

int main(void){
    
    int n=0,k=0;
    scanf("%d",&n);
    scanf("%d",&k);
    int* arr = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int numSubArr = 0;
    int* prefixArr = (int*)calloc(k,sizeof(int));

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        prefixArr[sum%k]++;
    }

    for(int i=0;i<k;i++){
        if(prefixArr[i] > 1){
            numSubArr += (prefixArr[i]*(prefixArr[i]-1))/2;
        }
    }

    numSubArr += prefixArr[0];
    printf("%d\n",numSubArr);

    return 0;
}

