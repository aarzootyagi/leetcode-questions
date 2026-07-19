class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26), vis(26, 0);

        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        string ans;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (vis[c - 'a'])
                continue;

            while (!ans.empty() && ans.back() > c &&
                   last[ans.back() - 'a'] > i) {
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans += c;
            vis[c - 'a'] = 1;
        }
        return ans;
    }
};