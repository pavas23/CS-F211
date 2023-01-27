#include "functions.h"

int main(void){
    Node* head = (Node*)malloc(sizeof(Node));
    Node* fn = (Node*)malloc(sizeof(Node));
    Node* sn = (Node*)malloc(sizeof(Node));
    Node* tn = (Node*)malloc(sizeof(Node));
    head->val = 1;
    head->next = fn;
    fn->val = 2;
    fn->next = sn;
    sn->val = 3;
    sn->next = tn;
    tn->val = 4;
    tn->next = NULL;
    printLL(head);
    insertAtLast(head,10);
    printLL(head);
    insertAtBeg(&head,-1);
    printLL(head);
    printf("%d\n",sizeOfLL(head));
    insertAtIndex(&head,0,100);
    printLL(head);
    deleteLast(head);
    printLL(head);
    deleteAtStart(&head);
    printLL(head);
    deleteAtIndex(&head,0);
    printLL(head);
    return 0;
}