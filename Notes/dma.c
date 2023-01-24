#include<stdio.h>
#include<stdlib.h>

long int sum(int** mat,int n){
	long int sum = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum += mat[i][j];
		}
	}
	return sum;
}

int main(void){

	/* malloc will allocate continuous memory of size given, it return void* pointer which needs to be type casted, if memory not sufficient it will return NULL pointer.*/
	int* ptr = (int*)malloc(4000);
	
	/* calloc will give continuous n blocks of memory all initialized to 0 and again return a void* pointer which needs to typecastesd and if memory not sufficient it will return NULL pointer */
	int* ptr1 = (int*)calloc(10,sizeof(int));
	
	if(ptr == NULL){
		printf("Error: Memory not allocated");
	}
	printf("%p\n",ptr);
	
	int n = 0;
	printf("Enter the value of n\n");
	scanf("%d",&n);

	// this will give n rows which will contain pointers of int* type and a will contain the base address of the memory location
	int** a = (int**)malloc(n*sizeof(int*));
	if(a == NULL){ printf("Memory Not Allocated !"); exit(0);}
	// for every row pointer will point to memory location which contains space for n integers
	for(int i=0;i<n;i++){
		a[i] = (int*)malloc(n*sizeof(int));
		if(a[i] == NULL){printf("Memory not allocated!!"); exit(0);}
	}
	
	printf("Enter the values for 2D array\n");
	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("\nPrinting the 2D array\n");
	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	printf("\nThe sum of elements of 2D array is %ld\n",sum(a,n));
	
	return 0;
}


