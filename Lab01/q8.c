#include<stdio.h>

int main(void){

    char s[1000];
    char ch = ' ';
    int i = 0;
    
    // taking input from the user 
    while(ch != '\n'){
        scanf("%c",&ch);
        s[i] = ch;
        i++;
    }

    int n = i-1;
    int j = 0;
    i = 0;
    char tokens[1000][1000];
    for(int j=0;j<n;j++){
        while(s[j] != ' '){
            tokens[i][j] = s[j];
            j++;
        }
        i++;
    }

    // printing the words
    int rows = i-1;
    for(int i=0;i<rows;i++){
        int x = 0;
        while(tokens[i][x] != '\0'){
            printf("%c",tokens[i][x]);
        }
        printf("\n");
    }

}
