#include <iostream>

using namespace std;

int partition(int s, int e, int A[])
{
    int left = s + 1;
    int right = e;
    int pivot = A[s];

    while (left <= right) {
        while (A[left] <= pivot && left <= right) {
            left++;
        }
        while (A[right] >= pivot && left <= right) {
            right--;
        }

        if(left <= right) {
            swap (A[left], A[right]);
        }
    }
    swap(A[right], A[s]);
    return right;
}

int select(int s, int e, int k, int A[]) {

    if (s == e) {
        return A[s];
    }

    int m = partition(s, e, A);

    if (k == m) {
        return A[k];
    }

    if (k < m) {
        return select(s, m-1, k, A); // k 가 m 보다 작으면 left subset의 k번째 수
    }
    else if (k > m){
        return select(m + 1, e, k-m, A); // k 가 m보닫 크면 right subset의 k - m 번째 수
    }
}