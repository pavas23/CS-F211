#include "template.h"

// placing all ece papers before cs ones

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

Node* rearrangeList(Node* head){
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        return head;
    }
    if(head->next->next == NULL){
        return head;
    }
    int n = length(head);
    Node* slow = head->next;
    Node* fast = head->next->next;
    head->next = fast;
    // temp_head will point to first element of cs list
    Node* temp_head = slow;
    while(slow != NULL){
        if(fast != NULL){
            slow->next = fast->next;
            slow = fast->next;
        }
        if(slow != NULL){
            if(fast == NULL){
                break;
            }
            fast->next = slow->next;
            fast = slow->next;
        }
    }
    if(n%2 != 0){
        // if n is odd then, fast is pointing to last ele of ece list, connecting ece list with cs list
        fast->next = temp_head;
    }else{
        // if n is even then fast is pointing towards NULL
        // making next of last element of cs list NULL
        slow->next = NULL;
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        // connecting last element of ece list to head of cs list
        temp->next = temp_head;
    }
    return head;
}

int main(void){
    Node* head = readList();
    head = rearrangeList(head);
    printList(head);
    freeList(head);
    return 0;
}

