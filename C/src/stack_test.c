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

	int i;
	stack stack;
	stack_new(&stack, sizeof(int), NULL);
	for(i = 1; i <= nums; i++){
		printf("Pushing %d on the stack.", i);
		push(&stack, &i);
	}
	
	int elem = 0;
	while(nums > 0){
		pop(&stack, &elem);
		printf("Got %d from popping the stack.", elem);
	}

	stack_destroy(&stack);
}
