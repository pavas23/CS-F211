#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n = 0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    priority_queue<int,vector<int>,greater<int> > pq;
    int count=0,sum=0;
    vector<int> v1;
    vector<int>:: iterator it;

    for(int i=0;i<n;i++){
        sum += v[i];
        v1.push_back(v[i]);
        count++;

        if(v[i] < 0){
            pq.push(v[i]);
        }

        if(sum < 0){
            sum -= pq.top();
            it = find(v1.begin(),v1.end(),pq.top());
            v1.erase(it);
            pq.pop();
            count--;
        }
    }
    cout<<count<<endl;
    return 0;
}
