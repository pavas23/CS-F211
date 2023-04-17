#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n = 0;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int ans = 0;
    stack<int> stk;
    for(int right=0;right<=n;right++){
        while(!stk.empty() && (right == n || nums[stk.top()] >= nums[right])){
            int mid = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top();
            ans -= nums[mid]*(right-mid)*(mid-left);
        }
        stk.push(right);
    }

    stk.pop();
    for(int right = 0;right<=n;right++){
        while(!stk.empty() && (right == n || nums[stk.top()] <= nums[right])){
            int mid = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top();
            ans += nums[mid]*(right-mid)*(mid-left);
        }
        stk.push(right);
    }
    cout<<ans<<endl;
    return 0;
}
