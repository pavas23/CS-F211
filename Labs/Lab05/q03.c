#include<stdio.h>
#include<stdlib.h>

int main(void){

    int n=0,k=0;
    scanf("%d",&n);
    scanf("%d",&k);
    char arr[n+1];
    scanf("%s",arr);

    int freq_arr[k];
    for(int i=0;i<k;i++){
        freq_arr[i] = 0;
    }

    int numSubstrings = 0;
    int start = 0;
    int end = 0;
    int currSum = 0;

    while(start<n && end<n){
        int flag = 0;
        currSum = 0;
        freq_arr[arr[end]-'a']++;
        for(int i=0;i<k;i++){
            if(freq_arr[i] != 0){
                currSum += 1;
            }
        }
        if(currSum == k){
            numSubstrings += 1 + (n-1) - end;
            freq_arr[arr[start]-'a']--;
            start++;
            flag = 1;
        }
        if(!flag){
            end++;
        }else{
            freq_arr[arr[end]-'a']--;
        }
    }

    printf("%d\n",numSubstrings);
    return 0;
}
