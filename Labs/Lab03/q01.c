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
    }
    return 0;
}