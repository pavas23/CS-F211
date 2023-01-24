#include<stdio.h>
#include<stdlib.h>

int main(void){
	
	int n = 0;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	// allocating memory for 3D array
	int*** arr = (int***)malloc(n*sizeof(int**));
	if(arr == NULL){printf("Memory Error\n"); exit(0);}
	for(int i=0;i<n;i++){
		arr[i] = (int**)malloc(n*sizeof(int*));
		if(arr[i] == NULL){printf("Memory Error\n"); exit(0);}
		for(int j=0;j<n;j++){
			arr[i][j] = (int*)malloc(n*sizeof(int));
			if(arr[i][j] == NULL){printf("Memory Error\n"); exit(0);}
		}
	}
	
	// taking input of 3D array
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				scanf("%d",&arr[i][j][k]);
			}
		}
	}
	
	// printing the 3D array
	printf("\n\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				printf("%d ",arr[i][j][k]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	
	// deallocating the memory for 3D array
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			free(arr[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		free(arr[i]);
	}
	free(arr);
	return 0;
}
