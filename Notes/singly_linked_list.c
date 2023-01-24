#include<stdio.h>
#include<stdlib.h>

// In this the datatype is struct Node not Node
/*
struct Node{
	int val;
	struct Node* next;
}; // put semicolon after struct
*/

// nodeType is the struct name and Node is the new name of this custom datatype
typedef struct nodeType
{
    int val;
    struct node* next;
}Node;

void printLL(Node* head){
    if(head == NULL){
        printf("Empty Linked List\n");
        return;
    }
    while(head != NULL){
        if(head->next != NULL){
            printf("%d -> ",head->val);
        }else{
            printf("%d",head->val);
        }
        head = head->next;
    }
    printf("\n");
    return;
}

Node* search(Node* head, int x){
    if(head == NULL){
        return NULL;
    }
    while(head != NULL){
        if(x == head->val){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

int sizeOfLL(Node* head){
    int size = 0;
    while(head != NULL){
        size++;
        head = head->next;
    }
    return size;
}

void insertAtLast(Node* head,int x){
    Node* lastNode = (Node*)malloc(sizeof(Node));
    if(lastNode == NULL){
        printf("Error: Memory Not Sufficient\n");
        exit(0);
    }
    lastNode->val = x;
    lastNode->next = NULL;
    while(head->next != NULL){
        head = head->next;
    }
    head->next = lastNode;
    return;
}

void insertAtBeg(Node** head,int x){
    // we passed ref of head pointer as we wanted call by reference method.
    Node* firstNode = (Node*)malloc(sizeof(Node));
    if(firstNode == NULL){
        printf("Error: Memory Not Sufficient\n");
        exit(0);
    }
    firstNode->val = x;
    firstNode->next = *head;
    *head = firstNode;
    return;
}

void insertAtIndex(Node** head_ref,int index,int x){
    Node* head = *head_ref;
    if(index<0){
        printf("Can't insert element at negative Index\n");
        return;
    }
    if(head == NULL){
        if(index != 0){
            printf("Can't add element %d at index %d as linked list is empty",x,index);
            return;
        }else{
            insertAtBeg(head,x);
            return;
        }
    }
    Node* ptr = head;
    int size = sizeOfLL(head);
    if(index == 0){
        insertAtBeg(head_ref,x);
        return;
    }if(index == size-1){
        return insertAtLast(head,x);
    }
    if(index > size){
        printf("Not possible to add element at index %d as length of linked list is %d\n",index,size);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Error: Memory Not Sufficient\n");
        exit(0);
    }
    newNode->val = x;
    int count = 0;
    while(count < index-1){
        ptr = ptr->next;
        count++;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return;
}

Node* deleteLast(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* ptr = head;
    while(ptr->next != NULL){
        Node* temp = ptr->next;
        if(temp->next == NULL){
            break;
        }
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
}

void deleteAtStart(Node** head){
    while(*head == NULL){
        return;
    }
    Node* ptr = *head;
    Node* temp = ptr->next;
    ptr = temp;
    *head = ptr;
    return;
}

void deleteAtIndex(Node** head_ref,int index){
    Node* head = *head_ref;
    if(index<0){
        printf("Can't delete element at negative Index\n");
        return;
    }
    if(head == NULL){
        printf("Can't delete elements in empty linked list\n");
        return;
    }
    Node* ptr = head;
    int size = sizeOfLL(head);
    if(index == 0){
        deleteAtStart(head_ref);
        return;
    }if(index == size-1){
        Node* node = deleteLast(head);
        return;
    }
    if(index >= size){
        printf("Not possible to delete element at index %d as length of linked list is %d\n",index,size);
        return;
    }
    int count = 0;
    while(count < index-1){
        ptr = ptr->next;
        count++;
    }
    Node* temp = ptr->next;
    ptr->next = temp->next;
    return;
}

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
