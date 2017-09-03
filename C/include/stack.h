#ifndef __STACK_H
#define __STACK_H

#include "list.h"

typedef struct {
	list list;
} stack;

void stack_new(stack* stack, int element_size, free_function free_func);
void push(stack* stack, void* element);
void pop(stack* stack, void* element);
void stack_destroy(stack* stack);

#endif
