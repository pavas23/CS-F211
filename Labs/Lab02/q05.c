#include "template.h"

// checking if a given singly linked list is palindrome or not

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

// this will recursively call the function on inner list
int checkPalindrome(Node* head,int start,int end){
    if(start >= end){
        return 1;
    }
    Node* ptr1 = head;
    Node* ptr2 = head;
    int count1 = 0;
    int count2 = 0;
    while(ptr1->next != NULL){
        if(count1 == start){
            break;
        }
        count1++;
        ptr1 = ptr1->next;
    }
    while(ptr2->next != NULL){
        if(count2 == end){
            break;
        }
        count2++;
        ptr2 = ptr2->next;
    }
    if(ptr1->data == ptr2->data){
        return checkPalindrome(head,start+1,end-1);
    }else{
        return 0;
    }
}

int isPalindrome(Node* head){
    int n = length(head);
    return checkPalindrome(head,0,n-1);
}

int main(void){
    Node* head = readList();
    int palin = isPalindrome(head);
    printf("%d\n",palin);
    freeList(head);
    return 0;
}