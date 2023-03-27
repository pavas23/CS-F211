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

int findKLargestElement(TreeNode* root, int k,int* count){
    if(root == NULL){
        return -1;
    }
    int ans = findKLargestElement(root->right,k,count);
    if(ans != -1){
        return ans;
    }
    *count += 1;
    if(*count == k){
        return root->val;
    }
    return findKLargestElement(root->left,k,count);
}

int main(void){
    int n=0,k=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>k;
    int zero = 0;
    int* count = &zero;
    TreeNode* root = constructBinaryTree(v,0,n);
    int ans = findKLargestElement(root,k,count);
    cout<<ans<<endl;
    return 0;
}