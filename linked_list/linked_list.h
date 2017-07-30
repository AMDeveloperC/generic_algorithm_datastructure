# include <stdlib.h>
# define SIZE 1024

typedef enum boolean{false, true} boolean;

typedef struct nodo {
    int val;
    struct nodo * next;
    struct nodo * prev;
} Nodo;

/* Create a new empty list */
Nodo ** create();

/* Add the element at first position of the list */
Nodo * addFirst(int, Nodo *);

/* Add the element at last position of the list */
Nodo * addLast(int, Nodo *);

/* Remove an element from the list */
void xremove(int, Nodo *);

/* Returns the size of the list */
int size(Nodo *);

/* Verify if the list is empty */
boolean isEmpty(Nodo *);

/* Check if malloc does not fail */
static void * xmalloc(int nbytes);
