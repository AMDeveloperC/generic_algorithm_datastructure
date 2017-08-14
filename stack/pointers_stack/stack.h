# define EMPTY 0
# define FULL 100000

typedef enum boolean{false, true} boolean;

typedef struct element {
    char d;
    struct element * next;
} element;

typedef struct stack {
    int cnt;
    element * top;
} stack;

/* Cancella ed inizializza lo stack */
void reset(stack * st);

/* Pone un valore sullo stack */
void push(char c, stack * st);

/* Recupera ed elimina un valore dalla cima dello stack */
char pop(stack * st);

/* Restituisce il valore in cima allo stack */
char top(stack * st);

/* Verifica se lo stack è vuoto */
boolean isEmpty(stack * st);

/* Verifica se lo stack è pieno */
boolean full(stack * st);

/* Restituisce il numero di elementi memorizzati nello stack */
int size(stack * st);
