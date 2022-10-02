#include <stdio.h>
#include <memory.h>

char arr[3072][6144];

void stars(int row, int col, int n) {
    if (n == 3) {
        arr[row][col] = '*';
        arr[row+1][col-1] = '*';
        arr[row+1][col+1] = '*';
        arr[row+2][col-2] = '*';
        arr[row+2][col-1] = '*';
        arr[row+2][col] = '*';
        arr[row+2][col+1] = '*';
        arr[row+2][col+2] = '*';
    }
    else {
        stars(row, col, n/2);
        stars(row + n/2, col - n/2, n/2);
        stars(row + n/2, col + n/2, n/2);

    }
}

int main(void) {
    int n; 
    scanf("%d", &n);
    memset(arr, ' ', sizeof(arr));
    stars(0, n-1, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 2*n; j++)
            putchar(arr[i][j]); 
        putchar(10);
    }

    return 0;
}