#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n=0,m=0;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(v[i]);
    }
    int sum = 0;
    for(int i=0;i<m;i++){
        int temp = pq.top();
        int newPrice = temp/2;
        pq.pop();
        pq.push(newPrice);
    }
    for(int i=0;i<n;i++){
        sum += pq.top();
        pq.pop();
    }
    cout<<sum<<endl;
    return 0;
}
