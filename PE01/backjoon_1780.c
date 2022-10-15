#define MAX 2187

#include <stdio.h>

int s[MAX][MAX];
int result[3];

int same_check (int i, int j, int n, int color) {
    for (int p = 0; p < n; p++) {
        for (int q = 0; q < n; q++) {
            if (s[i + p][j + q] != color) {
                return 0;
            }
        }
    }
    return 1;
}

void paper (int i, int j, int n) {

    if (same_check(i, j, n, s[i][j])) {
        result[s[i][j] + 1]++;
        // printf("%d", result[0]);
        // printf("%d", result[1]);
        // printf("%d\n", result[2]);
        return;
    }
    else {
        for (int p = 0; p < 3; p++) {
            for (int q = 0; q< 3; q++) {
                paper(i + p * n / 3, j + q * n / 3, n / 3);
            }
        }
    }
}

int main(void) {

    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    paper(0, 0, n);

    printf("%d\n", result[0]);
    printf("%d\n", result[1]);
    printf("%d\n", result[2]);

    return 0;
}

