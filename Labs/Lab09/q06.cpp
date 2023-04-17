#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n=0,k=0;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int ans = 0;
    vector<int> leftArr;
    vector<int> rightArr;
    int mid = n/2;
    int x = mid;
    if(n%2 != 0){
        x = mid+1;
    }
    for(int i=0;i<mid;i++){
        leftArr.push_back(v[i]);
    }
    for(int i=x;i<n;i++){
        rightArr.push_back(v[i]);
    }
    int i =0,j=0;
    int n1 = leftArr.size(), n2 = rightArr.size();
    while(i<n1 && j<n2){
        if(rightArr[j]-leftArr[i] >= k){
            i++;
            j++;
            ans++;
        }else{
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

