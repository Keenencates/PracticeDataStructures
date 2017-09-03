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
	int elem = 0;
	stack stack;
	stack_new(&stack, sizeof(int), NULL);
	printf("Created the stack!\n\n");
	for(i = 1; i <= nums; i++){
		elem = i;
		printf("Attempting to push onto the stack.\n");
		push(&stack, &elem);
		printf("Pushed %d onto the stack.\n\n", elem);
	}

	printf("Pushed %d elements onto the stack.\nNow attempting remove all the elements from the stack..\n\n", nums);

	int* rv = malloc(sizeof(int));
	*rv = 0; 
	while(nums > 0){
		printf("Attempting to pop from the stack.\n");
		pop(&stack, &rv);
		printf("Got %d from popping the stack.\n\n", *rv);
		nums--;
	}
	free(rv);

	stack_destroy(&stack);
}
