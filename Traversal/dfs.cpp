#include<bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &res) {
    vis[start] = 1;
    res.push_back(start);
    for (auto &it : adj[start]) {
        if (!vis[it]) {
            dfs(it, adj, vis, res);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> DFS;
    vector<bool> vis(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, DFS);
        }
    }

    cout << "DFS: ";
    for (int &node : DFS) {
        cout << node << ' ';
    }
    cout << endl;

    return 0;
}