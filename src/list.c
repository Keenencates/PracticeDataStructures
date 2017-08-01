#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "list.h"

void list_new(list* list, int element_size, free_function free_func){
	assert(element_size > 0);
	list->logical_length = 0;
	list->element_size = element_size;
	list->head = list->tail = NULL;
	list->free_func = free_func;
}

void list_destroy(list* list){
	list_node* current;
	while(list->head != NULL){
		current = list->head;
		list->head = current->next;

		if(list->free_func){
			list->free_func(current->data);
		}
	
		free(current->data);
		free(current);
	}
}

void list_prepend(list* list, void* element){
	list_node* node = malloc(sizeof(list_node));
	node->data = malloc(list->element_size);
	memcpy(node->data, element, list->element_size);

	node->next = list->head;
	list->head = node;

	if(!list->tail){
		list->tail = list->head;
	}
	list->logical_length++;
}

void list_append(list* list, void* element){
	list_node* node = malloc(sizeof(list_node));
	node->data = malloc(list->element_size);
	node->next = NULL;

	memcpy(node->data, element, list->element_size);

	if(list->logical_length == 0){
		list->head = list->tail = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}
	list->logical_length++;
}

void list_for_each(list* list, list_iterator iterator){
	assert(iterator != NULL);

	list_node* node = list->head;
	bool result = TRUE;
	while(node != NULL && result){
		result = iterator(node->data);
		node = node->next;
	}
}

void list_head(list* list, void* element, bool remove_from_list){
	assert(list->head != NULL);

	list_node* node = list->head;
	memcpy(element, node->data, list->element_size);

	if(remove_from_list){
		list->head = node->next;
		list->logical_length--;

		free(node->data);
		free(node);
	}
}

void list_tail(list* list, void* element){
	assert(list->tail != NULL);
	list_node* node = list->tail;
	memcpy(element, node->data, list->element_size);
}

int list_size(list* list){
	return list->logical_length;
}
