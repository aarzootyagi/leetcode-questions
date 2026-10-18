class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long C[1005][1005];

    long long solve(vector<int>& a) {
        if (a.size() <= 2)
            return 1;
        vector<int> l, r;
        for (int i = 1; i < a.size(); i++)
            if (a[i] < a[0])
                l.push_back(a[i]);
            else
                r.push_back(a[i]);

        return C[l.size() + r.size()][l.size()] * solve(l) % MOD * solve(r) %
               MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++)
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
        return (solve(nums) - 1 + MOD) % MOD;
    }
};