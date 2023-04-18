#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cmp(string a,string b){
    return a+b > b+a;
}

int main(void){
    int n = 0;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(),cmp);
    string ans;
    for(int i=0;i<n;i++){
        ans += v[i];
    }
    cout<<ans<<endl;
    return 0;
}
