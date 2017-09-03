#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "stack.h"
#include "list.h"

void stack_new(stack* stack, int element_size, free_function free_func){
	list lst;
	stack->list = &lst;
	list_new(stack->list, element_size, free_func);
}

void pop(stack* stack, void* element){
	assert(stack->list->logical_length > 0);
	list_head(stack->list, &element, TRUE);
}

void push(stack* stack, void* element){
	list_prepend(stack->list, &element);
	printf("stack: was able to push\n");
}

void stack_destroy(stack* stack){
	list_destroy(stack->list);
}