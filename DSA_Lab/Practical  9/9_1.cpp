
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100];
bool vis[100];

void dfs(int x) {
    vis[x] = true;
    cout << x << " ";

    for (int y : adj[x]) {
        if (!vis[y])
            dfs(y);
    }
}

void bfs(int s) {
    bool seen[100] = {false};
    queue<int> q;

    q.push(s);
    seen[s] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        cout << x << " ";

        for (int y : adj[x]) {
            if (!seen[y]) {
                seen[y] = true;
                q.push(y);
            }
        }
    }
}

int main() {
    int n, m, u, v, s;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> s;

    cout << "DFS: ";
    dfs(s);

    cout << "\nBFS: ";
    bfs(s);

    return 0;
}
