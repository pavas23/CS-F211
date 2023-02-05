#include "template.h"

// merging two sorted singly linked list

Node* mergeLists(Node* head1, Node* head2){
    Node *curr1 = head1, *curr2 = head2;
    Node* merged;

    if(curr1->data <= curr2->data){
        merged = createNode(curr1->data);
        curr1 = curr1->next;
    }else{
        merged = createNode(curr2->data);
        curr2 = curr2->next;
    }

    Node* curr_new = merged;

    while(curr1 != NULL && curr2 != NULL){
        if(curr1->data <= curr2->data){
            curr_new->next = createNode(curr1->data);
            curr_new = curr_new->next;
            curr1 = curr1->next;
        }else{
            curr_new->next = createNode(curr2->data);
            curr_new = curr_new->next;
            curr2 = curr2->next;
        }
    }

    while(curr1 != NULL){
        curr_new->next = createNode(curr1->data);
        curr_new = curr_new->next;
        curr1 = curr1->next;
    }
    while(curr2 != NULL){
        curr_new->next = createNode(curr2->data);
        curr_new = curr_new->next;
        curr2 = curr2->next;
    }

    curr_new->next = NULL;

    return merged;
}

int main(void){
    Node* head1 = readList();
    Node* head2 = readList();
    Node* merged = mergeLists(head1,head2);
    printList(merged);
    freeList(head1);
    freeList(head2);
    freeList(merged);
    return 0;
}