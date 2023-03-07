#include<iostream>
#include<stack>
using namespace std;

int main(void){
    int n = 0;
    cin>>n;
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int> st;
    st.push(-1);
    int area = arr[0];
    int i = 0;
    int* left_smaller = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        left_smaller[i] = -1;
    }
    int* right_smaller = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        right_smaller[i] = n;
    }
    while(i < n){
        while(!st.empty() && st.top() != -1 && arr[st.top()] > arr[i]){
            right_smaller[st.top()] = i;
            st.pop();
        }
        if(i > 0 && arr[i] == arr[i-1]){
            left_smaller[i] = left_smaller[i-1];
        }else{
            left_smaller[i] = st.top();
        }
        st.push(i);
        i++;
    }
    for(int j=0;j<n;j++){
        area = max(area,arr[j]*(right_smaller[j]-left_smaller[j]-1));
    }
    cout<<area<<endl;
    return 0;
}
