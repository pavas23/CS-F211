#include<stdio.h>
#include<stdlib.h>

int indices(int* arr, int n, int i, int sum, int* ans_arr){
    if(i == n-1){
        if(arr[i] == sum){
            ans_arr[i] = 1;
            return 1;
        }
        else{
            return 0;
        }
    }
    // recursive call for exclusion
    if(indices(arr,n,i+1,sum,ans_arr)){
        return 1;
    }

    // recursive call for inclusion
    ans_arr[i] = 1;
    if(indices(arr,n,i+1,sum-arr[i],ans_arr)){
        return 1;
    }
    else{
        // if recursive call for inclusion fails then backtracking
        ans_arr[i] = 0;
        return 0;
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

    // if n and s both are 0 then null set is possible
    if(s == 0 && n == 0){
        printf("POSSIBLE\n");
        return 0;
    }

    // making bit array for storing 0 if index is not included and 1 if index is included
    int* ans_arr = (int*)calloc(n,sizeof(int));
    int ans = indices(arr,n,0,s,ans_arr);

    // checking if possible or not
    int flag = 0;
    for(int i=0;i<n;i++){
        if(ans_arr[i] == 1){
            flag = 1;
        }
    }

    // if sum != 0 and all indicies are not included then not possible
    if(flag == 0){
        printf("NOT POSSIBLE\n");
        return 0;
    }

    // now print indices which have 1 in bit array
    printf("POSSIBLE\n");
    for(int i=0;i<n;i++){
        if(ans_arr[i] == 1){
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}






