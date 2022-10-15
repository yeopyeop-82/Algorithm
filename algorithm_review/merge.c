#include <stdio.h>
#include <stdlib.h>

void merge (int ls, int le, int rs, int re, int A[])
{
    int lptr = ls, rptr = rs, bptr = 0; // merge 알고리즘은 두개의 인덱스를 가지고 탐색
    int *B = (int *)calloc((le - ls) + (re - rs)+ 2, sizeof(int)); // 원래 배열 사이즈만큼 B 생성
    // 주어진게 ls, le, rs, re 밖에 없으므로 이것을 가지고 원래 배열 크기를 만든다 ! !

    while (lptr <= le && rptr <= re) { // 하나라도 먼저 끝에 도달하면 종료
        if (A[lptr] < A[rptr]) {
            B[bptr++] = A[lptr++];
        }
        else {
            B[bptr++] = A[rptr++];
        }
    }

    if (lptr > le) {
        for (int i = rptr; i < re; i++){
            B[bptr++] = A[i];
        }
    }
    else if (rptr > re) {
        for (int i = lptr; i < le; i++) {
            B[bptr++] = A[i];
        }
    }

    
}

void msort(int s, int e, int A[])
{
    if (s == e) {
        return;
    }

    int m = (s + e)/ 2;
    msort(s, m, A);
    msort(m + 1, e, A); // 배열을 쪼갠다 !! s == e일때까지

    merge(s, m, m+1, e, A); // 다 쪼갰으면 ls, le, rs, re, A 전달 !!!!
}

int main(void)
{
    int A[] = {4, 7, 3, 10, 8, 5, 1, 2, 9, 6};

    msort(0, 9, A);

    for (int i = 0; i < 10; i++) {
        printf("%d", A[i]);
    }

    return 0;
}
