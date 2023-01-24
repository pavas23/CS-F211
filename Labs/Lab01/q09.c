#include<stdio.h>

void swap(int* arr,int i,int j){
    int temp  = *(arr+i);
    *(arr+i) = *(arr+j);
    *(arr+j) = temp;
}

void helper(int* arr,int start,int end,int mid,int n){

    if(start > end){
        return;
    }

    // this will bring all elements smaller than mid in front of it
    int i = start-1;
    for(int j=start;j<n;j++){
        if(*(arr+j) < mid){
            for(int k=j;k>i+1;k--){
                swap(arr,k,k-1);
            }
            i++;
        }
    }

    // this will bring all elements greater than mid behind it
    int initial = 0;
    int last  = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > mid){
            initial = i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i] == mid){
            last = i;
            break;
        }
    }

    // bringing the mid ele to its correct place
    for(int i=last;i>=initial+1;i--){
        swap(arr,i,i-1);
    }

}

int main(void){

    int k=0,n=0;
    scanf("%d",&k);
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int mid = (k+1)/2;
    helper(arr,0,n-1,mid,n);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
