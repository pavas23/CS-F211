#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char val;
	struct node* next;
};

struct node* create_node(int a){
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("Error in allocating Memory\n");
		exit(0);
	}
	ptr->val = a;
	ptr->next = NULL;
	return ptr;
}

void insert_node(struct node**ptr,struct node** first){
	(*ptr)->next = *first;
	*first = *ptr;
}

void print(struct node* head){
	while(head != NULL){
		if(head->next == NULL){
			printf("%c",head->val);
		}else{
			printf("%c -> ",head->val);
		}
		head = head->next;
	}
	printf("\n");
}

int main(void){
	char s[10] = "abcdef";
	struct node* temp;
	struct node* head = create_node(s[0]);
	for(int i=1;i<strlen(s);i++){
		temp = create_node(s[i]);
		insert_node(&temp,&head);
	}
	temp = head;
	print(head);
}

