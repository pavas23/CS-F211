#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int giveRandom(int x){
    static int res;
    static int count = 0;

    count++;

    if(count == 1){
        res = x;
    }else{
        int i = rand()%count; // i can be 0 to count-1 with equal probability
        if(i == count-1){
            res = x;
        }
    }
    return res;
}

int main(void){
    int n = 0;
    scanf("%d",&n);
    int x = 0;
    srand(time(NULL)); // to give different results on each run
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        printf("%d\n",giveRandom(x));
    }
    return 0;
}
