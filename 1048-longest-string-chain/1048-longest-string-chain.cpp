class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
        return a.size() < b.size();
    });
    unordered_map<string, int> mpp;
    int maxi = 1;

    for (auto &word : words) {
        mpp[word] = 1; 
        for (int i = 0; i < word.size(); i++) {
            string prev = word.substr(0, i) + word.substr(i + 1);

            if (mpp.count(prev)) {
                mpp[word] = max(mpp[word], mpp[prev] + 1);
            }
        }
        maxi = max(maxi, mpp[word]);
    }
    return maxi;
    }
};