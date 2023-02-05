#include "template.h"

// left

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

Node* mergeLists(Node* head,int start,int mid,int end){
    int index = 0;
    Node* ptr = head;
    Node *curr1,*curr2;
    printf("%d\n",mid);
    while(ptr != NULL){
        if(index == mid){
            curr1 = head;
            curr2 = ptr->next;
            ptr->next = NULL;
            break;
        }
        index++;
        ptr = ptr->next;
    }
    printList(curr1);
    printList(curr2);
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
    printf("%d\n",merged->data);
    return merged;
}

// Node* giveMid(Node* head){
//     if(head == NULL){
//         return NULL;
//     }
//     int index = 0;
//     int size = length(head);
//     while(head != NULL){
//         if(index == size/2){
//             printf("%d\t",head->data);
//             return head;
//         }
//         head = head->next;
//         index++;
//     }
//     return NULL;
// }

void mergeSort(Node** head,int start,int end){
    if(*head == NULL){
        return;
    }
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(head,0,mid);
    mergeSort(head,mid+1,end);
    *head = mergeLists(head,start,mid,end);
}

Node* sortList(Node* head){
    int n = length(head);
    mergeSort(&head,0,n-1);
    return head;
}

int main(void){
    Node* head = readList();
    Node* sorted = sortList(head);
    printList(sorted);
    freeList(head);
    freeList(sorted);
    return 0;
}

