#include<iostream>
using namespace std;

void swap(int* arr,int i,int j){
    int temp = *(arr+i);
    *(arr+i) = *(arr+j);
    *(arr+j) = temp;
}

// heapify O(h)
void heapify(int* arr,int n,int startIndex){
    int parentIndex = startIndex;
    int leftChildIndex = 2*parentIndex;
    int rightChildIndex = 2*parentIndex+1;
    if(leftChildIndex < n && arr[leftChildIndex] >= arr[parentIndex]){
        parentIndex = leftChildIndex;
    }
    if(rightChildIndex < n && arr[rightChildIndex] >= arr[parentIndex]){
        parentIndex = rightChildIndex;
    }
    if(parentIndex != startIndex){
        swap(arr,parentIndex,startIndex);
        heapify(arr,n,parentIndex);
    }else{
        return;
    }
}

// O(n)
void buildMaxHeap(int* arr,int n){
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

// up-heapify O(logn)
void insertInMaxHeap(int* arr,int n,int x){
    arr = (int*)realloc(arr,(n+1)*sizeof(int));
    arr[n] = x;
    int childIndex = n;
    while(childIndex > 1){
        int parentIndex = childIndex/2;
        if(arr[parentIndex] < arr[childIndex]){
            swap(arr,parentIndex,childIndex);
            childIndex = parentIndex;
        }else{
            return;
        }
    }
    return;
}

// down-heapify O(logn)
int removeTopMaxHeap(int* arr,int n){
    int lastElement = arr[n-1];
    int maxElement = arr[1];
    arr[1] = lastElement;
    arr = (int*)realloc(arr,(n-1)*sizeof(int));
    int parentIndex = 1;
    int leftChildIndex = 2*parentIndex;
    int rightChildIndex = 2*parentIndex+1;
    while(rightChildIndex < n){
        leftChildIndex = 2*parentIndex;
        rightChildIndex = 2*parentIndex+1;
        int maxIndex = -1;
        if(arr[leftChildIndex] >= arr[rightChildIndex]){
            maxIndex = leftChildIndex;
        }else{
            maxIndex = rightChildIndex;
        }
        if(arr[parentIndex] >= arr[maxIndex]){
            break;
        }else{
            swap(arr,parentIndex,maxIndex);
            parentIndex = maxIndex;
        }
    }
    return maxElement;
}

// O(n*logn)
void heapSort(int** arrRef,int size){
    int* arr = *arrRef;
    buildMaxHeap(arr,size);
    // Now remove elements one by one
    int* sortedArr = (int*)malloc((size-1)*sizeof(int));
    for(int i=0;i<size-1;i++){
        sortedArr[size-1-i-1] = removeTopMaxHeap(arr,size);
    }
    *arrRef = sortedArr;
    return;
}

int main(void){
    int n = 0;
    cout<<"Enter the size of heap "<<endl;
    cin>>n;
    int* heap = (int*)calloc(n+1,sizeof(int));
    heap[0] = -1;
    cout<<"Enter the elements out of which heap is to be formed "<<endl;
    for(int i=1;i<n+1;i++){
        cin>>heap[i];
    }
    buildMaxHeap(heap,n+1);
    cout<<"The Heap formed is\n";
    for(int i=1;i<n+1;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    cout<<"Heap Sort\n";
    heapSort(&heap,n+1);
    for(int i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    return 0;
}

