#include<iostream>
#include<bits/stdc++.h>
using namespace std;

double medianOfTwoSortedArrays(vector<int> a,vector<int> b){
    int n = a.size();
    int m = b.size();
    if(n > m){
        return medianOfTwoSortedArrays(b,a);
    }
    int start = 0;
    int end = n;
    int realmidinmergedarray = (n+m+1)/2;

    while(start <= end){
        int mid = (start+end)/2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA = (leftAsize > 0) ? a[leftAsize-1] : INT_MIN;
        int leftB = (leftBsize > 0) ? b[leftBsize-1] : INT_MIN;
        int rightA = (leftAsize < n) ? a[leftAsize] : INT_MAX;
        int rightB = (leftBsize < m) ? b[leftBsize] : INT_MAX;

        if(leftA <= rightB && leftB <= rightA){
            if((n+m)%2 == 0){
                return (max(leftA,leftB)+min(rightA,rightB))/2.0;
            }else{
                return max(leftA,leftB);
            }
        }else if(leftA > rightB){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return 0.0;
}

int main(void){
    int n=0,m=0;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    vector<int> b(m,0);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    double ans = medianOfTwoSortedArrays(a,b);
    cout<<ans<<endl;
    return 0;
}
