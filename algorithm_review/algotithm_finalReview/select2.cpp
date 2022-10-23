#include <iostream>

using namespace std;

int partition(int s, int e, int A[])
{
    int left = s + 1;
    int right = e;
    int pivot = A[s];

    while (left <= right) {
        while (A[right] >= pivot && left <= right) {
            right--;
        }

        while (A[left] <= pivot && left <= right) {
            left++;
        }
        
        if (left <= right) {
            swap(A[left], A[right]);
        }
    }
    swap(A[right], A[s]);
    return right;
}

int selectK(int s, int e, int k, int A[])
{
    if (s == e) {
        return A[s];
    }

    int m = partition (s, e, A);
    
    if (k > m) {
        return selectK(m + 1, e, k - m, A);
    }
    else if (k < m) {
        return selectK(s, m - 1, k , A);
    }
    else {
        return A[k];
    }
}