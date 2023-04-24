#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printKMax(vector<int> v,int k){
    deque<int> dq(k);
    for(int i=0;i<k;i++){
        while(!dq.empty() && v[i] >= v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i=k;i<v.size();i++){
        cout<<v[dq.front()]<<" ";
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && v[i] >= v[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<v[dq.front()]<<endl;
}

int main(void){
    int n=0,k=0;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    printKMax(v,k);
    return 0;
}
