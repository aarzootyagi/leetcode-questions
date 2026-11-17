class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size(), INF = 1e9;
        vector<vector<int>> c(n, vector<int>(n, INF));

        for(int l = 0; l < n; l++) {
            for(int r = l + 1; r < n; r++) {
                int len = r - l + 1;

                for(int d = 1; d < len; d++) {
                    if(len % d) continue;

                    int x = 0;
                    for(int i = 0; i < d; i++) {
                        int a = 0, b = (len - 1 - i) / d;
                        while(a < b) {
                            if(s[l + i + a*d] != s[l + i + b*d])
                                x++;
                            a++, b--;
                        }
                    }
                    c[l][r] = min(c[l][r], x);
                }
            }
        }
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for(int t = 1; t <= k; t++) {
            for(int i = 2*t; i <= n; i++) {
                for(int j = 2*(t-1); j <= i-2; j++) {
                    dp[t][i] = min(dp[t][i], dp[t-1][j] + c[j][i-1]);
                }
            }
        }
        return dp[k][n];
    }
};