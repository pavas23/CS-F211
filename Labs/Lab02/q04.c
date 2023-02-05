#include "template.h"

// reversing a singly linked list

Node* reverseList(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    Node* ptr = head;
    Node* slow = ptr->next;
    Node* fast = ptr->next->next;
    // for making next of first node as NULL
    ptr->next = NULL;
    while(slow != NULL){
        slow->next = ptr;
        ptr = slow;
        slow = fast;
        if(fast != NULL){
            fast = fast->next;
        }
    }
    // at last slow and fast will point to NULL and ptr will point to last node which is the new head
    return ptr;
}

int main(void){
    Node* head = readList();
    head = reverseList(head);
    printList(head);
    freeList(head);
    return 0;
}
