#include <stdio.h>

int binary_search (int s, int e, int A[], int x)
{
    int m = (s + e)/ 2;

    if (s == e) {
        if(A[s] == x)
            return s;
        else
            return NULL;
    }
    else {
        binary_search(s, m - 1, A, x);
        binary_search(m + 1, e, A, x);
    }
}
