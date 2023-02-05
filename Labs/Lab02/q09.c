#include<stdio.h>
#include<string.h>

// finding BITS ID from BITS mail and branch using structures

// student structure for storing email, branch, id
typedef struct stud{
    char email[38];
    char branch[4];
    char id[14];
}stud;

void generateBITS_ID(stud* student){
    char id[14];
    int index = 0;
    int i = 1;
    while(i<=4){
        id[index] = (student->email)[i];
        index++;
        i++;
    }
    // strcmp returns 0 if strings are equal
    if(!strcmp(student->branch,"CS")){
        id[index]  = 'A';
        index++;
        id[index] = '7';
        index++;
    }
    else if(!strcmp(student->branch,"ECE")){
        id[index] = 'A';
        index++;
        id[index] = 'A';
        index++;
    }
    else if(!strcmp(student->branch,"EEE")){
        id[index] += 'A';
        index++;
        id[index] = '3';
        index++;
    }
    else{
        id[index] += 'X';
        index++;
        id[index] = 'X';
        index++;
    }
    id[index] = 'P';
    index++;
    id[index] =  'S';
    index++;
    int j = 5;
    while(j<=8){
        id[index] = (student->email)[j];
        index++;
        j++;
    }
    id[index] = 'H';
    index++;
    id[index] += '\0';
    int x = 0;
    while(id[x] != '\0'){
        (student->id)[x] = id[x];
        x++;
    }
    return;
}

int main(void){
    stud stud1;
    scanf("%s",stud1.email);
    scanf("%s",stud1.branch);
    generateBITS_ID(&stud1);
    printf("%s\n",stud1.id);
    return 0;
}