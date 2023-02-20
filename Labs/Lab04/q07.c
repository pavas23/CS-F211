#include<stdio.h>
#include<stdlib.h>

void printArray(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int getMax(int* arr,int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int* arr,int n,int place){
    int countArr[10];
    for(int i=0;i<10;i++){
        countArr[i] = 0;
    }
    int output[n];
    for(int i=0;i<n;i++){
        countArr[(arr[i]/place)%10]++;
    }
    for(int i=1;i<10;i++){
        countArr[i] += countArr[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[countArr[(arr[i]/place)%10]-1] = arr[i];
        countArr[(arr[i]/place)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
    printArray(arr,n);
}

void radixSort(int* arr,int n){
    int max = getMax(arr,n);
    for(int place = 1;max/place >0;place*=10){
        countingSort(arr,n,place);
    }
    return;
}

int main(void){
    int n = 0;
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    radixSort(arr,n);
    printf("\n");
    return 0;
}