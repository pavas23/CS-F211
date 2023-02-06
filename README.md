## CS-F211
2-2, DSA course in C at BITS Pilani, Hyderabad Campus

## Topics Covered
  - Time and Space Complexity

## Important Notes

#### Initializing Array Using Malloc
```c
int** array;
// allocating memory for n pointers of size int*
array = (int**)malloc(n*sizeof(int*));
// allocating memory for n int values to each pointer
for(int i=0;i<n;i++){
  int* temp = (int*)malloc(n*sizeof(int));
  array[i] = temp;
}
```
#### Passing 2D-Array declared using DMA to function

```c
int function(int** arr){
  // can access arr[i][j]
}
```
#### Finding length of Array in C
```c
int arr[100];
int size = (&arr)[1]-arr;
// size = 100
// (&arr)[1] points to memory location just after the last element of array and arr points to base index of array
// similarly for character arrays
```
#### Finding length of 2D-Array in C
```c
int arr[5][3];
int size = (&arr)[1]-arr;
// size = 5
// (&arr)[1] points to memory location just after the last row of array and arr points to base index of array
```

### Lab Summary

| Lab | Topic | Lab Sheet | Date |
| ------------- | ------------- | --- | -- |
| 1  | Implementing Basic Algorithms like Two pointer, Sliding window, Quick sort etc. | [Lab 1](https://github.com/pavas23/CS-F211/blob/main/Labs/Lab01/LabSheet1.pdf) | 31 Jan 2023 |
| 2  | Implementing basic operations on singly linked list and Structures | [Lab 2](lab-2/labsheet.pdf) | 7 Feb 2023 |
