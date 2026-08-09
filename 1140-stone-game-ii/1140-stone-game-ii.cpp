class Solution {
public:
    int dp[101][101];
    int f(vector<int>& s, int i, int m) {
        if (i >= s.size()) return 0;
        if (2 * m >= s.size() - i) return s[i];
        if (dp[i][m]) return dp[i][m];

        int ans = 0;
        for (int x = 1; x <= 2 * m; x++)
            ans = max(ans, s[i] - f(s, i + x, max(m, x)));

        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> suf(n);
        suf[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] + piles[i];

        return f(suf, 0, 1);
    }
};