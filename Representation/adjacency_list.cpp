#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; 
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    char graphType;
    cout << "Is the graph weighted? (y/n) : ";
    cin >> graphType;
    
    if (graphType == 'n') {
        vector<int> adj[n + 1];
        cout << "Enter edges (u v) : \n";
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // for directed graph comment out this line.
            adj[v].push_back(u);
        }

        cout << "Adjacency list : \n";
        for (int i = 1; i <= n; i++) {
            cout << i << " : ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    } else {
        vector<pair<int,int>> adj[n + 1];
        cout << "Enter edges with weights (u v w) : \n";
        for (int i = 0; i < m; i++) {
            int u, v, w; 
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        cout << "Adjacency list :\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " : ";
            for (auto neighbor : adj[i]) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ")\n";
            }
            cout << endl;
        }
    }
    
    return 0;
}