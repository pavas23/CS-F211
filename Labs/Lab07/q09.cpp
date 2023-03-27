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

TreeNode* constructBinaryTree(vector<int> v,int i,int n){
    if(i >= n){
        return NULL;
    }
    TreeNode* root = new TreeNode(v[i]);
    TreeNode* leftChild = constructBinaryTree(v,2*i+1,n);
    TreeNode* rightChild = constructBinaryTree(v,2*i+2,n);
    if(leftChild != NULL && leftChild->val != -1){
        root->left = leftChild;
    }
    if(rightChild != NULL && rightChild->val != -1){
        root->right = rightChild;
    }
    return root;
}

bool findPath(TreeNode* root,vector<int>& path,int x){
    if(root == NULL){
        return false;
    }
    path.push_back(root->val);
    if(root->val == x){
        return true;
    }
    if(root->left != NULL && findPath(root->left,path,x)){
        return true;
    }
    if(root->right != NULL && findPath(root->right,path,x)){
        return true;
    }
    path.pop_back();
    return false;
}

int findCommonAncestor(TreeNode* root,int x,int y){
    vector<int> path1,path2;

    if(!findPath(root,path1,x) || !findPath(root,path2,y)){
        return -1;
    }

    int i = 0;
    int size = min(path1.size(),path2.size());
    for(i = 0;i<size;i++){
        if(path1[i] != path2[i]){
            break;
        }
    }
    return path1[i-1];
}

int main(void){
    int n=0,x=0,y=0;
    cin>>n>>x>>y;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    TreeNode* root = constructBinaryTree(v,0,n);
    int ans = findCommonAncestor(root,x,y);
    cout<<ans<<endl;
    return 0;
}