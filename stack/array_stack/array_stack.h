# define MAX_LEN 100
# define EMPTY -1
# define FULL (MAX_LEN - 1)

typedef enum boolean{false, true} boolean;

/* Represents the ADT Stack */
typedef struct stack {
    void * s[MAX_LEN];
    int top;
} stack;

/* Check if the Stack is empty */
boolean isEmpty(stack * st) {
    return ((boolean) (st -> top == EMPTY));
}

/* Check if the Stack is full */
boolean full(stack * st) {
    return ((boolean) (st -> top == FULL));
}

/* Erase and initialize the Stack */
void reset(stack * st) {
    st -> top = EMPTY;
}

/* Insert a value on the top of stack */
void push(void * c, stack * st) {
    if (full(st)) {
        fprintf(stderr, "Stack full\n");
        return;
    }
    st -> top++;
    st -> s[st -> top] = c;
}

/* Remove and return the value on the top of the Stack */
void * pop(stack * st) {
    if (isEmpty(st)) {
        fprintf(stderr, "Stack empty\n");
        return NULL;
    }
    return st -> s[st -> top--];
}

/* Returns the top of the Stack */
void * top(stack * st) {
    if (isEmpty(st)) {
        fprintf(stderr, "Stack empty\n");
            return NULL;
    }
    return st -> s[st -> top];
}

/* Return the number of element into the Stack */
int size(stack * st) {
    return st -> top + 1;
}
