#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,x,y;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>x>>y;
    vector<int> a;
    map<int,int> mp;

    int count=0;
    for(int j=0;j<n;j++){
        int temp=v[j]-j*y;
        a.push_back(temp);
        mp[temp]++;
    }

    for(int i=0;i<n;i++){
        int temp=v[i]-x*i;
        mp[a[i]]--;
        count += mp[temp];
    }
    cout<<count<<endl;
    return 0;
}

