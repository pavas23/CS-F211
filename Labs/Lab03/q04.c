#include "template.h"

int main(void){
    Node* head = readList();
    Node* start = head;
    Node* end;
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    end = ptr;
    
    long int teamA=0,teamB=0;
    long int currTeamA=0,currTeamB=0;
    long int teamATotal=0;
    long int teamBTotal=0;

    while(start != end->next){
        if(teamATotal <= teamBTotal){
            teamATotal += start->data;
            currTeamA++;
            start = start->next;
        }
        else if(teamATotal > teamBTotal){
            teamBTotal += end->data;
            currTeamB++;
            end = end->prev;
        }
        if(teamATotal == teamBTotal){
            teamA = currTeamA;
            teamB = currTeamB;
        }
    }
    printf("%ld %ld\n",teamA,teamB);
    return 0;
}
