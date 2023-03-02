#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&v, int start, int mid, int end){
    vector<int>a,b;
    for(int i=0;i<=mid;i++) a.push_back(v[i]);
    for(int i=mid+1;i<=end;i++) b.push_back(v[i]);
    int i=0,j=0;
    int curr = 0;
    int n = a.size();
    int m = b.size();
    while(i<n && j<m){
        if(a[i] < b[j]){
            v[curr] = a[i];
            curr++;
            i++;
        }else{
            v[curr] = b[j];
            curr++;
            j++;
        }
    }
    while(i<n){
        v[curr] = a[i];
        curr++;
        i++;
    }
    while(j<m){
        v[curr] = b[j];
        curr++;
        j++;
    }
    return;
}

void mergeSort(vector<int>&vec, int start, int end){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(vec,start,mid);
    mergeSort(vec,mid+1,end);
    merge(vec,start,mid,end);
    return;
}

void printVec(vector<int>& v){
    for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    cout<<endl;
}

int main(void){
    int n = 0;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    mergeSort(v,0,n-1);
    printVec(v);
    return 0;
}

