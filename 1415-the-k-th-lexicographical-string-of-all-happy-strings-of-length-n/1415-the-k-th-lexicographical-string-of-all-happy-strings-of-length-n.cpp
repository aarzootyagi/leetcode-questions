class Solution {
public:
    void dfs(string s, int n, vector<string>& v) {
        if (s.size() == n) {
            v.push_back(s);
            return;
        }
        for (char c : {'a', 'b', 'c'})
            if (s.empty() || s.back() != c)
                dfs(s + c, n, v);
    }

    string getHappyString(int n, int k) {
        vector<string> v;
        dfs("", n, v);
        return k <= v.size() ? v[k - 1] : "";
    }
};