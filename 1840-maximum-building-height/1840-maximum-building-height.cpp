class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        r.push_back({1, 0});
        bool found = false;

        for (auto& x : r)
            if (x[0] == n)
                found = true;
        if (!found)
            r.push_back({n, n - 1});

        sort(r.begin(), r.end());
        int m = r.size();

        for (int i = 1; i < m; i++)
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);

        for (int i = m - 2; i >= 0; i--)
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);

        long long ans = 0;

        for (int i = 1; i < m; i++) {
            long long d = r[i][0] - r[i - 1][0];
            long long h1 = r[i - 1][1];
            long long h2 = r[i][1];

            ans = max(ans, (h1 + h2 + d) / 2);
        }
        return (int)ans;
    }
};
