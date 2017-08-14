# include "stack.h"

/* Cancella ed inizializza lo stack */
void reset(stack * st) {
    st -> cnt = 0;
    st -> top = NULL;
}

/* Pone un valore sullo stack */
void push(char c, stack * st) {
    element * p = (element *) malloc(sizeof(element));
    p -> d = c;
    p -> next = st -> top;
    st -> top = p;
    st -> cnt++;
}

/* Recupera ed elimina un valore dalla cima dello stack */
char pop(stack * st) {
    char d;
    element * p;
    d = st -> top -> d;
    p = st -> top;
    st -> top = st -> top -> next;
    st -> cnt--;
    free(p);
    return d;
}

/* Restituisce il valore in cima allo stack */
char top(stack * st) {
    return (st -> top -> d);
}

/* Verifica se lo stack è vuoto */
boolean isEmpty(stack * st) {
    return (boolean) st -> cnt == EMPTY;
}

/* Verifica se lo stack è pieno */
boolean full(stack * st) {
    return (boolean) st -> cnt == FULL;
}

/* Restituisce il numero di elementi memorizzati nello stack */
int size(stack * st) {
    return st -> cnt;
}
