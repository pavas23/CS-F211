#include<stdio.h>
#include<stdlib.h>
#define ll long long

int main(void){
    ll int n = 0;
    ll int stage = 0;
    scanf("%lld",&n);
    if(n == 2){
        printf("%lld\n",stage+1);
        return 0;
    }
    ll int steps = 0;
    ll int totalComparisions = (n*(n-1))/2;
    ll int halfComparisions = totalComparisions/2;
    // in ith stage number of comparisions are n-i
    ll int highStep = n-1; // no. of comparisions in 1st stage
    ll int lowStep = 1;  // no. of comparisions in (n-1)th stage
    while(lowStep <= highStep){
        // midStep is the step
        ll int midStep = (lowStep+highStep)/2;
        ll int compAtMid = (midStep*n)-(midStep*(midStep+1))/2;
        if((compAtMid == halfComparisions) || (compAtMid-halfComparisions > 0 && compAtMid-halfComparisions < n-midStep)){
            stage = midStep;
            break;
        }
        else if(halfComparisions < compAtMid){
            highStep = midStep-1;
        }
        else{
            lowStep = midStep+1;
        }
    }
    printf("%lld\n",stage);
    return 0;
}