class Solution {
public:
    set<string> solve(string &s, int &i) {
        set<string> res, cur = {""};

        while (i < s.size() && s[i] != '}') {
            set<string> part;
            if (s[i] == '{') {
                i++;
                part = solve(s, i);
                i++;
            } 
            else if (s[i] == ',') {
                i++;
                continue;
            } 
            else {
                part.insert(string(1, s[i]));
                i++;
            }
            set<string> temp;
            for (auto a : cur)
                for (auto b : part)
                    temp.insert(a + b);

            cur = temp;
            if (i < s.size() && s[i] == ',') {
                res.insert(cur.begin(), cur.end());
                cur = {""};
            }
        }
        res.insert(cur.begin(), cur.end());
        return res;
    }
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};