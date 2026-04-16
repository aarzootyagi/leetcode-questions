class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans;

        for (int q : queries) {
            auto& v = mp[nums[q]];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();

            int prev = v[(pos - 1 + v.size()) % v.size()];
            int next = v[(pos + 1) % v.size()];

            int d1 = abs(q - prev);
            int d2 = abs(q - next);

            int res = min({d1, d2, n - d1, n - d2});
            ans.push_back(res);
        }
        return ans;
    }
};