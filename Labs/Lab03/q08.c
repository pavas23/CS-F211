#include<stdio.h>
#include<stdlib.h>

int main(void){
    long long int n=0;

    // taking input
    scanf("%lld",&n);
    long long int low = 0;
    long long int high = n;
    long long int sqrt = 0;
    while(low <= high){
        long long int mid = (low+high)/2;
        if(mid*mid == n){
            sqrt = mid;
            break;
        }
        else if(mid*mid > n){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(sqrt == 0){
        // means n is not a perfect square
        low = 0;
        high = n;
        int flag = 0;
        while(low <= high){
            long long int mid = (low+high)/2;
            // diff should be greater than 0 and less than 1+2*mid as we are dropping the decimal part
            if(n - mid*mid >= 0 && n-mid*mid < 1+2*mid){
                sqrt = mid;
                flag = 1;
                break;
            }
            else if(n < mid*mid){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
    }
    printf("%lld\n",sqrt);
    return 0;
}


