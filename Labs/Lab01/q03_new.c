// left
#include<stdio.h>
#include<stdlib.h>

void indices(int* arr, int n, int i, int sum, int* ans_arr){
    if(i == n-1){
        int size = (&ans_arr)[1]-ans_arr;
        ans_arr[n-1] = i;
        return;
    }
    indices(arr,n-1,i+1,sum,ans_arr);
    int size = (&ans_arr)[1]-ans_arr;
    ans_arr[size-1] = i;
    indices(arr,n-1,i+1,sum-arr[i],ans_arr);
}

void sortArr(int* arr,int n){
    // bubble sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] =  arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(void){

    // taking input from the user
    int n=0,s=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&s);

    int* ans_arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        ans_arr[i] = 0;
    }
    indices(arr,n,0,s,ans_arr);
    // &ans points to entire array and (&ans)[1] points to next ele after the last element in array
    // and (&ans)[1]-ans gives the size of array
    sortArr(ans_arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",ans_arr[i]);
    }

    return 0;

}





