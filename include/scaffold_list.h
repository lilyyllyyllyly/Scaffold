#pragma once

typedef struct scaffold_list {
	void* data;
	struct scaffold_list* next;
	struct scaffold_list* prev;
} scaffold_list;

scaffold_list* scaffold_list_insert(scaffold_list* list, void* new_elem);
scaffold_list* scaffold_list_append(scaffold_list* list, void* new_elem);
scaffold_list* scaffold_list_delete_element(scaffold_list* list, scaffold_list* element);
void scaffold_list_destroy(scaffold_list* list);

