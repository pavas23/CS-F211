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

    // taking input from the user
    int n=0,s=0;
    scanf("%d",&n);
    int arr[n];
    int arr_extra[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        arr_extra[i] = arr[i];
    }
    scanf("%d",&s);

    // sorting the array
    sortArr(arr,n);

    int i=0,j=n-1;
    int temp_arr[n];
    int sum = s;
    int k = 0;
    int flag = 0;

    while(i<=j){
        if(arr[i] + arr[j] < sum){
            temp_arr[k++] = arr[i];
            temp_arr[k++] = arr[j];
            sum = s - arr[i] - arr[j];
            i++;
            j--;
        }
        else if(arr[i] + arr[j] > sum){
            j--;
        }
        else{
            temp_arr[k] = arr[i];
            temp_arr[++k] = arr[j];
            k++;
            flag = 1;
            break;
        }
        if(sum == 0){
            flag = 1;
            break;
        }
    }

    // if flag is true then we have found the sum
    if(flag){
        int indices[n];
        int y = 0;
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                if(arr_extra[j] == temp_arr[i]){
                    indices[y] = j;
                    y++;
                    arr_extra[j] = -1;
                    break;
                }
            }
        }
        // sorting the indices
        sortArr(indices,y);
        for(int x=0;x<y;x++){
            printf("%d ",indices[x]);
        }
        printf("\n");
    }
    else{
        printf("\nNOT POSSIBLE\n");
    }
    return 0;

}

