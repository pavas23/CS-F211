#include "global.h"

typedef struct Node
{
	int val;
	struct Node* prev;
	struct Node* next;
}Node;

Node* create_node(int x){
	Node* ptr = (Node*)malloc(sizeof(Node));
	if(ptr == NULL){
		printf("Error in allocating Memory\n");
		exit(0);
	}
	ptr->val = x;
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}

void printLL(Node* head){
	if(head == NULL){
		printf("Empty Linked List\n");
		return;
	}
	while(head != NULL){
		if(head->next == NULL){
			printf("%d",head->val);
		}else{
			printf("%d <-> ",head->val);
		}
		head = head->next;
	}
	printf("\n");
}

Node* search(Node* head,int x){
	while(head != NULL){
		if(x == head->val){
			return head;
		}
		head = head->next;
	}
	return NULL;
}

void insertAtBeg(Node** head,int x){
	Node* newNode = create_node(x);
	if(head == NULL){
		*head = newNode;
		newNode->prev = NULL;
		return;
	}
	newNode->next = *head;
	(*head)->prev = newNode;
	*head = newNode;
	newNode->prev = NULL;
}

void insertAtEnd(Node* head,int x){
	Node* newNode = create_node(x);
	while(head->next != NULL){
		head = head->next;
	}
	head->next = newNode;
	newNode->prev = head;
	newNode->next = NULL;
	return;
}

void deleteFromEnd(Node* head){
	if(head == NULL){
		return;
	}
	Node* ptr = head;
	while(ptr->next->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = NULL;
	return;
}
