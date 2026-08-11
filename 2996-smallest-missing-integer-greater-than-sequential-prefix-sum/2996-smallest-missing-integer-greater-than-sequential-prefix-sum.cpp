class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int s = nums[0];
        for (int i = 1; i < nums.size() && nums[i] == nums[i - 1] + 1; i++)
            s += nums[i];

        unordered_set<int> st(nums.begin(), nums.end());
        while (st.count(s))
            s++;
        return s;
    }
};