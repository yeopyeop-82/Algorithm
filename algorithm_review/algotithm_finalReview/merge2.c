#include <stdio.h>
#include <stdlib.h>

int A[] = {1, 6, 4, 5, 3, 9};

void merge(int ls, int le, int rs, int re, int A[])
{
    int lptr = ls, rptr = re, bptr = 0;
    int *B = (int *)calloc((le - ls) + (re - rs) + 2, sizeof(int));

    while (lptr <= le && rptr <= re) {
        if (A[lptr] <= A[rptr]) {
            B[bptr++] = A[lptr++];
        }
        else {
            B[bptr++] = A[rptr++];
        }
    }

    for (int i = rptr; i <= re; i++) {
        B[bptr++] = A[i];
    }
}

void msort (int s, int e, int A[])
{
    if (s == e) {
        return;
    }
    
    int m = (s + e) / 2;

    msort(s, m, A);
    msort(m + 1, e, A);
    merge(s, m, m + 1, e, A);
}

int main(void)
{
    msort(0, 5, A);

    for (int i = 0; i < 6; i++){
        printf("%d ", A[i]);
    }

    return 0;
}