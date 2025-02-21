#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m)), vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>,int>> q;
    int mxt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
        }
    }

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        mxt = max(mxt, t);

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 2 && grid[nr][nc] == 1){
                vis[nr][nc] = 2;
                grid[nr][nc] = 2;
                q.push({{nr, nc}, t + 1});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                mxt = -1;
                break;
            }
        }
        if (mxt == -1) break;
    }
    cout << mxt << endl;

    return 0;
}
