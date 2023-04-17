#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findPlatforms(vector<int> arrival,vector<int> departure,int n){
    sort(arrival.begin(),arrival.end());
    sort(departure.begin(),departure.end());

    int platform = 1, ans = 1;
    int i = 1, j=0;
    
    while(i<n && j<n){
        if(arrival[i] <= departure[j]){
            platform++;
            i++;
        }else if(arrival[i] > departure[j]){
            platform--;
            j++;
        }
        if(platform > ans){
            ans = platform;
        }
    }
    return ans;
}

int main(void){
    int n = 0;
    cin>>n;
    vector<int> arrival(n);
    vector<int> departure(n);
    for(int i=0;i<n;i++){
        cin>>arrival[i];
        cin>>departure[i];
    }
    cout<<findPlatforms(arrival,departure,n)<<endl;
    return 0;
}