#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kadanesAlgorithm(vector<int> v){
    int maxSum = INT_MIN;
    int currSum = 0;
    for(int i=0;i<v.size();i++){
        currSum += v[i];
        if(currSum > maxSum){
            maxSum = currSum;
        }
        if(currSum < 0){
            currSum = 0;
        }
    }
    return maxSum;
}

int main(void){
    int n = 0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans = kadanesAlgorithm(v);
    cout<<ans<<endl;
    return 0;
}
