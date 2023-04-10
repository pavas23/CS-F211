#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkAnagram(vector<int> a,vector<int> b){
    for(int i=0;i<26;i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

int main(void){
    int n=0,m=0;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int> >freq_arr(n,vector<int>(26,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].length();j++){
            freq_arr[i][v[i][j]-'a']++;
        }
    }
    multimap<vector<int>,int> map;
    for(int i=0;i<n;i++){
        map.insert(make_pair(freq_arr[i],i));
    }
    int index = 0;
    for(auto i = map.begin();i != map.end();i++){
        vector<int> v = i->first;
        for(int j=0;j<26;j++){
            freq_arr[index][j] = v[j];
        }
        index++;
    }
    int num_pairs = 0;
    for(int i=0;i<n-1;i++){
        int count = 1;
        while(i+1 < n && checkAnagram(freq_arr[i],freq_arr[i+1])){
            count++;
            i++;
        }
        num_pairs += (count*(count-1))/2;
    }
    cout<<num_pairs<<endl;
    return 0;
}
