#include "template.h"

// finding median of singly linked list

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

int findMedian(Node* head){
    int n = length(head);
    if(n == 0){
        printf("Empty Linked List, Hence no median found!\n");
        exit(0);
    }
    int index = 1;
    Node* curr = head;
    int a=0,b=0;
    while(curr != NULL){
        if(index == n/2){
            a = curr->data;
        }
        if(index == n/2+1){
            b = curr->data;
            break;
        }
        index++;
        curr = curr->next;
    }
    if(n%2 != 0){
        return b;
    }else{
        return (a+b)/2;
    }
}

int main(void){
    Node* head = readList();
    int median = findMedian(head);
    printf("%d\n",median);
    freeList(head);
    return 0;
}