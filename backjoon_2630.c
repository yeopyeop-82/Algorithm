#include <stdio.h>

int white = 0;
int blue = 0;
int s[128][128] = {0, };

void colorpaper (int i, int j, int n) {
    
    int count = 0;

    for (int p = i; p < i+n; p++) {
        for (int q = j; q < j+n; q++) {
            if(s[p][q] == 1) {
                count++;
            }
        }
    }

    if (count == n*n) {
        blue++;
    }
    else if(!count) {
        white++;
    }
    else {
        colorpaper(i, j, n/2);
        colorpaper(i, j + n/2, n/2);
        colorpaper(i + n/2, j, n/2);
        colorpaper(i + n/2, j + n/2, n/2);
    }



}

int main(void) {

    int n = 0;
    printf("n을 입력해주세요 : ");
    scanf("%d", &n);

    for (int i = 0; i < n*n; i++) {
        scanf("%d", &s[i / n][i % n]);
    }

    colorpaper(0, 0, n);

    printf("%d\n", white);
    printf("%d", blue);

    return 0;
}