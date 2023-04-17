#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n=0,q=0;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> prevCandle(n,-1);
    vector<int> nextCandle(n,n);
    vector<int> prefixSum(n,0);
    for(int i=0;i<n;i++){
        prevCandle[i] = (s[i] == '*')?((i == 0) ? prevCandle[i] : prevCandle[i-1]) : i;
        nextCandle[n-i-1] = (s[n-i-1] == '*')?((i == 0)? nextCandle[n-i-1] : nextCandle[n-i]) : n-i-1;
        prefixSum[i] = (i == 0) ? (s[i] == '*') : prefixSum[i-1] + (s[i] == '*');
    }
    while(q--){
        int li=0,ri=0;
        cin>>li>>ri;
        int start = nextCandle[li];
        int end = prevCandle[ri];
        cout<<prefixSum[end]-prefixSum[start]<<endl;
    }
    return 0;
}

