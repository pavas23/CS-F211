#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = 0;
    int j = 0;
    int sum = 0;

    for (int i = 0; i < n; i++){
        while (j < n && (sum + arr[j]) <= k){
            sum += arr[j];
            j++;
        }
        ans += (j - i);
        sum -= arr[i];
    }
    cout<<ans<<endl;
    return 0;
}
