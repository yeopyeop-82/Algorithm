#include <iostream>

using namespace std;

int partition (int s, int e, int A[]) {
    int left = s + 1;
    int right = e;
    int pivot = A[s];

    while (left <= right) {
        while ((A[left] <= pivot) && (left <= right)) {
            left++;
        }
        while ((A[right] >= pivot) && (left <= right)) {
            right--;
        }
        if (left <= right) {
            swap(A[left], A[right]);
        }
    }
    swap(A[right], A[s]);
    return right;
}

void quick_sort (int s, int e, int A[]) 
{
    if (s >= e) {
        return;
    }

    int m = partition(s, e, A);

    quick_sort(s, m - 1, A);
    quick_sort(m + 1, e, A);
}

int main()
{
    int A[] = {1, 7, 4, 6, 2, 5};
    quick_sort(0, 5, A);

    for (int i = 0; i < 6; i++){
        cout << A[i];
    }

    return 0;
}