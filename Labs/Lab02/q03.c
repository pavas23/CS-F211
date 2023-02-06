#include "template.h"

// sorting a singly linked list

Node* mergeLists(Node* first,Node* second){

    Node* curr1 = first;
    Node* curr2 = second;
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

void MakingTwoLists(Node* head, Node** first, Node** second){

    Node* fast;
    Node* slow;
    slow = head;
    fast = head->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' is before the midpoint in the list, so split it in two at that point.
    *first = head;
    *second = slow->next;
    slow->next = NULL;
}

void mergeSort(Node** headRef){
    Node* head = *headRef;
    Node* first;
    Node* second;
    if(head == NULL || head->next == NULL){
        return;
    }
    MakingTwoLists(head,&first,&second);
    mergeSort(&first);
    mergeSort(&second);
    *headRef =  mergeLists(first,second);
}

Node* sortList(Node* head){
    // this will change the head pointer, and it will point to sorted linked list
    mergeSort(&head);
    return head;
}

int main(void){
    Node* head = readList();
    Node* sorted = sortList(head);
    printList(sorted);
    freeList(head);
    return 0;
}

