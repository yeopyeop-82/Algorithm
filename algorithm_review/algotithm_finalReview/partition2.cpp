#include <iostream>

using namespace std;

int A[] = {1, 5, 4, 7, 3, 9, 10, 12, 11};

int partition(int s, int e, int A[])
{
    int left = s + 1, right = e;
    int pivot = A[s];
    
    while (left <= right) {
        while (left <= right && A[left] <= pivot) {
            left++;
        }
        while (left <= right && A[right] >= pivot) {
            right++;
        }
        if (left <= right)
            swap(A[left], A[right]);
    }
    swap(A[right], A[s]);

    return right;
}

void QS(int s, int e, int A[])
{
    if (s >= e) {
        return;
    }

    int m = partition(s, e, A);
    QS(s, m - 1, A);
    QS(m + 1, e, A);
}

int main(void)
{
    QS(0, 8, A);
    for (int i = 0; i < 9; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}