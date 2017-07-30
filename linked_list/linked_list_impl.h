# include "linked_list.h"
# include "sort_impl.h"

/* create a new empty list */
Nodo ** create() {
    Nodo ** ht = xmalloc(2 * sizeof(Nodo *));

    ht[0] = xmalloc(sizeof(Nodo *)); // header
    ht[1] = xmalloc(sizeof(Nodo *)); // trailer

    /* link nodes */
    ht[0] -> next = ht[1];
    ht[0] -> val = 0;
    ht[1] -> val = 0;
    ht[1] -> prev = ht[0];
    ht[1] -> next = NULL;

    return ht;
}

/* add the element at first position of the list */
Nodo * addFirst(int val, Nodo * header) {
    Nodo * newNode = xmalloc(sizeof(Nodo *));
    newNode -> val = val;

    /* link nodes */
    Nodo * app = header -> next;
    newNode -> next = app;
    newNode -> prev = header;
    header -> next = newNode;
    app -> prev = newNode;

    return newNode;
}

/* add the element at last position of the list */
Nodo * addLast(int val, Nodo * trailer) {
    Nodo * newNode = xmalloc(sizeof(Nodo *));
    newNode -> val = val;

    /* link nodes */
    Nodo * app = trailer -> prev;
    newNode -> prev = app;
    newNode -> next = trailer;
    trailer -> prev = newNode;
    app -> next = newNode;

    return newNode;
}

/* returns the size of the list */
int size(Nodo * list) {
    Nodo * app = list -> next;
    int c = 0;

    while(app -> next != NULL) {
        c++;
        app = app -> next;
    }

    return c;
}

/* remove an element from the list */
void xremove(int val, Nodo * list) {
    int flag = 0;
    Nodo * app = list -> next;

    while (app -> next != NULL) {
        if (app -> val == val) {
            flag = 1;
            break;
        }
        app = app -> next;
    }
    if (flag > 0) {
        Nodo * prev = app -> prev;
        Nodo * next = app -> next;
        prev -> next = next;
        next -> prev = prev;
        free(app);
    }
}

/* verify if the list is empty */
boolean isEmpty(Nodo * list) {
    return size(list) == 0;
}

/* print the content of specified array */
void printArray(int * vect, int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d\n", vect[i]);
}

/* convert a list in a array */
int * listToArray(Nodo * list) {
    int i = 0;
    int dim = size(list);
    Nodo * app = list -> next;
    int * vect = (int *) malloc(dim * sizeof(int));

    while(app -> next != NULL) {
        vect[i++] = app -> val;
        app = app -> next;
    }

    return vect;
}

/* check if malloc is return correct value */
static void * xmalloc(int nbytes) {
    void * result;
    if((result = malloc(nbytes)) == NULL) {
        fprintf(stderr, "malloc(%d) failed. Exiting.\n", nbytes);
        exit(-1);
    }
    return result;
}

/* sort the list */
void sortList(Nodo ** list) {
    int * vect = listToArray(list[0]);
    int dim = size(list[0]);
    int i;

    selection_sort(vect, dim, ascending);
    free(list);
    list = create();

    for (i = 0; i < dim; i++) {
        addLast(vect[i], list[1]);
    }
}
