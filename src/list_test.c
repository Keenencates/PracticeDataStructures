#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

void int_list();
void string_list();

bool iterate_int(void* data);
bool iterate_string(void* data);
void free_string(void* data);

int main(int argc, char* argv[]){
	int_list();
	string_list();
	return 0;
}

void int_list(){
	int nums = 10;
	printf("Creating a list with the first %d positive ints...\n", nums);

	int i;
	list list;
	list_new(&list, sizeof(int), NULL);

	for(i = 1; i <= nums; i++){
		list_append(&list, &i);
	}

	list_for_each(&list, iterate_int);

	list_destroy(&list);
	printf("Successfully freed %d numbers...\n", nums);
}

void string_list(){
	int num_strings = 5;
	const char *names[] = {"David", "Kevin", "Michael", "Craig", "Jimi"};

	int i;
	list list;
	list_new(&list, sizeof(char *), free_string);

	char* name;
	for(i=0; i<num_strings; i++){
		name = strdup(names[i]);
		list_append(&list, &name);
	}

	list_for_each(&list, iterate_string);

	list_destroy(&list);
	printf("Successfully freed %d strings...\n", num_strings);
}

bool iterate_int(void* data){
	printf("Found value: %d\n", *(int *)data);
	return TRUE;
}

bool iterate_string(void* data){
	printf("Found string value: %s\n", *(char **)data);
	return TRUE;
}

void free_string(void* data){
	free(*(char **)data);
}
