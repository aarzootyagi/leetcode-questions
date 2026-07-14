class Solution {
public:
    unordered_map<string, vector<string>> memo;
    unordered_set<string> dict;

    vector<string> solve(string s) {
        if (memo.find(s) != memo.end())
            return memo[s];

        vector<string> result;

        if (s.length() == 0) {
            result.push_back("");
            return result;
        }
        for (auto it = dict.begin(); it != dict.end(); it++) {
            string word = *it;
            if (s.substr(0, word.length()) == word) {
                vector<string> temp = solve(s.substr(word.length()));
                for (int i = 0; i < temp.size(); i++) {
                    string sentence;

                    if (temp[i] == "")
                        sentence = word;
                    else
                        sentence = word + " " + temp[i];

                    result.push_back(sentence);
                }
            }
        }
        memo[s] = result;
        return result;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            dict.insert(wordDict[i]);
        }
        return solve(s);
    }
};