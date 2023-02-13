#include "template.h"

void playNextSong(Node** currSongRef){
    Node* currSong = *currSongRef;
    if(currSong->next == NULL){
        return;
    }
    else{
        *currSongRef = currSong->next;
        return;
    }
}

void playPrevSong(Node** currSongRef){
    Node* currSong = *currSongRef;
    if(currSong->prev == NULL){
        return;
    }
    else{
        *currSongRef = currSong->prev;
        return;
    }
}

void playSongXNext(Node** headRef,Node** currSongRef,int x){
    Node* currSong = *currSongRef;
    Node* head = *headRef;
    Node* printHead = head;
    // if playlist is initially empty then currSong will be next Song
    if(head == NULL){
        addToList(headRef,x);
        *currSongRef = *headRef;
        return;
    }
    // finding if the Song x exists in the playlist or not
    int flag = 0;
    while(head != NULL){
        if(head->data == x){
            flag = 1;
            // song already exists in the playlist
            Node* prevOfX = head->prev;
            Node* nextOfX = head->next;
            // if song X is the first element of playlist
            if(prevOfX != NULL){
                prevOfX->next = nextOfX;
            }
            if(prevOfX == NULL){
                // if first element is X so head changes and points to second element of linked list
                *headRef = nextOfX;
            }
            if(nextOfX != NULL){
                nextOfX->prev = prevOfX;
            }
            Node* nextOfCurrSong = currSong->next;
            currSong->next = head;
            head->prev = currSong;
            // if currSong is the last element of playlist
            if(nextOfCurrSong != NULL){
                nextOfCurrSong->prev = head;
            }
            head->next = nextOfCurrSong;
            return;
        }
        head = head->next;
    }
    if(flag == 0){
        // song does not exists in the playlist
        Node* newSong = createNode(x);
        Node* oldNext = currSong->next;
        // if currSong is at the end of playlist
        if(oldNext == NULL){
            currSong->next = newSong;
            newSong->prev = currSong;
            return;
        }
        currSong->next = newSong;
        newSong->prev = currSong;
        newSong->next = oldNext;
        oldNext->prev = newSong;
        return;
    }
}

int main(void){
    Node* head = readList();
    Node* currSong = head;
    int x = 0;
    int flag = 0;
    while(x != 5){
        scanf("%d",&x);
        if(x == 1){
            // add song to playlist
            int val;
            scanf("%d",&val);
            addToList(&head,val);
            // if dll is initially empty then point currSong to head as soon as one song is added
            if(currSong == NULL){
                currSong = head;
            }
        }
        else if(x==2){
            // print the currSong
            if(!flag){
                printf("\n\n");
            }
            flag = 1;
            // if printing without adding any songs
            if(currSong == NULL){
                printf("Playlist is empty\n");
                continue;
            }
            printf("%d\n",currSong->data);
        }
        else if(x==3){
            // play Next Song
            // if playing the next song without adding any songs
            if(currSong == NULL){
                printf("Playlist is empty\n");
                continue;
            }
            playNextSong(&currSong);
        }
        else if(x==4){
            // if playing the prev song without adding any songs
            if(currSong == NULL){
                printf("Playlist is empty\n");
                continue;
            }
            // play Prev Song
            playPrevSong(&currSong);
        }
        else if(x==5){
            printf("\n");
            break;
        }
        else if(x==6){
            int nextSong;
            scanf("%d",&nextSong);
            playSongXNext(&head,&currSong,nextSong);
        }
    }
    return 0;
}