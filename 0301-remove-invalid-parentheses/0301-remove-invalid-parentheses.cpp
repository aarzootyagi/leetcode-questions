class Solution {
public:
    bool valid(string s) {
        int b = 0;
        for(char c : s) {
            if(c == '(') b++;
            else if(c == ')' && --b < 0) return false;
        }
        return b == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> vis{s};
        queue<string> q;
        q.push(s);

        bool found = false;

        while(!q.empty() && !found) {
            int n = q.size();

            while(n--) {
                string x = q.front();
                q.pop();

                if(valid(x)) {
                    ans.push_back(x);
                    found = true;
                    continue;
                }

                if(found) continue;

                for(int i = 0; i < x.size(); i++) {
                    if(x[i] == '(' || x[i] == ')') {
                        string y = x.substr(0,i) + x.substr(i+1);

                        if(vis.insert(y).second)
                            q.push(y);
                    }
                }
            }
        }
        return ans;
    }
};