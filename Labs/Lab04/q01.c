#include<stdio.h>
#include<stdlib.h>

void printArray(int** arr,int n){
    for(int i=0;i<n;i++){
        printf("%d %d\n",arr[i][0],arr[i][1]);
    }
    printf("\n\n");
}

void mergeSortedArray(int** arr,int start,int mid,int end){
    int size1 = mid-start+1;
    int** arr1 = (int**)malloc(size1*sizeof(int*));
    for(int i=0;i<size1;i++){
        arr1[i] = (int*)malloc(2*sizeof(int));
    }
    for(int i=0;i<size1;i++){
        arr1[i][0] = arr[i+start][0];
        arr1[i][1] = arr[i+start][1];
    }
    int size2 = end-mid;
    int** arr2 = (int**)malloc(size2*sizeof(int*));
    for(int i=0;i<size2;i++){
        arr2[i] = (int*)malloc(2*sizeof(int));
    }
    for(int i=0;i<size2;i++){
        arr2[i][0] = arr[size1+i+start][0];
        arr2[i][1] = arr[size1+i+start][1];
    }
    int i = 0,j=0;
    int k = 0;
    while(i<size1 && j<size2){
        if(arr1[i][0] < arr2[j][0]){
            arr[k+start][0] = arr1[i][0];
            arr[k+start][1] = arr1[i][1];
            i++;k++;
        }
        else if(arr1[i][0] > arr2[j][0]){
            arr[k+start][0] = arr2[j][0];
            arr[k+start][1] = arr2[j][1];
            j++;k++;
        }
        else{
            if(arr1[i][1] <= arr2[j][1]){
                arr[k+start][0] = arr1[i][0];
                arr[k+start][1] = arr1[i][1];
                i++;k++;
            }else{
                arr[k+start][0] = arr2[j][0];
                arr[k+start][1] = arr2[j][1];
                j++;k++;
            }
        }
    }
    while(i<size1){
        arr[k+start][0] = arr1[i][0];
        arr[k+start][1] = arr1[i][1];
        i++;k++;
    }
    while(j<size2){
        arr[k+start][0] = arr2[j][0];
        arr[k+start][1] = arr2[j][1];
        j++;k++;
    }
    return;
}

void mergeSort(int** arr,int start,int end){
    if(start >= end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    mergeSortedArray(arr,start,mid,end);
}

void sortAccordingToStartTime(int** arr,int n){
    mergeSort(arr,0,n-1);
    return;
}

int main(void){
    int n = 0;
    scanf("%d",&n);
    int** arr = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        int* temp = (int*)malloc(2*sizeof(int));
        arr[i] = temp;
    }
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }

    if(n == 1){
        printf("\n%d\n",n);
        printArray(arr,n);
        exit(0);
    }

    // sorting the slots according to the start time, if start time equal then sort according to end time
    sortAccordingToStartTime(arr,n);

    printf("\n\n");
    printArray(arr,n);

    // merging the slots into newArr
    int count = 0;
    int** newArr;
    int x = 0;
    for(int i=0;i<n-1;i++){
        x = i;
        int flag = 0;
        int maxEnd = arr[i][1];
        // if endTime of a slot is greater than or eqaul to start of next slot then keep incrementing and maintain a maxend.
        while(i<n-1 && arr[i][1] >= arr[i+1][0]){
            i++;
            if(arr[i][1] > maxEnd){
                maxEnd = arr[i][1];
            }
            flag = 1;
        }
        count++;
        newArr = (int**)realloc(newArr,count*sizeof(int*));
        newArr[count-1] = (int*)malloc(2*sizeof(int));
        newArr[count-1][0] = arr[x][0];
        newArr[count-1][1] = maxEnd;
        if(i == n-2){
            count++;
            newArr = (int**)realloc(newArr,count*sizeof(int*));
            newArr[count-1] = (int*)malloc(2*sizeof(int));
            newArr[count-1][0] = arr[i+1][0];
            newArr[count-1][1] = arr[i+1][1];
        }
    }
    printf("\n%d\n",count);
    printArray(newArr,count);
    return 0;
}
