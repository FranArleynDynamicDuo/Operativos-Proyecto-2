#ifndef LIST_H
#define LIST_H


struct list
{
	int size;
	struct node* first;
	struct node* last;
};

struct node
{
	void* data;
	struct node* next;
};

typedef struct list List;
typedef List* List_t;

typedef struct node Node;
typedef Node* Node_t;

List_t NewList();
Node_t NewNode(void*);

void InsertNode(List_t, void*);
void* GetData(List_t, int);


#endif