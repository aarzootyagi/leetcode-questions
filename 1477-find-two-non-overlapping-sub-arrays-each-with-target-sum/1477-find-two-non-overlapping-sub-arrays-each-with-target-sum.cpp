class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size(), ans = 1e9, l = 0, sum = 0, best = 1e9;
        vector<int> dp(n, 1e9);

        for(int r = 0; r < n; r++) {
            sum += arr[r];
            while(sum > target)
                sum -= arr[l++];
            if(sum == target) {
                int len = r - l + 1;
                if(l > 0 && dp[l-1] < 1e9)
                    ans = min(ans, len + dp[l-1]);
                best = min(best, len);
            }
            dp[r] = best;
        }
        return ans == 1e9 ? -1 : ans;
    }
};