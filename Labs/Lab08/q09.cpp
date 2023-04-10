#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n=0,k=0;
    cin>>n>>k;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        int a=0,b=0;
        cin>>a>>b;
        v[i] = make_pair(a,b);
    }
    set<int> next;
    set<int> loser;
    for(int i=0;i<n;i++){
        next.insert(v[i].first);
    }
    for(int i=0;i<n;i++){
        int l = v[i].second;
        if(loser.find(l) != loser.end()){
            next.erase(l);
        }else{
            loser.insert(l);
            next.insert(l);
        }
    }
    for(auto i = next.begin();i != next.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}
