#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= m; i++) {
        int u, v, w; 
        cin >> u >> v;
        // for weighted graph take w as input
        // store it instead of 1 in each adj[u][v]
        // cin >> w
        // adj[u][v] = w
        // adj[v][u] = w
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}