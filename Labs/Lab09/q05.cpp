#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printSparseMatrix(vector<pair<pair<int,int>,int> > mat){
    cout<<endl;
    cout<<mat.size()<<endl;
    for(int i=0;i<mat.size();i++){
        cout<<mat[i].first.first<<" "<<mat[i].first.second<<" "<<mat[i].second<<endl;
    }
    cout<<endl;
}

int main(void){
    int m=0,k=0,n=0;
    cin>>m>>k>>n;
    int p = 0;
    cin>>p;
    vector<pair<pair<int,int>,int> > mat1(p);
    for(int k=0;k<p;k++){
        int i=0,j=0,x=0;
        cin>>i>>j>>x;
        mat1[k].first.first = i;
        mat1[k].first.second = j;
        mat1[k].second = x;
    }
    int q = 0;
    cin>>q;
    vector<pair<pair<int,int>,int> > mat2(q);
    for(int k=0;k<q;k++){
        int s=0,t=0,x=0;
        cin>>s>>t>>x;
        mat2[k].first.first = s;
        mat2[k].first.second = t;
        mat2[k].second = x;
    }
    vector<pair<pair<int,int>,int> > mat2T(q);
    for(int k=0;k<q;k++){
        mat2T[k].first.first = mat2[k].first.second;
        mat2T[k].first.second = mat2[k].first.first;
        mat2T[k].second = mat2[k].second;
    }
    sort(mat2T.begin(),mat2T.end());
    vector<pair<pair<int,int>,int> > mult;
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            if(mat1[i].first.second == mat2T[j].first.second){
                mult.push_back(make_pair(make_pair(mat1[i].first.first,mat2T[j].first.first),mat1[i].second*mat2T[j].second));
            }
        }
    }
    sort(mult.begin(),mult.end());
    vector<pair<pair<int,int>,int> > finalAns;
    for(int i=0;i<mult.size()-1;i++){
        int sum = mult[i].second;
        while(i+1 < mult.size() && mult[i].first.first==mult[i+1].first.first && mult[i].first.second==mult[i+1].first.second){
            sum += mult[i+1].second;
            i++;
        }
        finalAns.push_back(make_pair(mult[i].first,sum));
        if(i == mult.size()-2){
            finalAns.push_back(make_pair(mult[i+1].first,mult[i+1].second));
        }
    }
    sort(finalAns.begin(),finalAns.end());
    printSparseMatrix(finalAns);
    return 0;
}
