#include <vector>
#include <algorithm> // sort 사용할거임

std::vector<int> edge[10001];
bool visit[10001];

void initVisit()
{
    for (int i = 0; i < 10001; i++) {
        visit[i] = false; // 초기화
    }
}

void dfs(int v) {
    if (visit[v] == true) {
        return; // 방문함 이미 !!
    }
    
    printf("%d ", v);
    visit[v] = true;
    for (int i = 0; i < edge[v].size(); i++) {
        dfs(edge[v][i]);
    }
}

int main()
{
    int i, j; // 반복문
    int n, m, s; // n : vertex 개수, m : edge 개수, s 뭐임
    int u, v; // u : vertex, v : 이어져 있는 v

    scanf("%d %d %d", &n, &m, &s);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (i = 1; i <= n; i++)
        sort(edge[i].begin(), edge[i].end());

    initVisit();
    for (i = 1; i <= n; i++) {
        if(visit[i] == false) {
            dfs(i);
        }
    }

    return 0;
}