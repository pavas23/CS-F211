#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int x){
            this->data = x;
            this->left = NULL;
            this->right = NULL;
        }
};

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        cout<<temp->data<<" ";
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
        q.pop();
    }
    cout<<endl;
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}

Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        return new Node(data);
    }
    if(data < root->data){
        root->left = insertIntoBST(root->left,data);
    }else{
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}

void createBST(Node** rootRef){
    Node* root = *rootRef;
    int data;
    cin>>data;
    while(data != -1){
        *rootRef = insertIntoBST(root,data);
        root = *rootRef;
        cin>>data;
    }
    return;
}

int main(void){
    Node* root = NULL;
    cout<<"Enter nodes to create BST"<<endl;
    createBST(&root);
    cout<<"Printing the BST (Level Order Traversal)\n";
    levelOrderTraversal(root);
    return 0;
}
