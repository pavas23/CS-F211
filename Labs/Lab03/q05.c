#include "template.h"

void rotateList(Node** headRef,Node** tailRef){
    Node* head = *headRef;
    Node* tail = *tailRef;
    if(head == NULL){
        return;
    }
    Node* end = tail;
    Node* secondLast = end->prev;
    end->next = head;
    head->prev = end;
    end->prev = NULL;
    secondLast->next = NULL;
    *headRef = end;
    *tailRef = secondLast;
    return;
}

int main(void){
    int n,k=0;
    scanf("%d",&n);
    scanf("%d",&k);
    Node* head = NULL;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        addToList(&head,x);
    }
    Node* tail = NULL;
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    tail = ptr;
    for(int i=0;i<k;i++){
        rotateList(&head,&tail);
    }
    printList(head);
    printf("\n");
    return 0;
}

