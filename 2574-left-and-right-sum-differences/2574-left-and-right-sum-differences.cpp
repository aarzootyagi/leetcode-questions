class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size(), total = accumulate(nums.begin(), nums.end(), 0),
            left = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            total -= nums[i];
            ans[i] = abs(left - total);
            left += nums[i];
        }

        return ans;
    }
};