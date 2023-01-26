## CS-F211
2-2, DSA course in C at BITS Pilani, Hyderabad Campus

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
### Lab Summary

| Lab | Topic | Lab Sheet | Date |
| ------------- | ------------- | --- | -- |
| 1  | Implementing Basic Algorithms like two pointer,sliding window, quick sort etc. | [Lab 1](ab-1/labsheet.pdf) | 22 Jan 2022 |
| 2  | Command Line Arguments, Compiling and Linking C files, File I/O, Pointers, Linked Lists _(non-evaluative)_ | [Lab 2](lab-2/labsheet.pdf) | 29 Jan 2022 |
