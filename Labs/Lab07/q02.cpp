#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(){
            val = 0;
            left = NULL;
            right = NULL;
        }
        TreeNode(int x){
            val = x;
            left = NULL;
            right = NULL;
        }
        TreeNode(int x,TreeNode* left,TreeNode* right){
            val = x;
            this->left = left;
            this->right = right;
        }
};

TreeNode* constructBinaryTree(vector<int> inOrder,vector<int> preOrder,int n){
    if(n == 0){
        return NULL;
    }
    int rootVal = preOrder[0];
    TreeNode* root = new TreeNode(rootVal);
    int partitionIndexInOrder = 0;
    for(int i =0;i<n;i++){
        if(inOrder[i] == rootVal){
            partitionIndexInOrder = i;
            break;
        }
    }
    vector<int> leftTreeInOrder;
    vector<int> leftTreePreOrder;
    vector<int> rightTreeInOrder;
    vector<int> rightTreePreOrder;

    for(int i=0;i<partitionIndexInOrder;i++){
        leftTreeInOrder.push_back(inOrder[i]);
    }
    for(int i=partitionIndexInOrder+1;i<n;i++){
        rightTreeInOrder.push_back(inOrder[i]);
    }

    int partitionIndexPreOrder = leftTreeInOrder.size();

    for(int i=1;i<=partitionIndexPreOrder;i++){
        leftTreePreOrder.push_back(preOrder[i]);
    }
    for(int i=partitionIndexPreOrder+1;i<n;i++){
        rightTreePreOrder.push_back(preOrder[i]);
    }

    root->left = constructBinaryTree(leftTreeInOrder,leftTreePreOrder,leftTreeInOrder.size());
    root->right = constructBinaryTree(rightTreeInOrder,rightTreePreOrder,rightTreeInOrder.size());

    return root;
}

int heightOfBinaryTree(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right));
}

vector<int> convertTreetoArr(TreeNode* root){
    int h = heightOfBinaryTree(root);
    int size = pow(2,h)-1;
    vector<int> arr;
    if(root == NULL){
        return arr;
    }
    queue<TreeNode*> q;
    q.push(root);
    arr.push_back(root->val);
    while(!q.empty() && arr.size() < size){
        TreeNode* temp = q.front();
        if(temp != NULL){
            TreeNode* leftChild = temp->left;
            TreeNode* rightChild = temp->right;
            if(leftChild != NULL){
                q.push(leftChild);
                arr.push_back(leftChild->val);
            }else{
                q.push(leftChild);
                arr.push_back(-1);
            }
            if(rightChild != NULL){
                q.push(rightChild);
                arr.push_back(rightChild->val);
            }else{
                q.push(rightChild);
                arr.push_back(-1);
            }
        }else{
            q.push(NULL);
            q.push(NULL);
            arr.push_back(-1);
            arr.push_back(-1);
        }
        q.pop();
    }
    return arr;
}

int main(void){
    int n = 0;
    cin>>n;
    vector<int> preOrder(n);
    vector<int> inOrder(n);
    for(int i=0;i<n;i++){
        cin>>preOrder[i];
    }
    for(int i=0;i<n;i++){
        cin>>inOrder[i];
    }
    TreeNode* root = constructBinaryTree(inOrder,preOrder,n);
    vector<int> ans = convertTreetoArr(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
