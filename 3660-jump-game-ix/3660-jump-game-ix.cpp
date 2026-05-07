class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n), ans(n);

        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = max(pre[i - 1], nums[i]);

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = min(suf[i + 1], nums[i]);

        int l = 0, mx = nums[0];

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);

            if (i == n - 1 || pre[i] <= suf[i + 1]) {
                for (int j = l; j <= i; j++)
                    ans[j] = mx;

                l = i + 1;
                if (l < n)
                    mx = nums[l];
            }
        }
        return ans;
    }
};