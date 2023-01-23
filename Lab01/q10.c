#include<stdio.h>
#include<stdlib.h>

int main(void){

    char arr1[1000];
    char arr2[1000];

    char ch1 = ' ';
    int i = 0;
    while(ch1 != '\n'){
        scanf("%c",&ch1);
        arr1[i] = ch1;
        i++;
    }

    char ch2 = ' ';
    int j = 0;
    while(ch2 != '\n'){
        scanf("%c",&ch2);
        arr2[j] = ch2;
        j++;
    }
    
    int n1=i-1,n2=j-1;
    if(i != j){
        printf("\nNOT POSSIBLE\n\n");
    }
    else{
        int arr[n1];
        int k = 0;
        int flag = 0;
        for(int i=0;i<n1;i++){
            flag = 0;
            for(int j=0;j<n2;j++){
                if(arr1[j] == arr2[i]){
                    flag = 1;
                    arr[k] = j+1;
                    k++;
                }
            }
            if(flag == 0){
                // means the char is not found in arr1
                printf("\nNOT POSSIBLE\n");
                exit(0);
            }
        }
        printf("\nPOSSIBLE\n");
        for(int i=0;i<n1;i++){
            printf("%d ",arr[i]);
        }
        printf("\n\n");
    }
}




