#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool findSwap(vector<int> first, vector<int> second){
    set<int> x,y;
    set<int> :: iterator p,q;
    int sum1=0,sum2=0;
    for(int i=0;i<first.size();i++){
        sum1 += first[i];
        x.insert(first[i]);
    }
    for(int i=0;i<second.size();i++){
        sum2 += second[i];
        y.insert(second[i]);
    }
    if(abs(sum1-sum2)%2 != 0){
        return false;
    }
    for(p = x.begin(); p != x.end(); p++){
        q = y.find(((sum2-sum1) + 2*(*p))/2);
        if(q != y.end()){
            return true;
        }
    }
    return false;
}

int main(void){
    int n=0,m=0;
    cin>>n>>m;
    vector<int> first(n);
    vector<int> second(m);
    for(int i=0;i<n;i++){
        cin>>first[i];
    }
    for(int i=0;i<m;i++){
        cin>>second[i];
    }
    bool ans = findSwap(first,second);
    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}