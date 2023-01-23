#include<stdio.h>

int main(void){
    int a,b;
    // taking input
    scanf("%d %d",&a,&b);
    int primes[1000];
    int x = 0;

    // storing primes between a and b in array
    for(int i=a;i<=b;i++){
        int flag = 0;
        for(int k=2;k<i;k++){
            if(i%k == 0){
                flag = 1;
                break;
            }
        }
        if(!flag){
            primes[x] = i;
            x++;
        }
    }

    // initializing the frequency array
    int freq_arr[10];
    for(int i=0;i<10;i++){
        freq_arr[i] = 0;
    }
    for(int i=0;i<x;i++){
        int num = primes[i];
        while(num > 0){
            int r = num%10;
            freq_arr[r]++;
            num = num/10;
        }
    }

    // finding the digit with maximum frequency
    int max_freq = -1;
    int max_digit = -1;
    for(int i=0;i<10;i++){
        if(freq_arr[i] > max_freq){
            max_freq  = freq_arr[i];
            max_digit = i;
        }
    }
    printf("%d %d\n",max_digit,max_freq);
    return 0;
}





