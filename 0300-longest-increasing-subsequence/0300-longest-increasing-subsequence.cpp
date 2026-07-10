// Recursion
//  class Solution {
//  public:
//      int solve(int i, int prev, vector<int>& nums) {
//          int n = nums.size();
//          if (i == n) return 0;
//          int notTake = solve(i + 1, prev, nums);

//         int take = 0;
//         if (nums[i] > prev) {
//             take = 1 + solve(i + 1, nums[i], nums);
//         }
//         return max(take, notTake);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         return solve(0, INT_MIN, nums);
//     }
// };

// Memoization
//  class Solution {
//  public:
//      int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
//          if (i == nums.size()) return 0;

//         if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

//         int notTake = solve(i + 1, prev, nums, dp);

//         int take = 0;
//         if (prev == -1 || nums[i] > nums[prev]) {
//             take = 1 + solve(i + 1, i, nums, dp);
//         }
//         return dp[i][prev + 1] = max(take, notTake);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return solve(0, -1, nums, dp);
//     }
// };

// Tabulation

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int notTake = dp[i + 1][prev + 1];
                int take = 0;
                if (prev == -1 || nums[i] > nums[prev]) {
                    take = 1 + dp[i + 1][i + 1];
                }
                dp[i][prev + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};