class Solution {
public:
    string ans = "";
    int cnt = 0;

    void dfs(string cur, int n, int k) {
        if (cur.size() == n) {
            cnt++;
            if (cnt == k)
                ans = cur;
            return;
        }
        for (char c : {'a', 'b', 'c'}) {
            if (cur.empty() || cur.back() != c) {
                dfs(cur + c, n, k);
                if (!ans.empty())
                    return;
            }
        }
    }

    string getHappyString(int n, int k) {
        dfs("", n, k);
        return ans;
    }
};