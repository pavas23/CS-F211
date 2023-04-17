#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> pages,int mid,int k){
    int count = 0;
    int sum = 0;
    int n = pages.size();
    for(int i=0;i<n;i++){
        if(pages[i] > mid){
            return false;
        }
        sum += pages[i];
        if(sum > mid){
            count++;
            sum = pages[i];
        }
    }
    count++;
    if(count <= k){
        return true;
    }
    return false;
}

int solve(vector<int> pages, int k){
    int max = *max_element(pages.begin(),pages.end());
    int start = max;
    int end = 0;
    int n = pages.size();
    for(int i=0;i<n;i++){
        end += pages[i];
    }
    int ans = 0;
    while(start <= end){
        int mid = (start+end)/2;
        if(check(pages,mid,k)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}

int main(void){
    int n=0,m=0;
    cin>>n>>m;
    vector<int> pages(n);
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    int ans = solve(pages,m);
    cout<<ans<<endl;
    return 0;
}