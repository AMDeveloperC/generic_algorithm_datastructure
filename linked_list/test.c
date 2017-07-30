# include <stdio.h>
# include <time.h>
# include "linked_list_impl.h"


/* here you can add other test to be sure of correctness of the code */
int main(void) {
    srand(time(NULL));
    int size = 10 + (rand() % 30);
    int a[size];
    int i;

    for (i = 0; i < size; i++) {
        a[i] = 1 + (rand() % 80);
    }

    printf("Size of array to sort: %d\n", size);
    printf("\n\n\nHere there is the array to sort: \n");
    printArray(a, size);

    insertion_sort(a, size, descending); // you can change the comparing function to state the ordering toward

    printf("\n\n\nHere there is the sorted array: \n");
    printArray(a, size);

    return 0;
}
