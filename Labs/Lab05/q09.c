#include<stdio.h>
#include<stdlib.h>

int main(void){

    long long int n=0,k=0;
    scanf("%lld",&n);
    scanf("%lld",&k);
    long long int* arr = (long long int*)malloc(n*sizeof(long long int));
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }

    long long int numSubArr = 0;
    long long int* oddArr = (long long int*)calloc(n,sizeof(long long int));

    long long int x = 0;
    for(long long int i=0;i<n;i++){
        if(arr[i]%2 != 0){
            oddArr[x] = i;
            x++;
        }
    }

    long long int start = 0;
    long long int end = k-1;
    while(start < x){
        long long int startOptions = 0;
        long long int endOptions = 0;
        if(start == 0){
            if(oddArr[start]-1 >=0){
                startOptions = oddArr[start]+1;
            }else{
                startOptions = 1;
            }
        }else{
            startOptions = oddArr[start]-oddArr[start-1];
        }
        if(end+1 < x){
            endOptions = oddArr[end+1]-oddArr[end];
        }else if(end < x){
            if(oddArr[end]+1 < n){
                endOptions = (n-1)-oddArr[end]+1;
            }else{
                endOptions = 1;
            }
        }else{
            break;
        }
        numSubArr += startOptions*endOptions;
        start++;
        end = start+k-1;
    }

    printf("%lld\n",numSubArr);
    return 0;
}

