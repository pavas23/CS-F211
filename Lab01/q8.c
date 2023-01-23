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

    // putting ' ' after last char to avoid errors
    s[i-1] = ' ';

    // tokenizing words based on white spaces and storing in 2D array
    int n = i-1;
    int j = 0;
    i = 0;
    char tokens[1000][1000];
    int k = 0;
    for(int j=0;j<n;j++){
        k = 0;
        while(s[j] != ' '){
            tokens[i][k] = s[j];
            j++;
            k++;
        }
        i++;
    }
    int rows = i;

    // reversing each word of the sentence.
    char rev_tokens[1000][1000];
    for(int i=0;i<rows;i++){
        int x = 0;
        while(tokens[i][x] != '\0'){
            x++;
        }
        int y = 0;
        while(tokens[i][y] != '\0'){
            rev_tokens[i][y] = tokens[i][x-y-1];
            y++;
        }
        int k = 0;
    }

    // printing the words in reverse order
    for(int i=0;i<rows;i++){
        int x = 0;
        while(rev_tokens[i][x] != '\0'){
            printf("%c",rev_tokens[i][x]);
            x++;
        }
        printf(" ");
    }

    printf("\nPrinting The Palindrome Words In The Given String\n");

    // printing the palindrome words
    int count = 0;
    for(int i=0;i<rows;i++){
        int x = 0;
        int flag = 0;
        while(rev_tokens[i][x] != '\0'){
            if(rev_tokens[i][x] != tokens[i][x]){
                flag = 1;
                break;
            }
            x++;
        }
        if(flag){
            continue;
        }
        else{
            if(x==1){
                // words of length 1 not to be considered
                continue;
            }
            count++;
            int y = 0;
            while(tokens[i][y] != '\0'){
                printf("%c",tokens[i][y]);
                y++;
            }
            printf(" ");
        }
    }
    if(count == 0){
        printf("\nNO PALINDROMES\n");
    }
    printf("\n\n");
    return 0;
}
