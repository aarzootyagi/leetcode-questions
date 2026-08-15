class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool nonzero = false;

        for (int n : nums) {
            x ^= n;
            if (n) nonzero = true;
        }
        if (x) return nums.size();

        return nonzero ? nums.size() - 1 : 0;
    }
};