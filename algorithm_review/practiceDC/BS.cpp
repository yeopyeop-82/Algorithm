#include <iostream>

using namespace std;

int binary_search(int s, int e, int A[], int x) {
    
    if (s == e) {
        if (A[s] == x) {
            return s;
        }
        else {
            return -1;
        }
    }

    int m = (s + e)/ 2;

    if (x < A[m]) {
        return binary_search(s, m-1, A, x);
    }
    else if (x > A[m]) {
        return binary_search(m + 1, e, A, x);
    }
    else
        return m;

}

int main(void) {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    cout << binary_search(0, 11, A, 4);
    return 0;
}