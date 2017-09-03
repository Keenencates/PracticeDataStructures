#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

void int_list();
void string_list();

bool iterate_int(void* data);
bool iterate_string(void* data);
void free_string(void* data);
void find_mth_last(list* list, void* element, int m);

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

	int result = 0;
	find_mth_last(&list, &result, 3);
        printf("The 3rd to last number in the list is: %d\n", result);
	
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

void find_mth_last(list* list, void* element, int m){
	list_node* mth_ptr = list->head;
	list_node* curr = list->head;
	int cnt = 0;
	while(curr->next != NULL){
		if(cnt < m){
			cnt++;
		}else{
			mth_ptr = mth_ptr->next;
		}
		curr = curr->next;
	}
	memcpy(element, mth_ptr->data, list->element_size);
}

