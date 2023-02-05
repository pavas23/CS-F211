#include "template.h"

// left

Node* removeRepeatedNodes(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* ptr = head;
    Node* curr = ptr;
    while(ptr != NULL){
        while(ptr->next != NULL && ptr->data == ptr->next->data){
            ptr = ptr->next;
        }
        curr->next = ptr->next;
        ptr = ptr->next;
    }
    return head;
}

int main(void){
    Node* head = readList();
    head = removeRepeatedNodes(head);
    printList(head);
    freeList(head);
    return 0;
}