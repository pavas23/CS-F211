#include<stdio.h>
#include<stdlib.h>

void merge(int* arr,int start,int mid,int end){
    int size1 = mid-start+1;
    int size2 = end-mid;
    int* arr1 = (int*)malloc(size1*sizeof(int));
    int* arr2 = (int*)malloc(size2*sizeof(int));
    for(int i=0;i<size1;i++){
        arr1[i] = arr[i+start];
    }
    for(int i=0;i<size2;i++){
        arr2[i] = arr[size1+i+start];
    }
    int i=0,j=0;
    int k = 0;
    while(i<size1 && j<size2){
        if(arr1[i] <= arr2[j]){
            arr[k+start] = arr1[i];
            i++;
            k++;
        }else{
            arr[k+start] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<size1){
        arr[k+start] = arr1[i];
        i++;
        k++;
    }
    while(j<size2){
        arr[k+start] = arr2[j];
        j++;
        k++;
    }
    return;
}

void mergeSort(int* arr,int start,int end){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,0,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main(void){
    int n = 0;
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    int score = 0;
    for(int i=n-1;i>=0;i--){
        int x = i+1;
        if(arr[n-x] >= x && x!=n && arr[n-x-1] <= x){
            if(x>score){
                score = x;
            }
        }
    }
    printf("%d\n",score);
    return 0;
}