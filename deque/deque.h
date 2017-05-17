# define SIZE 1024


typedef enum boolean{false, true} boolean;

typedef struct node {
	int val;
	struct node * next;
	struct node * prev;
} Node;

/* Create a new empty list */
Node ** create();

/* Add the element at first position of the list */
Node * addFirst(int, Node *);

/* Add the element at last position of the list */
Node * addLast(int, Node *);

/* Remove the first element of the deque */
int removeFirst(Node *);

/* Remove the last element of the deque */
int removeLast(Node *);

/* Return the first element of the deque */
int getFirst(Node *);

/* Return the last element of the deque */
int getLast(Node *);

/* Returns the size of the list */
int size(Node *);

/* Verify if the list is empty */
boolean isEmpty(Node *);

/* Check if malloc does not fail */
static void * xmalloc(int nbytes);
