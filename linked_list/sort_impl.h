# include "sorting.h"

/* swap the content of elem1 and elem2 variables */
static void swap(int * elem1, int * elem2) {
    int hold;

    hold = * elem1;
    * elem1 = * elem2;
    * elem2 = hold;
}

/* selection sort implementation */
void selection_sort(int * work, const int size, int (* compare)(const void * a, const void * b)) {
    int index;
    int i, j;

    for (i = 0; i < size; i++) {
        index = i;
        for (j =i + 1; j < size; j++) {
            if((*compare)(&work[index], &work[j]) > 0)
                index = j;
        }
        swap(&work[i], &work[index]);
    }
}

/* buble sort implementation */
void bubble_sort(int * work, const int size, int (* compare)(const void * a, const void * b)) {
    int i;
    int j;

    for(i = 1; i < size; i++) {
        for(j = 0; j < size - 1; j++) {
            if((*compare)(&work[j], &work[j + 1]) > 0)
                swap(&work[j], &work[j + 1]);
        }
    }
}

/* oredered insertion for insertion sort implementation */
static void ordered_insertion(int * work, int k, int v, int (* compare)(const void * a, const void * b)) {
    k--;
    while (k >= 0 && (* compare)(&work[k], &v) > 0) {
        work[k+1] = work[k];
        k--;
    }
    work[k + 1] = v;
}

/* insertion sort implementation */
void insertion_sort(int * work, const int size, int (* compare)(const void * a, const void * b)) {
    int i;
    for (i = 1; i < size; i++)
        ordered_insertion(work, i, work[i], compare);
}

/* counting Sort algorithm */
void counting_sort(int * work, const int size, int (* compare)(const void * a, const void * b)) {
    return;
}

/* compare function to states the ordering thoward */
static int descending(const void * a, const void * b) {
    return (* (int *)b - * (int *)a);
}
static int ascending(const void * a, const void * b) {
    return (* (int *)a - * (int *)b);
}
