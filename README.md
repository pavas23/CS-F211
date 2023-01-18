## CS-F211
2-2, DSA course in C at BITS Pilani, Hyderabad Campus

## Important Notes

#### Initializing Array Using Malloc
```c
int** array;
array = (int**)malloc(n*sizeof(int*));
for(int i=0;i<n;i++){
  int* temp = (int*)malloc(n*sizeof(int));
  array[i] = temp;
}
```
