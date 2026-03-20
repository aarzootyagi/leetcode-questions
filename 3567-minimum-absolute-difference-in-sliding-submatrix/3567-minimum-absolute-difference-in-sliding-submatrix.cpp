class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                set<int> st;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        st.insert(grid[x][y]);
                    }
                }
                if (st.size() <= 1) {
                    ans[i][j] = 0;
                    continue;
                }
                vector<int> arr(st.begin(), st.end());
                int minDiff = INT_MAX;

                for (int p = 1; p < arr.size(); p++) {
                    minDiff = min(minDiff, arr[p] - arr[p - 1]);
                }

                ans[i][j] = minDiff;
            }
        }
        return ans;
    }
};