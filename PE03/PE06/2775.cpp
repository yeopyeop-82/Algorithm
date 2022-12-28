#include <iostream>
#include <stdio.h>
#define MAX 15

using namespace std;

int A[MAX][15] = {0, };

int apt(int k, int n) {

    if (k == 0) {
        for(int i = 0; i <= n; i++) {
            A[k][i] = i;
        }
        return n;
    }

    else {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        
        A[k][n] = apt(k, n-1) + apt(k-1, n);
        return A[k][n];
    }
}

int main(void) {
    int count, k, n;
    cin >> count;

    for (int i = 0; i < count ; i++) {
        cin >> k;
        cin >> n;
        cout << apt(k, n);
    }

    return 0;
}