#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }

    map<int,int,greater<int> > pq;
    map<int,int> mp;
    for(int i=0;i<m;i++){
        mp[x[i]]++;
    }
    for(auto i:mp){
        if(i.second==k){
            pq[i.first]=1;
        }
    }

    int i=0,j=m-1;
    while(j<n){
        if(pq.empty()){
            cout<<-1<<endl;
        }else{
            cout<<pq.begin()->first<<endl;
        }
        if(pq.begin()->first==x[i]){
            mp[x[i]]--;
            pq.erase(x[i]);
            i++;
        }else{
            mp[x[i]]--;
            i++;
            if(mp[x[i]]==k){
                pq[x[i]]=1;
            }
        }
        j++;
        mp[x[j]]++;
        if(mp[x[j]]==k){
            pq[x[j]]=1;
        }
        else if(mp[x[j]]>k){
            pq.erase(x[j]);
        }
    }
    return 0;
}