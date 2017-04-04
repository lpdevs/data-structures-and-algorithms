#include <stdio.h>
#include <malloc.h>

// constants here
#define ID_ROOT  1

// data structure 
struct _Node
{
	int id;
	struct _Node *child;
	struct _Node *next;
	struct _Node *previous;
	struct _Node *parent;
};
typedef _Node Node;

// Declaration
Node *root;
int maxDepth;

// apis
void init(Node *root, int id)
{
	root->id = id;
	root->child = 0;
	root->next = 0;
	root->previous = 0;
	root->parent = 0;
}

/*
* Find a node with a given id
*/
Node* find(Node *p, int id)
{
	if(p == 0) return 0;
	if(p->id == id) return p;

	Node *temp = find(p->child, id);
	if(temp == 0) temp = find(p->next, id);
	
	return temp;
}

/*
* Print tree information
*/
void printTree(Node *p)
{
	if(p == 0) return;
	printf("Node with id: %d\n", p->id);

	if(p->child != 0)
	{
		printf("Node %d has first child with id: %d\n", p->id, p->child->id);
		printTree(p->child);
	}

	Node *cur = p;
	while(cur->next != 0)
	{
		printf("Node %d has sibling node with id: %d\n", p->id, cur->next->id);
		printTree(cur->next);
		cur = cur->next;
	}
}

/**
* Tree traversal
*/
void traversalTree(Node *node)
{
	if(node == 0) return;
	printf("%d ", node->id);

	if(node->child != 0)
	{
		traversalTree(node->child);

		Node *cur = node->child;
		while(cur->next != 0)
		{
			traversalTree(cur->next);
			cur = cur->next;
		}
	}
}

/*
* Add a new node with 'id' to the node with 'pid'
*/
void add(int id, int pid)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	init(newNode, id);

	Node *node = find(root, pid);
	if(node->child == 0) 
	{
		node->child = newNode;
		newNode->parent = node;
	}
	else 
	{
		// Add to tail of list
		/*
		Node *p = node->child;
		while(p->next != 0) p = p->next;
		p->next = newNode;
		newNode->parent = node;
		newNode->previous = p;
		*/

		// Add to beginning of list
		newNode->next = node->child;
		node->child->previous = newNode;
		node->child = newNode;
		newNode->parent = node;
	}
}

/*
* Move existing node with 'id' to the node with 'pid'
*/
void move(int id, int pid)
{
	Node *nodeId = find(root, id);
	Node *nodePId = find(root, pid);

	// Update at nodeId side
	nodeId->previous->next = nodeId->next;
	nodeId->next->previous = nodeId->previous;

	// Update at nodePId side
	if(nodePId->child == 0) 
	{
		nodePId->child = nodeId;
		nodeId->parent = nodePId;
	}
	else 
	{
		// Add to beginning of list
		nodeId->next = nodePId->child;
		nodePId->child->previous = nodeId;
		nodePId->child = nodeId;
		nodeId->parent = nodePId;
	}
}

/*
* Remove the node with 'id' in tree.
*/
void remove(int id)
{
	Node *node = find(root, id);

	if(node->parent->child == node)
	{
		node->parent->child = node->next;
		node->next->previous = 0;
		node->parent = 0;
	}
	else
	{
		node->previous->next = node->next;
		node->next->previous = node->previous;
		node->parent = 0;
	}
}

/*
* Max depth/height of tree
*/
void getDepth(Node *node, int depth)
{
	if(node == 0)
	{
		if(depth > maxDepth) maxDepth = depth;
		return;
	}
	else
	{
		// compute the depth of each subtree
		Node *child = node->child;
		getDepth(child, depth + 1);

		if(child != 0)
		{
			Node *p = child;
			while (p->next != 0)
			{
				getDepth(p->next, depth + 1);
				p = p->next;
			}
		}
	}
}

int main()
{
	maxDepth = 0;
	root = (Node*) malloc(sizeof(Node));
	init(root, ID_ROOT);
	
	add(2, ID_ROOT); add(3, ID_ROOT); add(4, ID_ROOT);
	add(5, 2); add(6, 2);
	add(7, 6);
	add(8, 4); add(9, 4); add(10, 4);
	add(11, 9); add(12, 9);

	printf("--------get depth of tree----------\n\n");
	getDepth(root, 0);
	printf("depth of tree is: %d\n", maxDepth);

	printf("--------traversal tree-------------\n\n");
	traversalTree(root);
	
	printf("-------------Tree------------------\n\n");
	printTree(root);
	
	printf("--------Tree after move------------\n\n");
	move(9, 6);
	printTree(root);

	printf("--------Tree after remove----------\n\n");
	remove(3);
	printTree(root);
	
	printf("--------get depth of tree-----------\n\n");
	getDepth(root, 0);
	printf("depth of tree is: %d\n", maxDepth);

	printf("--------traversal tree-------------\n\n");
	traversalTree(root);

	return 0;
}
