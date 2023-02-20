#include<stdio.h>
#include<stdlib.h>

void printMatrix(int** matrix,int n){
    for(int i=0;i<n;i++){
        printf("%d %d\n",matrix[i][0],matrix[i][1]);
    }
    printf("\n");
}

void mergeSortedArray(int** arr,int start,int mid,int end){
    int size1 = mid-start+1;
    int** arr1 = (int**)malloc(size1*sizeof(int*));
    for(int i=0;i<size1;i++){
        arr1[i] = (int*)malloc(2*sizeof(int));
    }
    for(int i=0;i<size1;i++){
        arr1[i][0] = arr[i+start][0];
        arr1[i][1] = arr[i+start][1];
    }
    int size2 = end-mid;
    int** arr2 = (int**)malloc(size2*sizeof(int*));
    for(int i=0;i<size2;i++){
        arr2[i] = (int*)malloc(2*sizeof(int));
    }
    for(int i=0;i<size2;i++){
        arr2[i][0] = arr[size1+i+start][0];
        arr2[i][1] = arr[size1+i+start][1];
    }
    int i = 0,j=0;
    int k = 0;
    while(i<size1 && j<size2){
        if(arr1[i][1] <= arr2[j][1]){
            arr[k+start][0] = arr1[i][0];
            arr[k+start][1] = arr1[i][1];
            i++;k++;
        }
        else{
            arr[k+start][0] = arr2[j][0];
            arr[k+start][1] = arr2[j][1];
            j++;k++;
        }
    }
    while(i<size1){
        arr[k+start][0] = arr1[i][0];
        arr[k+start][1] = arr1[i][1];
        i++;k++;
    }
    while(j<size2){
        arr[k+start][0] = arr2[j][0];
        arr[k+start][1] = arr2[j][1];
        j++;k++;
    }
    return;
}

void mergeSort(int** arr,int start,int end){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    mergeSortedArray(arr,start,mid,end);
}

void sortAccordingToVotes(int** arr,int n){
    mergeSort(arr,0,n-1);
    return;
}

int main(void){
    int n=0,k=0;
    scanf("%d",&n);
    scanf("%d",&k);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int maxElement = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > maxElement){
            maxElement = arr[i];
        }
    }
    int** matrix = (int**)malloc((1+maxElement)*sizeof(int*));
    for(int i=0;i<maxElement+1;i++){
        matrix[i] = (int*)malloc(2*sizeof(int));
    }
    for(int i=0;i<maxElement+1;i++){
        matrix[i][0] = i;
        matrix[i][1] = 0;
    }
    for(int i=0;i<n;i++){
        matrix[arr[i]][0] = arr[i];
        matrix[arr[i]][1]++;
    }

    // will sort in descending order of votes
    sortAccordingToVotes(matrix,maxElement+1);

    for(int i=0;i<k;i++){
        printf("%d ",matrix[maxElement-i][0]);
    }
    printf("\n");
    return 0;
}