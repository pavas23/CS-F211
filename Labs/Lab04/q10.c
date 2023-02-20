#include<stdio.h>
#include<stdlib.h>
#define ll long long int

void mergeTwoSortedArrays(ll* arr,ll start,ll mid,ll end){
    ll size1 = mid-start+1;
    ll* arr1 = (ll*)malloc(size1*sizeof(ll));
    ll size2 = end-mid;
    ll* arr2 = (ll*)malloc(size2*sizeof(ll));
    for(ll i=0;i<size1;i++){
        arr1[i] = arr[start+i];
    }
    for(ll i=0;i<size2;i++){
        arr2[i] = arr[start+size1+i];
    }
    ll i=0,j=0,k=0;
    while(i<size1 && j<size2){
        if(arr1[i] <= arr2[j]){
            arr[start+k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr[start+k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<size1){
        arr[start+k] = arr1[i];
        i++;
        k++;
    }
    while(j<size2){
        arr[start+k] = arr2[j];
        j++;
        k++;
    }
    return;
}

void mergeSort(ll* arr,ll start,ll end){
    if(start>=end){
        return;
    }
    ll mid = (start+end)/2;
    mergeSort(arr,0,mid);
    mergeSort(arr,mid+1,end);
    mergeTwoSortedArrays(arr,start,mid,end);
}

int main(void){
    ll n = 0;
    scanf("%lld",&n);
    ll* arr = (ll*)malloc(n*sizeof(ll));
    for(ll i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    mergeSort(arr,0,n-1);

    ll medianElement = arr[n/2];
    ll steps = 0;

    for(ll i=0;i<n;i++){
        if(arr[i] < medianElement){
            steps += medianElement-arr[i];
        }else{
            steps += arr[i]-medianElement;
        }
    }
    printf("%lld\n",steps);
    return 0;
}