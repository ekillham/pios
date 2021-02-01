#include <stdio.h>
#include <stdlib.h>
#include "list.h"

//Source: https://www.geeksforgeeks.org/generic-linked-list-in-c-2/?ref=lbp

void list_add (struct list_element** head, int new_data) 
{
 struct list_element* new_node = (struct list_element*) malloc(sizeof(struct list_element*));

 new_node->data = new_data;

 new_node->next = (*head);

 (*head) = new_node;
 
}

//Reference: https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
void list_remove(struct list_element** head, int key) 
{
 	struct list_element* temp = head, *prev;

	if (temp != NULL && temp->data == key)
 	{
 		head = temp->next;
 		free(temp);
 		return;
 	}

 	while ( temp != NULL && temp->data != key)
 	{
 		prev = temp;
 		temp = temp->next;
 	}

 	if  (temp == NULL) return;

 	prev->next = temp->next;

 	free(temp);
}
