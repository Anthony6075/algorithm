#include <iostream>
using namespace std;

constexpr int N = 5;

int visited[N] = {0};

void dfs(int G[N][N], int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int w = 0; w < N; w++) {
        if (G[v][w]) {
            if (!visited[w]) {
                dfs(G, w);
            }
        }
    }
}

void dfsTraverse(int G[N][N]) {
    for (int v = 0; v < N; v++) {
        if (!visited[v]) {
            dfs(G, v);
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

    dfsTraverse(G);
}