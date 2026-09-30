class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int d = 0;

        for(char c : seq) {
            if(c == '(') d++;
            ans.push_back(d % 2);
            if(c == ')') d--;
        }
        return ans;
    }
};