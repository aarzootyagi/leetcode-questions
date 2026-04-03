class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent, owner;

        function<string(string)> find = [&](string x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        for (auto& a : accounts) {
            for (int i = 1; i < a.size(); i++) {
                parent[a[i]] = a[i];
                owner[a[i]] = a[0];
            }
        }
        for (auto& a : accounts) {
            for (int i = 2; i < a.size(); i++) {
                parent[find(a[i])] = find(a[1]);
            }
        }
        unordered_map<string, vector<string>> mp;
        for (auto& p : parent) {
            mp[find(p.first)].push_back(p.first);
        }
        vector<vector<string>> res;
        for (auto& x : mp) {
            auto v = x.second;
            sort(v.begin(), v.end());
            v.insert(v.begin(), owner[x.first]);
            res.push_back(v);
        }
        return res;
    }
};