#include "template.h"

int length(Node* head){
    int length = 0;
    if(head == NULL){
        return 0;
    }
    while(head != NULL){
        head = head->next;
        length++;
    }
    return length;
}

Node* removeSlide(Node* head, int k){
    if(head == NULL){
        return head;
    }
    int n = length(head);
    int pos = n-k+1;
    Node* ptr = head;
    int count = 1;
    if(count == pos){
        head = ptr->next;
        return head;
    }
    while(ptr != NULL){
        if(count == pos-1){
            ptr->next = ptr->next->next;
            break;
        }
        ptr = ptr->next;
        count++;
    }
    return head;
}

int main(void){
    int k;
    scanf("%d",&k);
    Node* head = readList();
    head = removeSlide(head,k);
    printList(head);
    freeList(head);
    return 0;
}