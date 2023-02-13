#include<stdio.h>
#include<stdlib.h>

int main(void){
    
    int n=0,k=0;

    // taking input
    scanf("%d",&n);
    scanf("%d",&k);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",(arr+i));
    }
    int low = 0;
    int high = n-1;
    int maxAmt = 0;
    if(n == 1 && arr[0] <= k){
        maxAmt = arr[0];
        printf("%d\n",maxAmt);
        return 0;
    }
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] == k){
            maxAmt = k;
            break;
        }
        else if(arr[mid] > k){
            high = mid-1;
        }
        else{
            if((mid+1<n) && arr[mid+1] > k){
                maxAmt = arr[mid];
                break;
            }
            low = mid+1;
        }
        if(high-low <= 1){
            if(arr[high] <= k){
                maxAmt = arr[high];
                break;
            }
            else{
                maxAmt = arr[low];
                break;
            }
        }
    }
    printf("%d\n",maxAmt);
    return 0;
}

