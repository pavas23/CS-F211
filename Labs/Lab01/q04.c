#include<stdio.h>

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void){
    int n = 0;

    // taking user input
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // iterating through the whole array using two pointers i and j
    int i=0,j=1;
    while(i<n && j<n){
        if(arr[i] < 0){
            i++;
            j++;
        }
        // if at any index positive value is there swap all the pos values with the next available negative value
        else{
            int flag = 0;
            while((j<n) && (arr[j] > 0)){
                if(j == n-1){
                    flag = 1;
                    break;
                }
                j++;
            }
            // if only positive values are there till end, then no need to swap
            if(flag == 1){
                break;
            }
            // swap all adjacent values till the negative value is at it's right place
            for(int k=j;k>i;k--){
                swap(&arr[k],&arr[k-1]);
            }
        }
    }

    // printing the array
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;

}
