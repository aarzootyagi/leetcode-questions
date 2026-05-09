class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;
        for (int l = 0; l < layers; l++) {
            vector<int> v;
            int top = l, left = l;
            int bottom = m - l - 1, right = n - l - 1;

            for (int j = left; j <= right; j++) v.push_back(grid[top][j]);
            for (int i = top + 1; i <= bottom - 1; i++) v.push_back(grid[i][right]);
            for (int j = right; j >= left; j--) v.push_back(grid[bottom][j]);
            for (int i = bottom - 1; i >= top + 1; i--) v.push_back(grid[i][left]);

            int len = v.size();
            int rot = k % len;

            vector<int> t(len);
            for (int i = 0; i < len; i++)
                t[i] = v[(i + rot) % len];

            int idx = 0;
            for (int j = left; j <= right; j++) grid[top][j] = t[idx++];
            for (int i = top + 1; i <= bottom - 1; i++) grid[i][right] = t[idx++];
            for (int j = right; j >= left; j--) grid[bottom][j] = t[idx++];
            for (int i = bottom - 1; i >= top + 1; i--) grid[i][left] = t[idx++];
        }
        return grid;
    }
};