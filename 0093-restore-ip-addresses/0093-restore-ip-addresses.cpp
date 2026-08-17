class Solution {
public:
    vector<string> ans;

    bool valid(string& part) {
        if (part.size() > 1 && part[0] == '0') return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }
    void dfs(string& s, int idx, int parts, string cur) {
        if (parts == 4) {
            if (idx == s.size()) {
                cur.pop_back();
                ans.push_back(cur);
            }return;
        }
        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);

            if (!valid(part)) continue;

            dfs(s, idx + len, parts + 1, cur + part + ".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0, "");
        return ans;
    }
};