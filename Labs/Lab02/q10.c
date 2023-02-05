#include<stdio.h>
#include<stdlib.h>

// sorting the struct according to medals

typedef struct country{
    char name[21];
    int gold;
    int silver;
    int bronze;
}country;

void swap(country* arr, int i, int j){
    country temp = *(arr+i);
    *(arr+i) = *(arr+j);
    *(arr+j) = temp;
    return;
}

void findRanking(country* arr, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((arr+i)->gold < (arr+j)->gold){
                swap(arr,i,j);
            }
            else if((arr+i)->gold == (arr+j)->gold){
                if((arr+i)->silver < (arr+j)->silver){
                    swap(arr,i,j);
                }
                else if((arr+i)->silver == (arr+j)->silver){
                    if((arr+i)->bronze  < (arr+j)->bronze){
                        swap(arr,i,j);
                    }
                }
            }
        }
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    country* arr = (country*)malloc(n*sizeof(country));
    for(int i=0;i<n;i++){
        scanf("%s",arr[i].name);
        scanf("%d",&arr[i].gold);
        scanf("%d",&arr[i].silver);
        scanf("%d",&arr[i].bronze);
    }

    findRanking(arr,n);

    for(int i=0;i<n;i++){
        printf("%s\n",arr[i].name);
    }

    return 0;
}

