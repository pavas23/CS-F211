#include "template.h"

int main(void){
    long int k;
    scanf("%ld",&k);
    Node* head = readList();
    int ans = 0;
    int n = length(head);
    Node* start = head;
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    Node* end = ptr;
    while(start != end){
        if(start->data + end->data == k){
            ans = 1;
            break;
        }
        else if(start->data + end->data > k){
            end = end->prev;
        }
        else{
            start = start->next;
        }
    }
    printf("%d\n",ans);
    return 0;
}