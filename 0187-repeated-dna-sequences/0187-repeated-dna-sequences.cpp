class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        vector<string> ans;

        for (int i = 0; i + 9 < s.size(); i++) {
            string t = s.substr(i, 10);
            if (++mp[t] == 2)
                ans.push_back(t);
        }
        return ans;
    }
};