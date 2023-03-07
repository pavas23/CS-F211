#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

int main(void){
    int n=0,k=0;
    scanf("%d",&n);
    scanf("%d",&k);
    Node* front = (Node*)malloc(sizeof(Node));
    front->data = 1;
    front->next = NULL;
    front->prev = NULL;
    Node* ptr = front;
    for(int i=2;i<=n;i++){
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data =i;
        newnode->next = NULL;
        newnode->prev = ptr;
        ptr->next = newnode;
        ptr = newnode;
        if(i == n){
            newnode->next = front;
            front->prev = newnode;
            break;
        }
    }
    Node* rear = front;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<k-1;j++){
            rear = rear->next;
        }
        Node* prevNode = rear->prev;
        Node* nextNode = rear->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        rear = nextNode;
    }
    printf("%d\n",rear->data);
    return 0;
}