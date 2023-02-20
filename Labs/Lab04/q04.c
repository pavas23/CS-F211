#include<stdio.h>
#include<stdlib.h>

// Sieve Of EratoSthenes Algortihm

void sieveOfEratoSthenes(int* isPrime,int n){
    for(int i=0;i<n;i++){
        isPrime[i] = 1;
    }
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(int i=2;i*i<=n;i++){
        for(int j=2*i;j<=n;j+=i){
            isPrime[j] = 0;
        }
    }
    return;
}

int main(void){
    int n=0,q=0;
    scanf("%d",&n);
    scanf("%d",&q);
    int* arr = (int*)malloc(q*sizeof(int));
    for(int i=0;i<q;i++){
        scanf("%d",&arr[i]);
    }
    int* boolArr = (int*)calloc(n+1,sizeof(int));
    sieveOfEratoSthenes(boolArr,n+1);
    int* numOfPrimes = (int*)malloc((n+1)*sizeof(int));
    int sum = 0;
    for(int i=0;i<n+1;i++){
        sum += boolArr[i];
        numOfPrimes[i] = sum;
    }
    for(int i=0;i<q;i++){
        printf("%d ",numOfPrimes[arr[i]]);
    }
    printf("\n");
    return 0;
}
