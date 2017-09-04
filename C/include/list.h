#ifndef __LIST_H
#define __LIST_H

typedef void (*free_function)(void *);

typedef enum {FALSE, TRUE} bool;

typedef bool (*list_iterator)(void *);

typedef struct _list_node{
	void *data;
	struct _list_node *next;
	struct _list_node *prev;
} list_node;

typedef struct {
	int logical_length;
	int element_size;
	list_node* head;
	list_node* tail;
	free_function free_func;
} list;

void list_new(list* list, int element_size, free_function free_func);
void list_destroy(list* list);

void list_prepend(list* list, void* element);
void list_append(list* list, void* element);
int list_size(list* list);

void list_for_each(list* list, list_iterator iterator);
void list_head(list* list, void* element, bool remove_from_list);
void list_tail(list* list, void* element);

#endif
