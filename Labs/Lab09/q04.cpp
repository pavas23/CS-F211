#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(void){
    int n=0,k=0;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<int,int> mp;
    int sum = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        sum += (v[i]-k);
        if(sum == 0){
            count++;
        }
        if(mp.find(sum) != mp.end()){
            count += mp[sum];
        }
        mp[sum]++;
    }
    cout<<count<<endl;
    return 0;
}

