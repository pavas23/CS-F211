#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(){
            data = 0;
            prev = NULL;
            next = NULL;
        }
        Node(int x){
            data = x;
            prev = NULL;
            next = NULL;
        }
};

class MinStack{
    public:
        Node* head;
        Node* topPtr;
        int currMin;

        MinStack(){
            head = NULL;
            topPtr = NULL;
        }

        void push(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                topPtr = head;
            }else{
                topPtr->next = newNode;
                newNode->prev = topPtr;
                topPtr = topPtr->next;
            }
        }

        void pop(){
            Node* temp = topPtr->prev;
            free(topPtr);
            temp->next = NULL;
            topPtr = temp;
            return;
        }

        int top(){
            return topPtr->data;
        }

        void updateMin(int min){
            currMin = min;
        }

        int getMin(){
            return currMin;
        }

};

int main(void){
    int n = 0;
    cin>>n;
    MinStack stack;
    MinStack minStack;
    int min = __INT_MAX__;

    int element = 0;
    for(int i=0;i<n;i++){
        cin>>element;
        if(element < min){
            min = element;
            minStack.push(min);
            stack.updateMin(min);
        }
        stack.push(element);
    }
    int m = 0;
    cin>>m;

    for(int i=0;i<m;i++){
        int operation = 0;
        cin>>operation;
        if(operation == 1){
            int x = 0;
            cin>>x;
            if(x < min){
                min = x;
                minStack.push(min);
                stack.updateMin(min);
            }
            stack.push(x);
        }else if(operation == 2){
            if(stack.top() == min){
                minStack.pop();
                min = minStack.top();
                stack.updateMin(min);
            }
            stack.pop();
        }else if(operation == 3){
            cout<<stack.top()<<endl;
        }else if(operation == 4){
            cout<<stack.getMin()<<endl;
        }
    }
    return 0;
}