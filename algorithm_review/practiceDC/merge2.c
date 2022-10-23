#include <stdio.h>
#include <stdlib.h>

void merge(int ls, int le, int rs, int re, int A[]) {
    int lptr = ls, rptr = rs, bptr = 0;
    int i, j;
    int *B = (int*) calloc (((le - ls) + (re - rs) + 2), sizeof(int));

    while (lptr <= le && rptr <= re) {
        if (A[lptr] < A[rptr]) {
            B[bptr++] = A[lptr++];
        }
        else {
            B[bptr++] = A[lptr++];
        }
    }
    if (lptr > le) {
        for (i = rptr; i <= re; i++) {
            B[bptr++] = A[i];
        }
    }
    if (rptr > re) {
        for (i = lptr; i <= le; i++) {
            B[bptr++] = A[i];
        }
    }

    // A <- B
    for (i = ls; i <= re; i++) {
        A[i] = B[i];
    }
}

void msort(int s, int e, int A[]) {
    if (s == e) {
        return;
    }

    int m = (s + e) / 2;

    msort(s, m, A);
    msort(m + 1, e, A);
    merge(s, m, m+1, e, A);
}

int main(void)
{
    int A[] = {1, 5, 7, 4, 2, 3, 9, 8};

    msort(0, 7, A);

    for (int i = 0; i < 8; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}