#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int subarrayXOR(vector<int> v,int n){
    int ans = 0;
    vector<int> prefixXOR(n);
    map<int,int> mp;
    prefixXOR[0] = v[0];
    for(int i=1;i<n;i++){
        prefixXOR[i] = prefixXOR[i-1] ^ v[i];
    }
    for(int i=0;i<n;i++){
        int temp = 0^prefixXOR[i];
        ans += mp[temp];
        if(prefixXOR[i] == 0){
            ans++;
        }
        mp[prefixXOR[i]]++;
    }
    return ans;
}

int main(void){
    int n=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans = subarrayXOR(v,n);
    cout<<ans<<endl;
    return 0;
}
