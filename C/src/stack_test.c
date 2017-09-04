#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void int_stack();

int main(int argc, char* argv[]){
	int_stack();
	return 0;
}

void int_stack(){
	int nums = 10;
	printf("Creating a stack with the first %d positive ints...\n", nums);

	int i = 1;
	stack stack;
	stack_new(&stack, sizeof(int), NULL);
	printf("Created the stack!\n\n");
	for(i = 1; i <= nums; i++){
		printf("Attempting to push onto the stack.\n");
		push(&stack, &i);
		printf("Pushed %d onto the stack.\n\n", i);
	}
	int top = 0;
	list_head(&stack.list, &top, FALSE);
	printf("Top of stack is %d\n", top);
	printf("Pushed %d elements onto the stack.\nNow attempting remove all the elements from the stack..\n\n", nums);

	int rv = 0; 
	while(nums > 0){
		printf("Attempting to pop from the stack.\n");
		pop(&stack, &rv);
		printf("Got %d from popping the stack.\n\n", rv);
		nums--;
	}
	stack_destroy(&stack);
}
