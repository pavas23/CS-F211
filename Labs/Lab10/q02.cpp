#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool searchIn2DMatrix(vector<vector<int> > mat,int v){
    int row = mat.size();
    int col = mat[0].size();
    int smallest = mat[0][0], largest = mat[row-1][col-1];

    if(v < smallest || v > largest){
        return false;
    }

    int i=0,j=col-1;
    while(i <row && j>=0){
        if(mat[i][j] == v){
            return true;
        }
        if(mat[i][j] > v){
            j--;
        }else{
            i++;
        }
    }
    return false;
}

int main(void){
    int n=0,m=0;
    cin>>m>>n;
    vector<vector<int> > mat(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int v = 0;
    cin>>v;
    bool ans = searchIn2DMatrix(mat,v);
    if(ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
