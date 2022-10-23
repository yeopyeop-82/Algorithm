#include <stdio.h>
#define MAX 10001

int dfn[MAX];
int low[MAX];
int num = 0;

void initArray() {
    int i, j;
    for (i = 0; i < MAX; i++){
        dfn[i] = low[i] = -1;
    }
}

void dfs4(int u, int v) {
    dfn[u] = low[u] = num++; // 일단 low 값을 본인의 dfn으로 설정 -> low의 정의에 따른다.

    for ()

}