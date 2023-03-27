#include<iostream>
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

TreeNode* constructBinaryTree(long long* arr,long long i,long long n){
    if(i>=n){
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

void printBinaryTreeInorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    printBinaryTreeInorder(root->left);
    cout<<root->val<<" ";
    printBinaryTreeInorder(root->right);
    return;
}

long long findNumOfFreedomNodes(TreeNode* root,long long x){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->val == x){
            return 1;
        }else{
            return 0;
        }
    }
    long long leftAns = findNumOfFreedomNodes(root->left,x-root->val);
    long long rightAns = findNumOfFreedomNodes(root->right,x-root->val);
    return leftAns+rightAns;
}

int main(void){
    long long n=0,x=0;
    cin>>n>>x;
    long long* arr = (long long*)malloc(n*sizeof(long long));
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    TreeNode* root = constructBinaryTree(arr,0,n);
    long long ans = findNumOfFreedomNodes(root,x);
    cout<<ans<<endl;
    return 0;
}