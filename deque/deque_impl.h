# include "linked_list.h"


/* Create a new empty list */
Node ** create() {
	Node ** ht = xmalloc(2 * sizeof(Node *));

	ht[0] = xmalloc(sizeof(Node *)); // header
	ht[1] = xmalloc(sizeof(Node *)); // trailer

	/* Link nodes */
	ht[0] -> next = ht[1];
	ht[0] -> val = 0;
	ht[1] -> val = 0;
	ht[1] -> prev = ht[0];
	ht[1] -> next = NULL;

	return ht;
}

/* Add the element at first position of the list */
Node * addFirst(int val, Node * header) {
	Node * newNode = xmalloc(sizeof(Node *));
	newNode -> val = val;

	/* Link nodes */
	Node * app = header -> next;
	newNode -> next = app;
	newNode -> prev = header;
	header -> next = newNode;
	app -> prev = newNode;

	return newNode;
}

/* Add the element at last position of the list */
Node * addLast(int val, Node * trailer) {
	Node * newNode = xmalloc(sizeof(Node *));
	newNode -> val = val;

	/* Link nodes */
	Node * app = trailer -> prev;
	newNode -> prev = app;
	newNode -> next = trailer;
	trailer -> prev = newNode;
	app -> next = newNode;

	return newNode;
}

/* Returns the size of the list */
int size(Node * list) {
	Node * app = list -> next;
	int c = 0;

	while(app -> next != NULL) {
		c++;
		app = app -> next;
	}

	return c;
}


/* Remove the first element of the deque */
int removeFirst(Node * header) {
	int value = header -> next -> val;

	Node * toDelete = header -> next;
	header -> next = toDelete -> next;
	toDelete -> next -> prev = header;
	free(toDelete);

	return value;
}

/* Remove the last element of the deque */
int removeLast(Node * trailer) {
	int value = trailer -> prev -> val;

	Node * toDelete = trailer -> prev;
	trailer -> prev = toDelete -> prev;
	toDelete -> prev -> next = trailer;
	free(toDelete);

	return value;
}

/* Return the first element of the deque */
int getFirst(Node * header) {
	return header -> next -> val;
}

/* Return the last element of the deque */
int getLast(Node * trailer) {
	return trailer -> prev -> val;
}

/* Convert a list in a array */
int * listToArray(Node * list) {
	int i = 0;
	int dim = size(list);
	Node * app = list -> next;
	int * vect = (int *) malloc(dim * sizeof(int));

	while(app -> next != NULL) {
		vect[i++] = app -> val;
		app = app -> next;
	}

	return vect;
}

/* Check if malloc is return correct value */
static void * xmalloc(int nbytes) {
	void * result;
	if((result = malloc(nbytes)) == NULL) {
		fprintf(stderr, "malloc(%d) failed. Exiting.\n", nbytes);
		exit(-1);
	}
	return result;
}
