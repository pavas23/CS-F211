## CS-F211
2-2, DSA course at BITS Pilani, Hyderabad Campus

## Topics Covered
  - Time and Space Complexity
  - Searching and Sorting Algorithms
  - Stacks and Queues
  - Linked Lists
  - Priority Queues and Heaps
  - Hash Tables
  - BST, Balanced BST, Red Black Trees
  - Skip List
  - Divide and Conquer
  - Greedy Algorithm
  - Dynamic Programming
  - Graph Algorithms

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
| 2  | Implementing basic operations on Singly linked list and Structures | [Lab 2](https://github.com/pavas23/CS-F211/blob/main/Labs/Lab02/LabSheet2.pdf) | 07 Feb 2023 |
| 3  | Doubly Linked Lists and Binary Search | [Lab 3](https://github.com/pavas23/CS-F211/blob/main/Labs/Lab03/LabSheet3.pdf) | 14 Feb 2023 |
| 4  | Sorting and Math | [Lab 4](https://github.com/pavas23/CS-F211/blob/main/Labs/Lab04/LabSheet4.pdf) | 21 Feb 2023 |
| 5  | Recursion, Prefix Sum, Sliding Window, Bitmasking | [Lab 5](https://github.com/pavas23/CS-F211/blob/main/Labs/Lab05/LabSheet5.pdf) | 28 Feb 2023 |
| 6  | Stacks and Queues | [Lab 6](https://github.com/pavas23/CS-F211/blob/main/Labs/Lab06/LabSheet6.pdf) | 07 Mar 2023 |
| 7  | Heaps, Binary Trees and Binary Search Trees | [Lab 7](https://github.com/pavas23/CS-F211/blob/main/Labs/Lab07/LabSheet7.pdf) | 28 Mar 2023 |
| 8  | Maps, Sets and Strings | [Lab 8](https://github.com/pavas23/CS-F211/blob/main/Labs/Lab08/LabSheet8.pdf) | 11 Apr 2023 |
| 9  | Maps, Sets, Strings and Stacks | [Lab 9](https://github.com/pavas23/CS-F211/blob/main/Labs/Lab09/LabSheet9.pdf) | 18 Apr 2023 |
| 10  |  Divide and Conquer, Recap | [Lab 10](https://github.com/pavas23/CS-F211/blob/main/Labs/Lab10/LabSheet10.pdf) | 25 Apr 2023 |
