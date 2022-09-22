#include <stdio.h>

void star (int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i % 3 == 1 && j % 3 == 1) {
                printf(" ");
            }
            else if (n/3 - 1 < i && i < 2/3 * n) {
                if (n/3 - 1 < j && j < 2/3 * n)
                    printf(" ");
                else
                    printf("*");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main(void) {
    
    int n = 0;

    scanf("%d", &n);
    star(n);

    return 0;
}