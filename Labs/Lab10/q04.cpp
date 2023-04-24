#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> pancakeSteps;

void flip(vector<int>& v,int i){
    pancakeSteps.push_back(i+1);
    int temp, start = 0;
    while(start < i){
        temp = v[start];
        v[start] = v[i];
        v[i] = temp;
        start++;
        i--;
    }
}

void pancakeSort(vector<int> v,int n){
    if(n == 1){
        return;
    }
    int mi = 0;
    for(int i=0;i<n;i++){
        if(v[i] > v[mi]){
            mi = i;
        }
    }
    if(mi != 0){
        flip(v,mi);
    }
    flip(v,n-1);
    pancakeSort(v,n-1);
    return;
}

int main(void){
    int n = 0;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    pancakeSort(v,n);
    int m = 0;
    m = pancakeSteps.size();
    cout<<m<<endl;
    for(int i=0;i<m;i++){
        cout<<pancakeSteps[i]<<" ";
    }
    cout<<endl;
    return 0;
}
