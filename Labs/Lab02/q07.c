#include "template.h"

// removing all duplicate nodes in singly linked list

Node* removeRepeatedNodes(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* ptr = head;
    Node* curr = ptr;
    while(ptr != NULL){
        // if head node is duplicate one
        int flag = 0;
        while(head->next != NULL && head->data == head->next->data){
            flag = 1;
            head = head->next;
        }
        if(flag){
            head = head->next;
        }
        // checking duplicate nodes
        while(ptr->next != NULL && ptr->data == ptr->next->data){
            ptr = ptr->next;
        }
        ptr = ptr->next;
        if(ptr == NULL){
            curr->next = NULL;
            break;
        }
        // Now ptr will point to nodes after all duplicates
        if(ptr->next != NULL && ptr->data == ptr->next->data){
            continue;
        }
        else{
            curr->next = ptr;
            curr = curr->next;
            if(ptr == NULL && curr != NULL){
                curr->next = ptr;
            }
        }
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