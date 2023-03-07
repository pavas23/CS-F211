#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n = 0;
    scanf("%d",&n);
    int* queue = (int*)malloc(n*sizeof(int));
    int* freq_arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        freq_arr[i] = 0;
    }
    int curr = -1;
    int rear  = 0;
    int front = 0;
    for(int i=0;i<n;i++){
        int x = 0;
        scanf("%d",&x);
        if(front == rear){
            if(freq_arr[x] == 1){
                freq_arr[x] = -1;
                printf("%d ",-1);
            }else{
                queue[rear] = x;
                curr = x;
                printf("%d ",curr);
                freq_arr[curr]++;
                rear++;
            }
        }else{
            if(freq_arr[curr] != -1 && curr != x){
                printf("%d ",curr);
                if(freq_arr[x] == 1){
                    freq_arr[x] = -1;
                }else{
                    freq_arr[x] = 1;
                }
                queue[rear] = x;
                rear++;
            }else{
                freq_arr[x] = -1;
                while(front < rear && freq_arr[queue[front]] == -1){
                    front++;
                }
                if(front == rear){
                    printf("%d ",-1);
                    curr = -1;
                }else{
                    printf("%d ",queue[front]);
                    curr = queue[front];
                }
            }
        }
    }
    printf("\n");
    return 0;
}

