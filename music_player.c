#include "queue.h"
#include "dll.h"
#include "music_player.h"
#include <stdio.h>
#include <stdlib.h>

playlist_t* create_playlist() // return a newly created doubly linked list
{
	// DO NOT MODIFY!!!
	playlist_t* playlist = (playlist_t*) malloc(sizeof(playlist_t));
	playlist->list = create_list();
	playlist->num_songs = 0;
	playlist->last_song = NULL;
	return playlist;
}

void delete_playlist(playlist_t* playlist) // delete the playlist
{
	// DO NOT MODIFY!!!
	delete_list(playlist->list);
	free(playlist);
}

music_queue_t* create_music_queue() // return a newly created queue
{
	// DO NOT MODIFY!!!
	return create_queue();
}

void clear_music_queue(music_queue_t* q) // clear the queue q
{	
	// DO NOT MODIFY!!!
	delete_queue(q);
}

void add_song(playlist_t* playlist, int song_id, int where) // TODO: add a song id to the end of the playlist
{
	if(playlist ->list == NULL){
		return;
	}

	else if(where == -1){
		insert_front(playlist->list, song_id);
	}

	else if(where == -2){
       insert_back(playlist->list, song_id);
	}

	else{
		insert_after(playlist->list, song_id, where);
	}

	playlist->num_songs += 1;

}

void delete_song(playlist_t* playlist, int song_id) // TODO: remove song id from the playlist
{
	if(playlist == NULL){
		return;
	}

	else{
		delete_node(playlist->list, song_id);
	}

	playlist->num_songs -= 1;
}

song_t* search_song(playlist_t* playlist, int song_id) // TODO: return a pointer to the node where the song id is present in the playlist
{
	song_t * p = (song_t*)malloc(sizeof(song_t));

	while(p != NULL && p->data != song_id){
		p = p->next;
	}
	
	return p;
}

void search_and_play(playlist_t* playlist, int song_id) // TODO: play the song with given song_id from the list(no need to bother about the queue. Call to this function should always play the given song and further calls to play_next and play_previous)
{
	if(playlist->list->size == 0){
		return;
	}

	else{
		song_t * p = playlist->list->head;
		while(p != NULL && p->data != song_id){
			p = p->next;
		}

		if(p == NULL){
			return;
		}

		else{
           play_song(p->data);
		   playlist->last_song = p;
		}
	}
}

void play_next(playlist_t* playlist, music_queue_t* q) // TODO: play the next song in the linked list if the queue is empty. If the queue if not empty, play from the queue
{
	if(q->size != 0 && q->front!= NULL){
		play_from_queue(q);
	}

	else{
		if(playlist->last_song == NULL){
			play_song(playlist->list->head->data);
			playlist->last_song = playlist->list->head;
		}

		else if(playlist->last_song->next == NULL){
               play_song(playlist->list->head->data);
               //playlist->last_song->next = playlist->list->head;
			   playlist->last_song = playlist->list->head;
			}

		else if(playlist->num_songs == 0){
			return;
		}

		else{
			play_song(playlist->last_song->next->data);
			playlist->last_song = playlist->last_song->next;
		}
	}


}

void play_previous(playlist_t* playlist) // TODO: play the previous song from the linked list
{
	song_t * p = playlist->last_song;
	if(playlist->last_song->prev == NULL){
        play_song(playlist->list->tail->data);
		playlist->last_song = playlist->list->tail;
	}

	else if(playlist->last_song == NULL){
		play_song(playlist->list->tail->data);
		playlist->last_song = playlist->list->tail;
	}

	else if (playlist->num_songs == 0){
		return;
	}

	else{
		play_song(playlist->last_song->prev->data);
		playlist->last_song = playlist->last_song->prev;
	}
}

void play_from_queue(music_queue_t* q) // TODO: play a song from the queue
{
	if(q == NULL){
		return;
	}

	else{
		play_song(q->front->data);
		q->front = q->front->next;
	}
}

void insert_to_queue(music_queue_t* q, int song_id) // TODO: insert a song id to the queue
{
	enqueue(q, song_id);
}

void reverse(playlist_t* playlist) // TODO: reverse the order of the songs in the given playlist. (Swap the nodes, not data)
{
    node_t * temp = NULL;
    node_t * current = playlist->list->head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        playlist->list->head = temp->prev; // The new head of the reversed list
    }

}

void k_swap(playlist_t* playlist, int k) // TODO: swap the node at position i with node at position i+k upto the point where i+k is less than the size of the linked list
{
	int i = 0;

    node_t * p = playlist->list->head;
	int count = 0;

	while(count != k){
		p = p->next;
		count = count + 1;
	}

	node_t * q = playlist->list->head;

	while((i+k) < playlist->list->size){
	   node_t * x = p;
	   node_t * y = q;
       int temp = q->data;
	   q->data = p->data;
	   p->data = temp;
	   p = p->next;
	   q = q->next;
	   i = i + 1; 

	   if (x == playlist->last_song){
		 playlist->last_song = p;
	   }

	   else if(y == playlist->last_song){
		 playlist->last_song = q;
	   }
	   
	}
}

void shuffle(playlist_t* playlist, int k) // TODO: perform k_swap and reverse
{
	k_swap(playlist, k);
	reverse(playlist);
}

song_t* debug(playlist_t* playlist) // TODO: if the given linked list has a cycle, return the start of the cycle, else return null. Check cycles only in forward direction i.e with the next pointer. No need to check for cycles in the backward pointer.
{
	node_t * slow = playlist->list->head;
    node_t * fast = playlist->list->head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow; // Cycle detected
        }
    }


}

void display_playlist(playlist_t* p) // Displays the playlist
{
	// DO NOT MODIFY!!!
	display_list(p->list);
}

void play_song(int song_id)
{
	// DO NOT MODIFY!!!
	printf("Playing: %d\n", song_id);
}

