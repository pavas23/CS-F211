#include<stdio.h>
#include<stdlib.h>
#define ll long long int

int main(void){
    ll n = 0;
    scanf("%lld",&n);
    ll low = 1;
    ll high = n;
    ll count = 1;
    ll ans = 0;
    ll num = 1;
    ll currLen = n;

    // in every iteration low and high will point to start and end of remaining elements
    while(low <= high){
        currLen = (high-low)/count+1;
        if(high - low <= count){
            // when only 2 elements are left, if n is even then it will start from end
            if(num%2 == 0){
                ans = low;
            }else{
                ans = high;
            }
            break;
        }
        // for even length high and low move alternately
        if(currLen%2 == 0 && num%2 == 0){
            high -= count;
        }
        if(currLen%2 == 0 && num%2 != 0){
            low += count;
        }
        // for odd length both low and high move in every iteration
        if(currLen%2 != 0){
            low += count;
            high -= count;
        }
        count *= 2;
        num++;
    }
    printf("%lld\n",ans);
    return 0;
}
