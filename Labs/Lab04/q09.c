#include<stdio.h>
#include<stdlib.h>
#define ll long long int

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}

ll findGcdOfArray(int* arr,int n,int x){
    ll ans = 0;
    if(x == 0){
        ans = arr[1];
    }else{
        ans = arr[0];
    }
    for(int i=0;i<n;i++){
        if(i == x){
            continue;
        }
        ans = gcd(arr[i],ans);
    }
    return ans;
}

int main(void){
    ll n = 0;
    scanf("%lld",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    ll maxGcd = 0;
    for(int i=0;i<n;i++){
        ll ans = findGcdOfArray(arr,n,i);
        if(ans >= maxGcd){
            maxGcd = ans;
        }
    }
    printf("%lld\n",maxGcd);
    return 0;
}