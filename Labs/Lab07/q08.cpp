#include<iostream>
#include<vector>
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

TreeNode* constructBeautifulBST(TreeNode* root,int l,int r){
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->val >= l && root->val <= r){
            return root;
        }else{
            return NULL;
        }
    }
    if(root->val >= l && root->val <= r){
        TreeNode* leftChild = constructBeautifulBST(root->left,l,r);
        TreeNode* rightChild = constructBeautifulBST(root->right,l,r);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    } 
    else{
        if(root->left == NULL){
            return constructBeautifulBST(root->right,l,r);
        }
        else if(root->right == NULL){
            return constructBeautifulBST(root->left,l,r);
        }else{
            if(root->val < l){
                return constructBeautifulBST(root->right,l,r);
            }else{
                return constructBeautifulBST(root->left,l,r);
            }
        }
    }
}

void printBinaryTreePostorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    printBinaryTreePostorder(root->left);
    printBinaryTreePostorder(root->right);
    cout<<root->val<<" ";
    return;
}

int main(void){
    int n=0,l=0,r=0;
    cin>>n>>l>>r;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    TreeNode* root = constructBinaryTree(v,0,n);
    TreeNode* newRoot = constructBeautifulBST(root,l,r);
    printBinaryTreePostorder(newRoot);
    cout<<endl;
    return 0;
}