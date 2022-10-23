#include <stdio.h>

void merge (int ls, int le, int rs, int re, int A[]) {
    int lptr = ls;
    int rptr = rs;
    int bptr = 0;
    int *B = (int *)calloc((le - ls) + (re - rs) + 2, sizeof(int));

    while (lptr <= le && rptr <= re) {
        if (A[lptr] < A[rptr]) {
            B[bptr++] = A[lptr++];
        }
        else {
            B[bptr++] = A[rptr++];
        }
    }

    if (lptr > le) {
        for (int i = rptr; i <= re; i++) {
            B[bptr++] = A[i];
        }
    }
    
    if (rptr > re) {
        for (int i = lptr; i <= le; i++) {
            B[bptr++] = A[i];
        }
    }
    
}

void msort(int s, int e, int A[])
{
    if (s == e)
        return; // 다 쪼갰다.
    
    int m = (s + e) / 2;
    msort(s, m, A);
    msort(m+1, e, A);
    merge(s, m, m+1, e, A);
}