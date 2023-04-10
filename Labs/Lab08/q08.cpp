#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin>>s;
    int n = s.length();
    multimap<string,int> map;
    for(int i=0;i<n;i++){
        string str;
        for(int j=i;j<i+10;j++){
            str += s[j];
        }
        map.insert(make_pair(str,i));
    }
    vector<string> v;
    for(auto i = map.begin(); i != map.end();i++){
        string str = i->first;
        v.push_back(str);
    }
    int ans = 0;
    vector<string> unique;
    for(int i=0;i<v.size()-1;i++){
        int count = 1;
        while(i+1 < n && v[i] == v[i+1]){
            count++;
            i++;
        }
        if(count > 1){
            unique.push_back(v[i]);
        }
    }
    ans = unique.size();
    cout<<ans<<endl;
    for(int i=0;i<ans;i++){
        cout<<unique[i]<<endl;
    }
    return 0;
}