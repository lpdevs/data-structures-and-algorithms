#include <stdio.h>
#include <malloc.h>

typedef struct Node{
	int data;
	int key;
	struct Node *next;
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

void displayList()
{
	if(head == NULL) return;
	Node *ptr = head;
	while(true)
	{
		displayNode(ptr);
		if(ptr == last) return;
		ptr = ptr->next;
	}
}

void insertFirst(int key, int data)
{
	Node *newnode = (Node*) malloc(sizeof(Node));
	newnode->data = data;
	newnode->key = key;
	newnode->next = NULL;

	if(isEmpty()) last = newnode;
	else newnode->next = head;
	
	head = newnode;
	last->next = head;
}

Node* deleteFirst()
{
	Node* tmp = head;

	if(head->next == head)
	{
		head = NULL;
		last = NULL;
		return tmp;
	}

	head = head->next;
	last->next = head;
	return tmp;
}

int main(int argc, char** argv)
{
	insertFirst(1, 4);
	insertFirst(3, 10);
	insertFirst(5, 20);
	displayList();
	printf("\n");
	deleteFirst();
	displayList();

	return 0;
}
