class Solution {
public:
    string minWindow(string s, string t) {
        int freq[128] = {0};
        int n = t.size();

        for (int i = 0; i < n; i++) {
            freq[t[i]]++;
        }
        int left = 0, right = 0;
        int count = t.size();
        int minLen = INT_MAX, start = 0;

        while (right < s.size()) {
            if (freq[s[right]] > 0)
                count--;

            freq[s[right]]--;
            right++;

            while (count == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0)
                    count++;

                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};