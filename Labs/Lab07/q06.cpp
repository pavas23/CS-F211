#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > pii;

vector<int> mergeKSortedArrays(vector<vector<int> > vec, int k){
    vector<int> output;
    priority_queue<pii,vector<pii>,greater<pii> > minHeap;
    for(int i=0;i<vec.size();i++){
        pii val = make_pair(vec[i][0], make_pair(i,0));
        minHeap.push(val);
    }
    while(!minHeap.empty()){
        pii topElement = minHeap.top();
        minHeap.pop();
        output.push_back(topElement.first);
        int rowNum = topElement.second.first;
        int colNum = topElement.second.second;
        if(colNum + 1 < vec[rowNum].size()){
            minHeap.push(make_pair(vec[rowNum][colNum+1],make_pair(rowNum,colNum+1)));
        }
    }
    return output;
}

int main(void){
    int k = 0;
    cin>>k;
    vector<vector<int> > vec;
    for(int i=0;i<k;i++){
        int size = 0;
        cin>>size;
        vector<int> row(size);
        for(int i=0;i<size;i++){
            cin>>row[i];
        }
        vec.push_back(row);
    }
    vector<int> ans = mergeKSortedArrays(vec,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}