#include <iostream>
#include <queue>
using namespace std;

constexpr int N = 5;

int visited[N] = {0};

void bfs(int G[N][N], int v) {
    queue<int> q;

    cout << v << " ";
    visited[v] = 1;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int w = 0; w < N; w++) {
            if (G[v][w]) {
                if (!visited[w]) {
                    cout << w << " ";
                    visited[w] = 1;
                    q.push(w);
                }
            }
        }
    }
}

void bfsTraverse(int G[N][N]) {
    for (int v = 0; v < N; v++) {
        if (!visited[v]) {
            bfs(G, v);
        }
    }
}

int main() {
    int G[N][N] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    bfsTraverse(G);
}