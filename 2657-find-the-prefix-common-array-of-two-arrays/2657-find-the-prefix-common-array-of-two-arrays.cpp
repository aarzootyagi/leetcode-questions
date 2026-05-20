class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), c = 0;
        vector<int> ans, vis(n + 1);

        for (int i = 0; i < n; i++) {
            if (++vis[A[i]] == 2)
                c++;
            if (++vis[B[i]] == 2)
                c++;
            ans.push_back(c);
        }
        return ans;
    }
};