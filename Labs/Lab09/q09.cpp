#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n = 0;
    cin>>n;
    int total_petrol = 0, total_cost = 0;
    vector<int> petrol(n);
    for(int i=0;i<n;i++){
        cin>>petrol[i];
        total_petrol += petrol[i];
    }
    vector<int> cost(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
        total_cost += cost[i];
    }
    if(total_cost > total_petrol){
        cout<<-1<<endl;
        return 0;
    }
    int minIndex = 0;
    int currPetrol = 0;
    for(int i=0;i<n;i++){
        currPetrol += petrol[i] - cost[i];
        if(currPetrol < 0){
            minIndex = i+1;
            currPetrol = 0;
        }
    }
    cout<<minIndex<<endl;
    return 0;
}
