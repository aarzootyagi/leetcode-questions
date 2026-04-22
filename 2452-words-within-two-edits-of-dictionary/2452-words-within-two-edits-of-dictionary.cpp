class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,vector<string>& dictionary) {
        vector<string> res;
        for (auto& s : queries)
            for (auto& t : dictionary) {
                int diff = 0;
                for (int i = 0; i < s.size() && diff <= 2; i++)
                    diff += s[i] != t[i];

                if (diff <= 2) {
                    res.push_back(s);
                    break;
                }
            }
        return res;
    }
};