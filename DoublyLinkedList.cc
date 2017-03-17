#include <stdio.h>
#include <malloc.h>

typedef struct Node{
	int data;
	int key;
	struct Node *next;
	struct Node *prev;
}Node;

Node *head = NULL;
Node *last = NULL;

bool isEmpty()
{
	return head == NULL;
}

void displayNode(Node *ptr)
{
	if(ptr != NULL) printf(" (%d,%d) ", ptr->key, ptr->data);
	else printf(" Node is NULL");
}

// display from first to last
void displayForward()
{
	Node *ptr = head;
	while(ptr != NULL)
	{
		displayNode(ptr);
		ptr = ptr->next;
	}
	printf("\n");
}

// display from last to first
void displayBackward()
{
	Node *ptr = last;
	while(ptr != NULL)
	{
		displayNode(ptr);
		ptr = ptr->prev;
	}
	printf("\n");
}

// insert node at the first location
void insertFirst(int key, int data)
{
	Node *newnode = (Node *) malloc(sizeof(Node));
	newnode->data = data;
	newnode->key = key;
	newnode->next = NULL;
	newnode->prev = NULL;

	if(isEmpty()) last = newnode;
	else head->prev = newnode;

	newnode->next = head;
	head = newnode;
}

// insert node at the last location
void insertLast(int key, int data)
{
	Node *newnode = (Node *) malloc(sizeof(Node));
	newnode->data = data;
	newnode->key = key;
	newnode->next = NULL;
	newnode->prev = NULL;

	if(isEmpty()) head = newnode;
	else 
	{
		last->next = newnode;
		newnode->prev = last;
	}

	last = newnode;
}

Node *deleteFirst()
{
	Node *tmp = head;
	if(head->next == NULL) last = NULL;
	else head->next->prev = NULL;
	head = head->next;
	return tmp;
}

Node *deleteLast()
{
	Node *tmp = last;
	if(head->next == NULL) head = NULL;
	else last->prev->next = NULL;
	last = last->prev;
	return tmp;
}

Node *del(int key)
{
	if(head == NULL) return NULL;

	Node *current = head;
	Node *previous = NULL;

	while(current->key != key)
	{
		if(current->next == NULL) return NULL;
		else 
		{
			previous = current;
			current = current->next;
		}
	}

	if(current == head) head = head->next;
	else current->prev->next = current->next;

	if(current == last) last = current->prev;
	else current->next->prev = current->prev;

	return current;
}

bool insertAfter(int key, int newKey, int data)
{
	if(head == NULL) return false;

	Node *current = head;
	while(current->key != key)
	{
		if(current->next == NULL) return false;
		else current = current->next;
	}

	Node *newnode = (Node*) malloc(sizeof(Node));
	newnode->key = newKey;
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	if(current == last)
	{
		newnode->next = NULL;
		last = newnode;
	}
	else
	{
		newnode->next = current->next;
		current->next->prev = newnode;
	}

	newnode->prev = current;
	current->next = newnode;
	return true;
}

int main(int argc, char** argv)
{
	insertFirst(1, 100);
	insertFirst(2, 80);
	insertFirst(3, 120);
	insertFirst(4, 150);
	insertFirst(5, 90);
	insertLast(6, 200);
	insertLast(7, 600);
	displayForward();
	displayBackward();

	displayNode(deleteFirst());
	printf("\n");
	displayForward();

	displayNode(deleteLast());
	printf("\n");
	displayForward();

	displayNode(del(3));
	printf("\n");
	displayForward();

	if(insertAfter(6,8,211)) displayForward();
	else printf("\nInsert After Error");

	if(insertAfter(1,9,188)) displayForward();
	else printf("\nInsert After Error");

	return 0;
}
