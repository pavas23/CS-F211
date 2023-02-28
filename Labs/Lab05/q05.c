#include <stdio.h>
int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0){
            count++;
        }
    }
    int ar[count];
    int numZeros = count;
    if(numZeros == 0){
        printf("%d\n",n);
        return 0;
    }
    if(numZeros < k){
        k = numZeros;
    }
    count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0){
            ar[count] = i;
            count++;
        }
    }
    int start = 0, end = 0, max = 0;
    for (int i = 0; i <= numZeros-k;i++){
        if (i == 0){
            start = 0;
        }
        else{
            start = ar[i - 1] + 1;
        }
        if(i+k<numZeros){
            end = ar[i + k] - 1;
        }
        else{
            end = ar[numZeros-1];
            if (end < n - 1){
                end = n - 1;
            }
        }
        if (max < (end - start + 1)){
            max = end - start + 1;
        }
    }
    printf("%d\n", max);
    return 0;
}
