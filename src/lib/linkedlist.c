#include "linkedlist.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

void list_new(list *list, int elementSize, freeFunction freeFn)
{
	assert(elementSize > 0);
	list->elementSize = elementSize;
	list->freeFn = freeFn;
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
}

void list_destroy(list *list)
{
	listNode *current = list->head;

	while(current != NULL)
	{
		current = list->head;
		list->head = current->next;

		if(list->freeFn)
		{
			list->freeFn(current->data);
		}

		free(current->data);
		free(current);
	}
}

void list_prepend(list *list, void *element)
{
	listNode *node = malloc(sizeof(listNode));
	node->data = malloc((unsigned long)(list->elementSize));
	node->next = NULL;

	memcpy(node->data, element, list->elementSize);

	node->next = list->head;
	list->head = node;

	if(!list->tail)
	{
		list->tail = list->head;
	}

	list->length++;
}

void list_append(list *list, void *element)
{
	listNode *node = malloc(sizeof(listNode));
	node->data = malloc((unsigned long)(list->elementSize));
	node->next = NULL;

	memcpy(node->data, element, list->elementSize);

	if(list->length == 0)
	{
		list->head = list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->length++;
}

int list_size(list *list)
{
	return list->length;
}

void list_for_each(list *list, listIterator iterator)
{
	assert(iterator != NULL);
	printf("Entered foreach\n");
	listNode *node = list->head;
	bool result = true;
	while(node != NULL && result) {
		printf("Looping\n");
		fflush(stdin);
		result = iterator(node->data);
		node = node->next;
	}
}

void list_head(list *list, void *element, bool removeFromList)
{
	assert(list->head != NULL);

	listNode *node = list->head;
	memcpy(element, node->data, list->elementSize);

	if(removeFromList) {
		list->head = node->next;
		list->length--;

		free(node->data);
		free(node);
	}
}

void list_tail(list *list, void *element)
{
	assert(list->tail != NULL);
	listNode *node = list->tail;
	memcpy(element, node->data, list->elementSize);
}
