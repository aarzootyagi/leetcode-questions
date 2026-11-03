class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end()), s = 0;
        for(int x : nums) s += m - x;
        return s;
    }
};