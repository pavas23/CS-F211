#include<stdio.h>
#include<stdlib.h>
#define ll long long int

// for finding gcd of two numbers use Euclidian Theorem gcd(a,b) = gcd(b,a%b)
// Time Complexity is O(log(min{a,b}))
ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}

ll findLargestDivisorCoprime(ll a,ll b){
    ll ans = 0;
    // for finding all divisors of n in O(sqrt(n)), there will be two divisors for each i, i and n/i
    for(int i=1;i*i<=a;i++){
        if(a%i == 0){
            if(gcd(i,b) == 1){
                // if i is coprime with b and greater than current value of ans
                if(i > ans){
                    ans = i;
                }
            }
            if(gcd(a/i,b) == 1){
                // if a/i is coprime with b and greater than current value of ans
                if(a/i > ans){
                    ans = a/i;
                }
            }
        }
    }
    return ans;
}

int main(void){
    ll a=0,b=0;
    scanf("%lld",&a);
    scanf("%lld",&b);
    ll largestNumCoPrime = findLargestDivisorCoprime(a,b);
    printf("%lld\n",largestNumCoPrime);
    return 0;
}
