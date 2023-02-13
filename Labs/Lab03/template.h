#include "global.h"

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addToList(Node** headRef,int x){
    Node* newNode = createNode(x);
    Node* head = *headRef;
    if(head == NULL){
        *headRef = newNode;
        return;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
    return;
}

Node* readList(){
    int n;
    scanf("%d",&n);
    Node* head = NULL;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        addToList(&head,x);
    }
    return head;
}

void printList(Node* head){
    if(head == NULL){
        return;
    }
    while(head != NULL){
        printf("%d ",head->data);
        head = head->next;
    }
    return;
}

int length(Node* head){
    int size = 0;
    if(head == NULL){
        return size;
    }
    while(head != NULL){
        size++;
        head = head->next;
    }
    return size;
}

