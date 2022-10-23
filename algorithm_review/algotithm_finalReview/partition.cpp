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

void quick_sort(int s, int e, int A[]) {

    if (s >= e)
        return;
    
    int m = partition(s, e, A);
    quick_sort(s, m - 1, A);
    for (int i = 0; i< 8; i++) {
        printf("%d ", A[i]);
    }
    cout << "\n";
    quick_sort(m + 1, e, A);

    // conquer가 필요없는 알고리즘이므로 따로 뱉는거 없다.
}

int main(void) {
    int A[] = {40, 30, 20, 80, 50, 10, 60, 70};

    quick_sort(0, 7, A);

    
}