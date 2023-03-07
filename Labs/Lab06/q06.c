#include<stdio.h>
#include<stdlib.h>

typedef struct deque{
    int* arr;
    int front;
    int rear;
    int size;
}deque;

deque* createDeque(int size){
    deque* dq = (deque*)malloc(sizeof(deque));
    dq->size = size;
    dq->arr = (int*)malloc(size*sizeof(int));
    dq->front = -1;
    dq->rear = 0;
    return dq;
}

void insertFront(deque* dq,int x){
    if(dq->front == -1){
        dq->front = 0;
    }
    else if(dq->front == 0){
        dq->front = dq->size-1;
    }else{
        dq->front--;
    }
    dq->arr[dq->front] = x;
    return;
}

void insertRear(deque* dq,int x){
    if(dq->front == -1){
        dq->front = 0;
        dq->rear = 0;
    }else{
        dq->rear++;
    }
    dq->arr[dq->rear] = x;
    return;
}

int getFront(deque* dq){
    return dq->arr[dq->front];
}

void printDeque(deque* dq){
    if(dq->front == 0){
        while(dq->front <= dq->rear){
            printf("%d ",getFront(dq));
            dq->front++;
        }
    }else{
        while(dq->front < dq->size){
            printf("%d ",getFront(dq));
            dq->front++;
        }
        dq->front = 0;
        while(dq->front <= dq->rear){
            printf("%d ",getFront(dq));
            dq->front++;
        }
    }
}


int main(void){

    int n = 0;
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    deque* dq = createDeque(n);
    insertFront(dq,arr[0]);

    // inserting in the deque
    for(int i=1;i<n;i++){
        if(arr[i] <= getFront(dq)){
            insertFront(dq,arr[i]);
        }else{
            insertRear(dq,arr[i]);
        }
    }

    // printing the deque
    printDeque(dq);

    printf("\n");
    return 0;
}
