#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n=0,k=0;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    make_heap(v.begin(),v.end());
    int sum = 0;
    for(int i=0;i<k;i++){
        int left = 0;
        pop_heap(v.begin(),v.end());
        int largest = v[v.size()-1];
        v.pop_back();
        if(largest%2 == 0){
            sum += largest/2;
            left = largest/2;
        }else{
            sum += largest/2 + 1;
            left = largest - (largest/2+1);
        }
        v.push_back(left);
        push_heap(v.begin(),v.end());
    }

    cout<<sum<<endl;

    return 0;
}
