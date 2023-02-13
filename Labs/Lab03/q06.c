#include<stdio.h>
#include<stdlib.h>

int giveLastIndexOfX(int* arr,int n,int x,int*k){
    int low = 0;
    int high = n-1;
    int lastIndex = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            lastIndex = mid;
            low = mid+1;
        }
        else if(arr[mid] < x){
            low = mid+1;
        } 
        else{
            high = mid-1;
        }
    }
    (*k)++;
    return lastIndex;
}

int main(void){
    int n = 0;

    // taking input
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",(arr+i));
    }

    // k is number of distinct elements
    int k = 0;
    int lastIndex = -1;

    for(int i=0;i<n;i++){
        // it will return the index of element passed where it last occurs, then search for the element at next index and so on
        lastIndex = giveLastIndexOfX(arr,n,arr[lastIndex+1],&k);
        // when lastIndex hits n-1, that is all the unique elements are found.
        if(lastIndex == n-1){
            break;
        }
    }
    printf("%d\n",k);
    return 0;
}

