#include<iostream>
#include<stack>
using namespace std;

int main(void){
    stack<int> price;
    stack<int> days;
    int n = 0;
    cin>>n;
    int x=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(!price.empty()){
            if(price.top() <= x){
                while(!price.empty() && price.top() <= x){
                    price.pop();
                    days.pop();
                }
                if(!days.empty()){
                    cout<<i-days.top()<<" ";
                }else{
                    cout<<i+1<<" ";
                }
            }else{
                cout<<1<<" ";
            }
        }else{
            cout<<1<<" ";
        }
        price.push(x);
        days.push(i);
    }
    cout<<endl;
    return 0;
}