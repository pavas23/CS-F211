// left

#include<stdio.h>

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

    int n=0,s=0;
    int arr[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&s);

    sortArr(arr,n);
    printf("After sorting the array\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");

    int i=0,j=n-1;

    int temp_arr[n];
    printf("\n%d %d\n",j,arr[j]);
    int sum = s;
    int k = 0;

    while(i<=j){
        if(arr[i] + arr[j] < sum){
            temp_arr[k++] = arr[i];
            temp_arr[k++] = arr[j];
            // printf("%d %d\n",temp_arr[k-2],temp_arr[k-1]);
            // printf("%d\n",arr[j]);
            sum = s - arr[i] - arr[j];
            i++;
            j--;
        }
        else if(arr[i] + arr[j] > sum){
            j--;
        }
        else{
            temp_arr[k] = i;
            temp_arr[++k] = j;
            k++;
            break;
        }
        if(sum == 0){
            break;
        }
    }

    for(int i=0;i<k;i++){
        printf("%d ",temp_arr[i]);
    }

    return 0;

}

