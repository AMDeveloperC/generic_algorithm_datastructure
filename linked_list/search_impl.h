# include "search.h"

int binary_search(int * work, int l, int r, int key) {
    if (l > r)
        return -1;
    else {
        int m = (l + r)/2;
        if (key == work[m])
            return work[m];
        if (key > work[m])
            return binary_search(work, m + 1, r, key);
        return binary_search(work, 0, m - 1, key);
    }
}

int linear_search(int * work, int l, int r, int key) {
    for (int i = l; i < r; i++) {
        if (key == work[i])
            return work[i];
    }
    return -1;
}
