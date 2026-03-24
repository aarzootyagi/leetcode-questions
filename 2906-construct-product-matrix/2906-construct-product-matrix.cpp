class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), mod = 12345;
        int size = n * m;
        
        vector<long long> arr(size, 1), res1D(size, 1);
        
        for (int i = 0, k = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[k++] = grid[i][j] % mod;
    
        long long prefix = 1;
        for (int i = 0; i < size; i++) {
            res1D[i] = prefix;
            prefix = (prefix * arr[i]) % mod;
        }
        
        long long suffix = 1;
        for (int i = size - 1; i >= 0; i--) {
            res1D[i] = (res1D[i] * suffix) % mod;
            suffix = (suffix * arr[i]) % mod;
        }
        
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < size; i++)
            res[i / m][i % m] = res1D[i];
        
        return res;
    }
};