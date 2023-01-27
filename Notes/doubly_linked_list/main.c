#include "functions.h"

int main(void){

    // Driver Code
	int n = 0;
	printf("\nEnter the number of elements in doubly linked list\n");
	scanf("%d",&n);
	int* arr = (int*)malloc(n*sizeof(int));
	if(arr == NULL){
		printf("Error : Memory Not Sufficient\n");
		exit(0);
	}

	printf("Enter the elements of doubly linked list\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	Node* head = create_node(arr[0]);
	Node* head_rev = create_node(arr[0]);
    Node* curr_head;

    // Printing the Menu
    printf("-----------------------------------------------------------------------\n");
    printf("Enter 1 for printing the doubly linked list\n");
    printf("Enter 2 for searching in doubly linked list\n");
    printf("Enter 3 for inserting at the beginning of doubly linked list\n");
    printf("Enter 4 for inserting at the end of doubly linked list\n");
    printf("Enter 5 for deleting the last element of the doubly linked list\n");
    printf("Enter -1 to exit the program\n");
    printf("-----------------------------------------------------------------------\n");

    int ch;
    printf("Do you want to create a reversed doubly linked list? (1 for yes and 0 for no)\n");
    scanf("%d",&ch);
    if(ch == 1){
        // creating dll by adding nodes at beg.
	    for(int i=1;i<n;i++){
		    insertAtBeg(&head_rev,arr[i]);
	    }
        curr_head = head_rev;
    }
    else{
        // creating dll by inserting at the end
	    for(int i=1;i<n;i++){
		    insertAtEnd(head,arr[i]);
	    }
        curr_head = head;
    }
    
    int x = 0;
    printf("Enter the operation number to be performed on doubly linked list\n");
    while(x != -1){
        scanf("%d",&x);
        int ele = 0;
        if(x == 1){
            printLL(curr_head);
            printf("Enter the next operation number to be performed on doubly linked list\n");
        }
        else if(x == 2){
            printf("Enter the value to search for: ");
            scanf("%d",&ele);
            Node* node = search(curr_head,ele);
            if(node != NULL){
                printf("Element %d found in doubly linked list\n\n",ele);
            }
            else{
                printf("Element %d not founf in doubly linked list\n\n",ele);
            }
            printf("Enter the next operation number to be performed on doubly linked list\n");
        }
        else if(x == 3){
            printf("Enter the element to be inserted at beginning of doubly linked list: ");
            scanf("%d",&ele);
            insertAtBeg(&curr_head,ele);
            printf("Insertion Done successfully!!\n\n");
            printf("Enter the next operation number to be performed on doubly linked list\n");
        }
        else if(x == 4){
            printf("Enter the element to be inserted at end of doubly linked list: ");
            scanf("%d",&ele);
            insertAtEnd(curr_head,ele);
            printf("Insertion Done successfully!!\n\n");
            printf("Enter the next operation number to be performed on doubly linked list\n");
        }
        else if(x == 5){
            deleteFromEnd(curr_head);
            printf("Deletion Done successfully !!\n\n");
            printf("Enter the next operation number to be performed on doubly linked list\n");
        }
    }

    printf("Exiting the program...\n");

	return 0;
}

