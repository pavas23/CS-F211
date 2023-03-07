#include<iostream>
#include<stack>
using namespace std;

int main(void){
    string s;
    stack<char> stack;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            stack.push('(');
        }
        else if(s[i] == ')'){
            if(stack.size() != 0 && stack.top() == '('){
                stack.pop();
            }else{
                stack.push(')');
            }
        }
    }
    int ans = stack.size();
    cout<<ans<<endl;
    return 0;
}
