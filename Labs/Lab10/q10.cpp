#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int> > pip;

int kthSmallest(vector<vector<int> > mat,int k){
    priority_queue<pip,vector<pip>,greater<pip> > pq;
    int n = mat.size();
    for(int i=0;i<n;i++){
        pq.push(make_pair(mat[0][i],make_pair(0,i)));
    }
    pair<int,pair<int,int> > node;
    for(int i=0;i<k;i++){
        node = pq.top();
        pq.pop();
        int nextVal = (node.second.first < n-1) ? mat[node.second.first+1][node.second.second] : INT_MAX;
        pq.push(make_pair(nextVal,make_pair(node.second.first+1,node.second.second)));
    }
    return node.first;
}

int main(void){
    int n=0,k=0;
    cin>>n>>k;
    vector<vector<int> > mat(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int ans = kthSmallest(mat,k);
    cout<<ans<<endl;
    return 0;
}
