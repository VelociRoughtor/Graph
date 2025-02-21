#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == 0){
            dfs(nr, nc, vis, grid);
        }
    }
}

int main() {
    int n, m, cc = 0;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m)), vis(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && vis[i][j] == 0) {
                cc++;
                dfs(i, j, vis, grid);
            }
        }
    }

    cout << "Number of islands: " << cc << endl;

    return 0;
}
