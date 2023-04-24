#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n = 0,m=0;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    map<int,int> mp;
    map<int,bool> visited;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        visited[a[i]] = false;
        mp[a[i]]++;
    }
    vector<int> result;
    for(int i=0;i<m;i++){
        if(mp.find(b[i]) != mp.end()){
            visited[b[i]] = true;
            int num = mp[b[i]];
            for(int j=0;j<num;j++){
                result.push_back(b[i]);
            } 
        }
    }

    for(int i=0;i<n;i++){
        if(visited[a[i]] == false){
            result.push_back(a[i]);
        }
    }

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}