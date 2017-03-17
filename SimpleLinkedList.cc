#include <stdio.h>
#include <malloc.h>

typedef struct Node{
	int data;
	int key;
	struct Node *next;
}Node;

Node *head = NULL;
int length = 0;

// display node
void printNode(Node *node)
{
	if(node != NULL) printf(" (%d, %d) ", node->key, node->data);
	else printf("Node is NULL\n");
}

// display the list
void printList()
{
	Node *ptr = head;
	while(ptr != NULL)
	{
		printNode(ptr);
		ptr = ptr->next;
	}
	printf("\n");
}

// insert link at the first location
void insertFirst(int key, int data)
{
	Node* newnode = (Node*) malloc(sizeof(Node));
	newnode->key = key;
	newnode->data = data;

	newnode->next = head;
	head = newnode;

	length++;
}

// delete first node
Node* deleteFirst()
{
	Node* temp = head;
	head = head->next;

	length--;

	return temp;
}

// check list empty
bool isEmpty()
{
	return head == NULL;
}

// find a node with given key
Node* find(int key)
{
	if(head == NULL) return NULL;

	Node *ptr = head;
	while(ptr != NULL && ptr->key != key)
		ptr = ptr->next;

	return ptr;
}

// delete a node with given key
Node* del(int key)
{
	if(head == NULL) return NULL;

	Node* current = head;
	Node* previous = NULL;

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
	else previous->next = current->next;

	return current;
}

void sort()
{
	if(head == NULL || head->next == NULL) return;
	
	Node *sorted_head = NULL;
	Node *ptr = head;
	while(ptr != NULL)
	{
		Node *current = ptr;
		ptr = ptr->next;

		// insert current element into proper position in sorted_head linked list.
		if(sorted_head == NULL || current->data <= sorted_head->data)
		{
			current->next = sorted_head;
			sorted_head = current;
		}
		else
		{
			Node *p = sorted_head;
			while(p != NULL)
			{
				if(p->next == NULL || current->data < p->next->data)
				{
					current->next = p->next;
					p->next = current;
					break;
				}
				p = p->next;
			}
		}
	}
	head = sorted_head;
}

void reverse()
{
	Node *prev = NULL;
	Node *current = head;
	Node *next = NULL;

	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

int main(int argc, char** argv)
{
	insertFirst(1, 150);
	insertFirst(2, 15);
	insertFirst(3, 30);
	insertFirst(4, 100);
	insertFirst(5, 70);
	printList();
	sort();
	printList();
	reverse();
	printList();

	printNode(deleteFirst());
	printf("\n");
	printList();

	printNode(find(6));

	printNode(del(2));
	printf("\n");
	printList();


	return 0;
}
