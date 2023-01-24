#include<stdio.h>
#include<stdlib.h>

// doubly linked list
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

int main(void){

	int n = 0;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	int* arr = (int*)malloc(n*sizeof(int));
	if(arr == NULL){
		printf("Error : Memory Not Sufficient\n");
		exit(0);
	}

	printf("Enter the elements of array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	Node* head = create_node(arr[0]);
	Node* head_rev = create_node(arr[0]);

	// creating dll by inserting at the end
	for(int i=1;i<n;i++){
		insertAtEnd(head,arr[i]);
	}

	// creating dll by adding nodes at beg.
	for(int i=1;i<n;i++){
		insertAtBeg(&head_rev,arr[i]);
	}

	insertAtBeg(&head_rev,100);
	printLL(head_rev);
	Node* ptr = search(head_rev,100);
	if(ptr != NULL){
		printf("%d\n",ptr->val);
	}
	deleteFromEnd(head_rev);
	printLL(head_rev);

	// for deleting the linked list recursively
	Node* temp = head->next;
	free(head);
	printf("%d ",temp->val);

	return 0;
}