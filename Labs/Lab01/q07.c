#include<stdio.h>

int main(void){
    char sentence[1000];
    char word[1000];
    int i = 0;
    char ch = ' ';
    while(ch != '\n'){
        scanf("%c",&ch);
        sentence[i] = ch;
        i++;
    }
    ch = ' ';
    int lenOfSentence = i-1;
    i = 0;
    while(ch != '\n'){
        scanf("%c",&ch);
        word[i] = ch;
        i++;
    }
    int lenOfWord = i-1;
    int startIndex = 0, endIndex = 0;
    
}