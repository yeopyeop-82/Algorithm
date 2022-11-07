#include <stdio.h>

void BS(int s, int e, int k, int A[])
{
    if (s == e){
        if (A[s] == k){
            return s;
        }
        else {
            return -1;
        }
    }
    
    int m = (s + e) /2;

    if (A[m] == k) {
        return m;
    }
    else if (A[m] > k) {
        return BS(s, m-1, A, k);
    }
    else if (A[m] < k) {
        return BS(m + 1, e, A, k);
    }
}