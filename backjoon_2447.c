#include <stdio.h>

void starboxMaker(int row, int col, int N) {
	if ((row / N) % 3 == 1 && (col / N) % 3 == 1) {
		printf(" ");
	}
	else {
		if (N / 3 == 0) {
			printf("*");
		}
		else {
			starboxMaker(row, col, N / 3);
		}
	}
}

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			starboxMaker(i, j, N);
		}
		printf("\n");
	}

	return 0;
}

