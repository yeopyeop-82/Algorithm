#include <stdio.h>

int s[64][64];

void zip(int i, int j, int n) {
    int count = 0;
    for (int p = i; p < i + n; p++) {
        for (int q = j; q < j + n; q++) {
            if (s[p][q] == 1) {
                count++;
            }
        }
    }
    if (count == n*n) {
        printf("1");
    }
    else if(!count) {
        printf("0");
    }
    else {
        printf("(");
        zip(i, j, n/2);
        zip(i, j + n/2, n/2);
        zip(i + n/2, j, n/2);
        zip(i + n/2, j + n/2, n/2);
        printf(")");
    }
}

int main(void) {

    int n = 0;

    printf("n을 입력하세요 : ");
    scanf("%d", &n);

    for (int i = 0; i < n*n; i++) {
        scanf("%1d", &s[i/n][i%n]);
    }

    zip(0, 0, n);

    return 0;

}