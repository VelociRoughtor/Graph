#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &res) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        res.push_back(node);

        for (auto &it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> BFS;
    vector<bool> vis(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bfs(i, adj, vis, BFS);
        }
    }

    cout << "BFS: ";
    for (int &node : BFS) {
        cout << node << ' ';
    }
    cout << endl;

    return 0;
}
