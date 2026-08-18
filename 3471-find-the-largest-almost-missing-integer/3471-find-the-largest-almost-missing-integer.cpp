class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int cnt[51] = {};
        
        for(int i = 0; i <= nums.size() - k; i++) {
            bool seen[51] = {};
            for(int j = i; j < i + k; j++)
                seen[nums[j]] = true;
            for(int x = 0; x <= 50; x++)
                if(seen[x]) cnt[x]++;
        }
        for(int x = 50; x >= 0; x--)
            if(cnt[x] == 1) return x;
        
        return -1;
    }
};