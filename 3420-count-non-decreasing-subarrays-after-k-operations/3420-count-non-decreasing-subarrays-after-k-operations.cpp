class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), L = 17;
        vector<vector<int>> up(L, vector<int>(n + 1, n));
        vector<vector<long long>> sum(L, vector<long long>(n + 1, 0));

        vector<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            up[0][i] = st.empty() ? n : st.back();
            sum[0][i] = 1LL * nums[i] * (up[0][i] - i);
            st.push_back(i);
        }
        for (int j = 1; j < L; j++) {
            for (int i = 0; i < n; i++) {
                int mid = up[j - 1][i];
                up[j][i] = up[j - 1][mid];
                sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
            }
        }
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        auto cost = [&](int l, int r) {
            long long s = 0;
            int cur = l;
            for (int j = L - 1; j >= 0; j--) {
                if (up[j][cur] <= r) {
                    s += sum[j][cur];
                    cur = up[j][cur];
                }
            }
            s += 1LL * nums[cur] * (r - cur + 1);
            return s - (pref[r + 1] - pref[l]);
        };
        long long ans = 0;
        for (int l = 0; l < n; l++) {
            int lo = l, hi = n - 1, best = l - 1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (cost(l, mid) <= k) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            ans += best - l + 1;
        }
        return ans;
    }
};