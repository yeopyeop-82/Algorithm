#include <iostream>
#include <queue>
using namespace std;
 
const int MAX = 100001;
int N, K;
bool visited[MAX] = { 0, };
int path[MAX];
queue<int> q;
 
void printPath() {
    cout << "[PATH]" << endl;
    for (int i = N; i <= K; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = N; i <= K; i++) {
        printf("%2d ", path[i]);
    }
    printf("\n");
}
 
void BFS(int v) {
    path[v] = 0;
    visited[v] = true;
    q.push(v);
 
    while (!q.empty()) {
        int w = q.front();
        if (w == K) break;
        q.pop();

    }
 
}
 
int main() {
    cin >> N >> K;
 
    BFS(N);
 
    cout << path[K];
}
