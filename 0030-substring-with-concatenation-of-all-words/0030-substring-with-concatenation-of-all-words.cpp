class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size();
        int m = words.size();
        int len = words[0].size();
        unordered_map<string, int> mp;
        for (auto& w : words)
            mp[w]++;

        for (int i = 0; i < len; i++) {
            unordered_map<string, int> cur;
            int left = i, cnt = 0;
            for (int j = i; j + len <= n; j += len) {
                string t = s.substr(j, len);
                if (mp.count(t)) {
                    cur[t]++;
                    cnt++;
                    while (cur[t] > mp[t]) {
                        string x = s.substr(left, len);
                        cur[x]--;
                        left += len;
                        cnt--;
                    }
                    if (cnt == m) {
                        ans.push_back(left);

                        string x = s.substr(left, len);
                        cur[x]--;
                        left += len;
                        cnt--;
                    }
                } else {
                    cur.clear();
                    cnt = 0;
                    left = j + len;
                }
            }
        }
        return ans;
    }
};