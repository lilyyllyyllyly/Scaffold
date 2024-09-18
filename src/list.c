#include <stdio.h>
#include <stdlib.h>

#include "scaffold_list.h"

scaffold_list* scaffold_list_insert(scaffold_list* list, void* new_data) {
	scaffold_list* new_elem = calloc(1, sizeof(scaffold_list));

	new_elem->data = new_data;
	new_elem->next = list;

	if (list != NULL) {
		if (list->prev != NULL) {
			new_elem->prev = list->prev;
			list->prev->next = new_elem;
		}
		list->prev = new_elem;
	}

	return new_elem;
}

scaffold_list* scaffold_list_append(scaffold_list* list, void* new_data) {
	if (list == NULL) {
		return NULL; // for append list cant be null, insert must be called instead
	}

	scaffold_list* new_elem = calloc(1, sizeof(scaffold_list));

	new_elem->data = new_data;
	new_elem->prev = list;

	if (list->next != NULL) {
		list->next->prev = new_elem;
		new_elem->next = list->next;
	}

	list->next = new_elem;

	return new_elem;
}

scaffold_list* scaffold_list_delete_element(scaffold_list* list, scaffold_list* element) {
	if (element->next != NULL) element->next->prev = element->prev;
	if (element->prev != NULL) element->prev->next = element->next;
	else list = element->next;

	free(element);
	return list;
}

void scaffold_list_destroy(scaffold_list* list) {
	scaffold_list* curr = list;
	while (curr != NULL) {
		scaffold_list* next = curr->next;
		free(curr);
		curr = next;
	}
}

void scaffold_list_debug(scaffold_list* list) {
	printf("DEBUG: printing scaffold list %p contents\n", (void*)list);
	for (scaffold_list* elem = list; elem != NULL; elem = elem->next) {
		printf("DEBUG: elem %p - prev: %p | next: %p\n", (void*)elem, (void*)(elem->prev), (void*)(elem->next));
	}
}

