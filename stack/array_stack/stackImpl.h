# include "stack.h"

/* Cancella ed inizializza lo stack */
void reset(stack * st) {
    st -> top = EMPTY;
}

/* Pone un valore sullo stack */
void push(char c, stack * st) {
    st -> top++;
    st -> s[st -> top] = c;
}

/* Recupera ed elimina un valore dalla cima dello stack */
char pop(stack * st) {
    return st -> s[st -> top--];
}

/* Restituisce il valore in cima allo stack */
char top(stack * st) {
    return st -> s[st -> top];
}

/* Verifica se lo stack è vuoto */
boolean isEmpty(stack * st) {
    return ((boolean) (st -> top == EMPTY));
}

/* Verifica se lo stack è pieno */
boolean full(stack * st) {
    return ((boolean) (st -> top == FULL));
}

/* Restituisce il numero di elementi memorizzati nello stack */
int size(stack * st) {
    return st -> top + 1;
}
