class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
                           vector<int>& wd) {
        int ans = INT_MAX;

        for (int i = 0; i < ls.size(); i++) {
            for (int j = 0; j < ws.size(); j++) {
                ans = min(ans, max(ls[i] + ld[i], ws[j]) + wd[j]);
                ans = min(ans, max(ws[j] + wd[j], ls[i]) + ld[i]);
            }
        }
        return ans;
    }
};