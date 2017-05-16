# include "sorting.h"


/* Swap the content of elem1 and elem2 variables */
static void swap(int * elem1, int * elem2) {
	int hold;

	hold = * elem1;
	* elem1 = * elem2;
	* elem2 = hold;
}


/* Implements Selection Sort */
void SelectionSort(int * work, const int size, int (* compare)(const void * a, const void * b)) {
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


/* Implements Buble Sort */
void BubbleSort(int * work, const int size, int (* compare)(const void * a, const void * b)) {
	int i;
	int j;

	for(i = 1; i < size; i++) {
		for(j = 0; j < size - 1; j++) {
			if((*compare)(&work[j], &work[j + 1]) > 0)
				swap(&work[j], &work[j + 1]);
		}
	}
}


/* This couple of function is useful to set up the sorting */
static int descending(const void * a, const void * b) {
	return (* (int *)b - * (int *)a);
}
static int ascending(const void * a, const void * b) {
	return (* (int *)a - * (int *)b);
}