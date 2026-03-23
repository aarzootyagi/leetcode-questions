class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int ans = 0;
        
        for (int i = 1; i < n; i++) {
            ans = max(ans, stones[i] - stones[i - 1]);
        }
        for (int i = 2; i < n; i++) {
            ans = max(ans, stones[i] - stones[i - 2]);
        }
        return ans;
    }
};