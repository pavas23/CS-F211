#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void KMaxCombinations(vector<int>& a,vector<int>& b,int k){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int n = a.size();
    
    priority_queue<pair<int,pair<int,int> > >pq;
    set<pair<int,int> > set;
    pq.push(make_pair(a[n-1]+b[n-1],make_pair(n-1,n-1)));
    set.insert(make_pair(n-1,n-1));

    for(int count = 0;count < k;count++){
        pair<int,pair<int,int> > temp = pq.top();
        pq.pop();

        cout<<temp.first<<" ";

        int i = temp.second.first;
        int j = temp.second.second;

        int sum = a[i-1] + b[j];

        pair<int,int> temp1 = make_pair(i-1,j);

        if(set.find(temp1) == set.end()){
            pq.push(make_pair(sum,temp1));
            set.insert(temp1);
        }

        sum = a[i] + b[j-1];
        temp1 = make_pair(i,j-1);

        if(set.find(temp1) == set.end()){
            pq.push(make_pair(sum,temp1));
            set.insert(temp1);
        }
    }
    return;
}

int main(void){
    int n=0,k=0;
    cin>>n>>k;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    KMaxCombinations(a,b,k);
    cout<<endl;
    return 0;
}
