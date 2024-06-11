#include <stdlib.h>

#include "scaffold_list.h"

scaffold_list* scaffold_list_insert(scaffold_list* list, void* new_data) {
	scaffold_list* new_elem = calloc(1, sizeof(scaffold_list));
	new_elem->data = new_data;
	new_elem->next = list;
	if (list != NULL) list->prev = new_elem;
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

