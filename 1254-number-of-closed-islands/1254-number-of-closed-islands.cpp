class Solution {
public:
    void dfs(vector<vector<int>>& g, int i, int j) {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j]) return;
        g[i][j] = 1;
        dfs(g, i + 1, j);
        dfs(g, i - 1, j);
        dfs(g, i, j + 1);
        dfs(g, i, j - 1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;

        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        for (int i = 1; i < m - 1; i++)
            for (int j = 1; j < n - 1; j++)
                if (grid[i][j] == 0) {
                    ans++;
                    dfs(grid, i, j);
                }
        return ans;
    }
};