#include "global.h"

struct Node_t{
    int data;
    struct Node_t *next;
};

typedef struct Node_t Node;

// creates a new node with the given value and returns a pointer to it
Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    // assert function from assert.h is used to check if the assumption made by us is correct or not, if not correct program terminates
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// creates a new node with given value and adds it to the back of given singly linked list, returns a pointer to newly created node
Node* addToList(Node* head, int value){
    Node* newNode = createNode(value);
    if(head == NULL){
        return newNode;
    }
    Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    return newNode;
}

// creates a singly linked list by reading input and returns a pointer to the head of the newly created linked list
Node* readList(){
    int n = 0;
    scanf("%d",&n);

    Node* head = NULL;

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);

        if(head == NULL){
            head = addToList(head,x);
        }else{
            Node* temp = addToList(head,x);
        }
    }
    return head;
}

// Prints the values stored in the nodes of the given singly linked list
void printList(Node* head){
    Node* ptr = head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

// Frees the memory dynamically allocated to all the nodes of the given singly linked list
void freeList(Node* head){
    Node *curr, *next;
    curr = head;
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
}

