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

TreeNode* constructBinaryTree(int* arr,int i,int n){
    if(i >= n){
        return NULL;
    }
    TreeNode* root = new TreeNode(arr[i]);
    TreeNode* leftChild = constructBinaryTree(arr,2*i+1,n);
    TreeNode* rightChild = constructBinaryTree(arr,2*i+2,n);
    if(leftChild != NULL && leftChild->val != -1){
        root->left = leftChild;
    }
    if(rightChild != NULL && rightChild->val != -1){
        root->right = rightChild;
    }
    return root;
}

TreeNode* constructGSTHelper(TreeNode* root,int* sum){
    if(root == NULL){
        return root;
    }
    root->right = constructGSTHelper(root->right,sum);
    *sum += root->val;
    root->val = *sum;
    root->left = constructGSTHelper(root->left,sum);
    return root;
}

TreeNode* constructGST(TreeNode* root){
    int x = 0;
    int* sum = &x;
    return constructGSTHelper(root,sum);
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
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    TreeNode* rootOfBST = constructBinaryTree(arr,0,n);
    TreeNode* rootOfGST = constructGST(rootOfBST);
    vector<int> ans = convertTreetoArr(rootOfGST);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}