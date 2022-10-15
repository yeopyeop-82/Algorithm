#include <iostream>

using namespace std;

// 배열을 정렬하지 않고도
// selection 부분 잘 알기

int partition(int s, int e, int A[]) {
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
        if (left <= right) {
            swap(A[left], A[right]);
        }
    }
    swap(A[right], A[s]);
    return right;
}

int selection (int s, int e, int A[], int k)
{
    if (s == e) {
        return A[s];
    }

    int m = partition(s, e, A);

    if (k == m) {
        return A[k];
    }
    else if (k < m) {
        return selection(s, m - 1, A, k);
    }
    else {
        return selection(m + 1, e, A, k - m);
    }

}

int main(void) {
    int A[] = {3, 6, 5, 7, 1, 2, 9, 4, 8};
    cout << selection(0, 9, A, 8);

}
