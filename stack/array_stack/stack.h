# define MAX_LEN 1000
# define EMPTY -1
# define FULL (MAX_LEN - 1)

typedef enum boolean{false, true} boolean;

typedef struct stack {
    char s[MAX_LEN];
    int top;
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
