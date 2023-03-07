#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int main(void){
    string str;
    cin>>str;
    string s;
    s.append("/");
    s.append(str);
    stack<string> st;
    for(int i=0;i<s.length();i++){
        if(s[i] == '/'){
            int flag = 0;
            string temp = "";
            i++;
            while(i<s.length() && s[i] != '/'){
                flag = 1;
                temp += s[i];
                i++;
            }
            if(flag){
                st.push(temp);
            }
            i--;
        }
        if(!st.empty() && st.top() == "."){
            st.pop();
        }else if(!st.empty() && st.top() == ".."){
            st.pop();
            st.pop();
        }
    }

    stack<string> dirStack;

    while(!st.empty()){
        dirStack.push(st.top());
        st.pop();
    }

    if(dirStack.empty()){
        cout<<"/";
    }
    while(!dirStack.empty()){
        cout<<"/"<<dirStack.top();
        dirStack.pop();
    }
    
    cout<<endl;
    return 0;
}
