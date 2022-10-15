#include <iostream>
#include <stdlib.h>

using namespace std;

int partition (int s, int e, int A[]) {
    int left = s + 1, right = e;
    int pivot = A[s];

    while (left <= right) {
        while (A[left] <= pivot && left <= right) {
            left++;
        }
        while (A[right] >= pivot && left <= right) {
            right--;
        }
        
        if (left <= right)
            swap(A[left], A[right]);
    }
    
    swap(A[right], A[s]);
    
    return right;
}

void quick_sort (int s, int e, int A[]) {

    if (s >= e) {
        return;
    }

    int m = partition(s, e, A);

    quick_sort(s, m - 1, A);
    quick_sort(m + 1, e, A);

}

int main(void) {
    int A[] = {3, 5, 7, 9, 1, 2, 4, 8};
    quick_sort(0, 7, A);

    for (int i = 0; i < 8; i++) {
        cout << A[i];
    }

    return 0;
}