#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}

int countTriangles(vector<pair<int,int> > p,int n){
    map<pair<int,int>,int> mp;
    int ans = 0;
    for(int i=0;i<n;i++){
        mp.clear();
        for(int j=i+1;j<n;j++){
            int x = p[i].first-p[j].first;
            int y = p[i].second-p[j].second;
            int g = gcd(x,y);
            x /= g;
            y /= g;
            mp[make_pair(x,y)]++;
        }
        int num = n - (i+1);
        ans += (num*(num-1))/2;
        for(auto j : mp){
            ans -= (j.second*(j.second-1))/2;
        }
    }
    return ans;
}

int main(void){
    int n = 0;
    cin>>n;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        int a=0,b=0;
        cin>>a>>b;
        v[i] = make_pair(a,b);
    }
    int ans = countTriangles(v,n);
    cout<<ans<<endl;
    return 0;
}
