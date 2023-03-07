#include<iostream>
#include<stack>
using namespace std;

int main(void){
    int n = 0;
    cin>>n;
    int* arr = (int*)malloc(n*sizeof(int));
    int maxEle = -1;
    int maxIndex = -1;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(arr[i] > maxEle){
            maxEle = arr[i];
            maxIndex = i;
        }
    }
    stack<int> st1;
    stack<int> st2;
    st2.push(maxIndex);
    for(int i=maxIndex+1;i<n;i++){
        st1.push(i);
    }
    for(int i=0;i<maxIndex;i++){
        st1.push(i);
    }
    int output[n];
    output[maxIndex] = -1;
    while(!st1.empty()){
        while(!st2.empty() && ((arr[st1.top()] >= arr[st2.top()]))){
            st2.pop();
        }
        if(st2.empty()){
            output[st1.top()] = -1;
        }
        else{
            int minVisits = (st2.top()-st1.top());
            if(minVisits < 0){
                minVisits += n;
            }
            output[st1.top()] = minVisits;
        }
        st2.push(st1.top());
        st1.pop();
    }
    for(int i=0;i<n;i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
}