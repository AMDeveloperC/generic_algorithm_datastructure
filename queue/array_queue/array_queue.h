# define MAX_LEN 1000

typedef enum boolean{false, true} boolean;

/* Represents the ADT Queue */
typedef struct queue {
    void * q[MAX_LEN];
    int front;
    int rear;
} queue;

/* Check if the Queue is empty */
boolean isEmpty(queue * qu) {
    return qu -> front == qu -> rear;
}

/* chek if the Queue is full */
boolean full(queue * qu) {
    return qu -> rear == (MAX_LEN - 1);
}

/* Initialize the Queue */
void initialize(queue * qu) {
    qu -> front = 0;
    qu -> rear = 0;
}

/* Insert into the Queue */
void enqueue(void * d, queue * qu) {
    if (full(qu)) {
        fprintf(stderr, "Full queue\n");
        return;
    }
    qu -> q[qu -> rear] = d;
    qu -> rear = (qu -> rear + 1) % MAX_LEN;
}

/* Remove from the Queue */
void * dequeue(queue * qu) {
    if (isEmpty(qu)) {
        fprintf(stderr, "Empty queue\n");
        return NULL;
    }
    void * tmp = qu -> q[qu -> front];
    qu -> q[qu -> front] = NULL;
    qu -> front = (qu -> front + 1) % MAX_LEN;
    return tmp;
}

/* Return the front of the Queue */
void * front(queue * qu) {
    if (isEmpty(qu)) {
        fprintf(stderr, "Empty queue");
        return NULL;
    }
    return qu -> q[qu -> front];
}

/* Return the size of the Queue */
int size(queue * qu) {
    return (MAX_LEN + (qu -> front + qu -> rear)) % MAX_LEN;
}
