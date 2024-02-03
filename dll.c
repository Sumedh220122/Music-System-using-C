#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t * p = (node_t*)malloc(sizeof(node_t));

	if(list->size == 0){
		p->data = data;
		p->next = NULL;
		p->prev = NULL;
		list->head = p;
		list->tail = p;
		list->size += 1;
	}

	else{
		p -> data = data;
		p -> next = list -> head;
		p ->prev = NULL;
		list->head->prev = p;
		list->head = p;
		list->size += 1;
	}

}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t * p = (node_t*)malloc(sizeof(node_t));
	if(list->size == 0){
		p->data = data;
		p->next = NULL;
		p->prev = NULL;
		list->head = p;
		list->tail = p;
		list->size += 1;
	}

	else{
		p -> data = data;
		p -> next = NULL;
		p ->prev = list->tail;
		list->tail->next = p;
		list->tail = p;
		list->size += 1;
	}

}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t * p = (node_t*)malloc(sizeof(node_t));
	node_t * q = (node_t*)malloc(sizeof(node_t));

	p = list->head;
	q = p->next;

	while(p->data != prev && q != NULL){
        p = p->next;
		q = q->next;
	}

	if(q == NULL && p->data != prev){
		return;
	}

	else if(q == NULL && p->data == prev){
		insert_back(list, data);
	}

	else{
		node_t * temp = (node_t*)malloc(sizeof(node_t));
		temp->data = data;
		temp->next = q;
		q->prev = temp;
		temp->prev = p;
		p->next = temp;

		list->size += 1;
	}


}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	if(list->size == 0){
        return;
	}

	node_t * p = (node_t*)malloc(sizeof(node_t));
	p = list->head;
	list->head = p->next;
	list->head->prev = NULL;
	p->next = NULL;
	free(p); 

	list->size -= 1;
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
	if(list->size == 0){
        return;
	}

	node_t * p = list->tail;
	list->tail = list->tail->prev;
    free(p);

	list->size -= 1;
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	node_t * p = list->head;
	node_t * q = list->head->next;

	if(p->data == data){
		delete_front(list);
	}

	else{

		while(q->data != data && q != NULL){
			q = q->next;
			p = p->next;
		}

		if(q == NULL && p->data != data){
			return;
		}
		
		else if(q == NULL && p->data == data){
			delete_back(list);
		}

		else{
			node_t * temp = (node_t*)malloc(sizeof(node_t));
			temp = q;
			q = q->next;
			p->next = q;
			q->prev = p;
			free(temp);

			list->size -= 1;
		}

	}


}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{	
	node_t * p = list->head;
    
	while(p != NULL && p->data != data){
		p = p->next;
	}

	return p;

}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

