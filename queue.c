#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue_t* create_queue()   // return a newly created empty queue
{
	// DO NOT MODIFY!!!
	queue_t* Q = (queue_t*) malloc(sizeof(queue_t));
	Q->list = create_list();
	Q->front = Q->list->head;
	Q->rear = Q->list->tail;
	Q->size = Q->list->size;
	return Q;
}

void enqueue(queue_t* q, int data) // TODO: insert data at the end of a queue
{
	if(q ->size == 0){
		node_t * temp = (node_t*)malloc(sizeof(node_t));
		temp->data = data;
		q->front = temp;
		q->rear = temp;
		q->size += 1;
	}

	else{
		node_t * p = q->rear;
        node_t * temp = (node_t*)malloc(sizeof(node_t));
		temp->data = data;
		p->next = temp;
		temp->prev = p;
		temp->next = NULL;
		q->rear = temp;

		q->size += 1; 
	}
}

int dequeue(queue_t* q) 	// TODO: return the data at the front of a queue and remove it. Return -1 if queue is empty
{
	int val;

    if(q == NULL){
		return -1;
	 }
     
	else{
		node_t * p = q->front;
		q->front = p->next;
		val = p->data;
		free(p);
		q->size -= 1;
	 }

	 return val;
}

int front(queue_t* q) // TODO: return the data at the front of a queue. Return -1 if queue is empty
{
	return q->front->data;
}

int empty(queue_t* q) // return if the queue is empty
{
	// DO NOT MODIFY!!!
	return is_empty(q->list);
}

int queue_size(queue_t* q) // returns the number of elements in the queue
{
	// DO NOT MODIFY!!!
	return q->size;
}

void delete_queue(queue_t* q) // empty the contents of the queue
{
	// DO NOT MODIFY!!!
	delete_list(q->list);
	free(q);
}
