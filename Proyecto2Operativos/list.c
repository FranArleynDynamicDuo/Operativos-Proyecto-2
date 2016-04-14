#include "core.h"

List_t NewList()
{
	List_t l = malloc(sizeof(List));
	
	l->size = 0;
	l->first = NULL;
	l->last = NULL;
	
	return l;
}

Node_t newNode(void* data)
{
	Node_t n = malloc(sizeof(Node));
	
	n->data = data;
	n->next = NULL;
}

void InsertNode(List_t l, void* data)
{
	if (!l->first)
	{
		l->first = newNode(data);
		l->last = l->first;
	}
	else
	{
		l->last->next = newNode(data);
		l->last = l->last->next;
	}
	l->size++;
}

void* GetData(List_t l, int index)
{
	Node_t aux = l->first;
	
	while (index-- > 0)
	{
		aux = aux->next;
	}
	return aux->data;
}

