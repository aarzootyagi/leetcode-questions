class Solution {
public:
    long long dfs(vector<vector<int>>& g, int i, int j) {
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size() || g[i][j]==0)
            return 0;

        long long s = g[i][j];
        g[i][j] = 0;

        s += dfs(g,i+1,j);
        s += dfs(g,i-1,j);
        s += dfs(g,i,j+1);
        s += dfs(g,i,j-1);

        return s;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0, m = grid.size(), n = grid[0].size();

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] > 0)
                    if(dfs(grid,i,j) % k == 0)
                        ans++;

        return ans;
    }
};