#include <stdio.h>

int binary_search(int s, int e, int A[], int x)
{
    if (s == e) {
        if (A[s] == x) {
            return s;
        }
        else {
            return -1;
        }
    }

    int m = (s + e) / 2;

    if (A[m] == x) {
        return m;
    }
    else if (A[m] > x) {
        binary_search(s, m - 1, A, x); // m - 1 까먹지 말기 !!
    }
    else {
        binary_search(m + 1, e, A, x);
    }
}