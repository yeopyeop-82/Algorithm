// SCC 구현하기
// 1. graph 만들기

// SCC 알고리즘
// 1. 자료구조 만들기
//      - graph g -> adjacency list -> vector의 배열

// 2. G 읽어들이기
// 3. G -> G reverse
// 4. G reverse 에서 dfs 하고, pre, post 계산
// 5. G 에서 postnum 역순으로 dfs --> scc 하나씩 생성

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> g [10001];
vector<int> gr[10001];
int pre[10001], post[10001];
int c = 0;

void initVisit()
{
    for (int i = 0; i < 10001; i++) {
        pre[i] = post[i] = -1;
    }
}

void dfs(int v)
{
    printf("%d visiting \n", v);

    for (int i = 0; i < gr[v].size(); i++) {
        if(pre[gr[v][i]] < 0){
            dfs(gr[v][i]);
        }
    }

    post[v] = c++;
}

int main() {
// 1. G 읽어들이기

    int i, j;
    int n, m; // n은 v의 수, m은 E의 수
    int u, v; // <u, v> 는 edge


    FILE* fp = fopen("graph1.txt", "r + t");

    fscanf(fp, "%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        fscanf(fp, "%d %d", &u, &v);
        g[u].push_back(v);
        // undirected 일 때 g[v].push_back(u)
    }

    fclose(fp);

    for (i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());
    
    for (i = 1; i <= n; i++) {
        printf("[%d] %d ", i, g[i].size());
        for (j = 0; j < g[i].size(); j++){
            printf("<%d, %d> ", i,g[i][j]);
        }
        printf("\n");
    }

    printf("\n");

// 2. G reverse 만들기
//      -> G를 하나씩 읽으면 u, v
//      -> v에 u를 푸시백한다. push_back --> gr[g[i][j]].push_back(i)

    for (i = 1; i <= n; i++) {
        for (j = 0; j < g[i].size(); j++) {
            gr[g[i][j]].push_back(i);
        }
    }

    for (i = 1; i <= n; i++) {
        sort(gr[i].begin(), gr[i].end());
    }

    for (i = 1; i <= n; i++) {
        printf("[%d] %d ", i, gr[i].size());
        for (j = 0; j < gr[i].size(); j++){
            printf("<%d, %d> ", i, gr[i][j]);
        }
        printf("\n");
    }

// 3. G reverse 에서 dfs 하면서 pre, post 계산

    initVisit();
    for (i = 1; i <= n; i++) {
        if (pre[i] < 0){
            dfs(i);
        }
    }

    for (i = 1; i < n; i++) {
        printf("%d: %d, %d", i, pre[i], post[i]);
    }


    return 0;
}