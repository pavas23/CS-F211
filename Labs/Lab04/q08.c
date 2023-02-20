#include<stdio.h>
#include<stdlib.h>

int main(void){
    long long int n=0,m=0;
    scanf("%lld",&n);
    scanf("%lld",&m);

    // for finding max
    long long int remaining = n-(m-1);
    long long int maxPairs = 0;
    maxPairs = (n-(m-1))*(n-(m-1)-1)/2;

    // for finding min pairs
    long long int minPairs = 0;
    long long int y = n%m;
    long long int x = n/m;
    minPairs = (((x+1)*x)/2)*y + ((x*(x-1))/2)*(m-y);

    printf("%lld %lld\n",minPairs,maxPairs);
    return 0;
}
