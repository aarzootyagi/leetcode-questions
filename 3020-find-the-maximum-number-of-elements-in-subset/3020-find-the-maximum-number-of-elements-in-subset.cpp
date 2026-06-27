class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums)
            freq[x]++;
        int ans = 1;

        if (freq.count(1)) {
            int c = freq[1];
            ans = max(ans, (c % 2) ? c : c - 1);
        }
        for (auto& [start, cnt] : freq) {
            if (start == 1)
                continue;

            long long cur = start;
            int len = 0;

            while (true) {
                int f = freq.count(cur) ? freq[cur] : 0;
                if (f < 2) {
                    if (len == 0) {
                        if (f >= 1)
                            ans = max(ans, 1);
                    } else {
                        if (f >= 1)
                            ans = max(ans, len + 1);
                        else
                            ans = max(ans, len - 1);
                    }
                    break;
                }
                len += 2;
                if (cur > 1000000000LL) {
                    ans = max(ans, len - 1);
                    break;
                }
                cur = cur * cur;
            }
        }
        return ans;
    }
};