#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int nc, int ic, vector<vector<int>> &ans, vector<vector<int>> &image) {
    int n = image.size();
    int m = image[0].size();

    ans[row][col] = nc;

    int dr[] = {0, 1, 0, -1};
    int dc[] = {-1, 0, 1, 0};

    for (int i = 0; i < 4; i++) {
        int newr = row + dr[i];
        int newc = col + dc[i];
        if (newr >= 0 && newr < n && newc >= 0 && newc < m && image[newr][newc] == ic && ans[newr][newc] != nc) {
            dfs(newr, newc, nc, ic, ans, image);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> image(n, vector<int>(m)), ans;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }
    ans = image;

    int sr, sc, nc; 
    cin >> sr >> sc >> nc;
    
    int ic = image[sr][sc];
    
    if (ic == nc) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
        return 0;
    }

    dfs(sr, sc, nc, ic, ans, image);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
