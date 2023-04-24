#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int>& b){
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

int maxRussianDolls(vector<vector<int> >& v){
    sort(v.begin(),v.end(),cmp);
    int i,j,n = v.size();
    vector<int> list;

    for(int i=0;i<n;i++){
        auto it = lower_bound(list.begin(),list.end(),v[i][1]);
        if(it == list.end()){
            list.push_back(v[i][1]);
        }else{
            *it = v[i][1];
        }
    }
    return list.size();
}

int main(void){
    int n = 0;
    cin>>n;
    vector<vector<int> > v(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    int ans = maxRussianDolls(v);
    cout<<ans<<endl;
    return 0;
}