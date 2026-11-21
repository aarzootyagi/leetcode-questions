class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n=p.size();
        vector<vector<int>> g(n), t(n);
        for(int i=1;i<n;i++) g[p[i]].push_back(i);

        vector<int> last(26,-1), ans(n,1);

        function<void(int)> dfs = [&](int u) {
            int c=s[u]-'a', old=last[c];
            last[c]=u;
            for(int v:g[u]) {
                if(last[s[v]-'a']!=-1)
                    p[v]=last[s[v]-'a'];
                dfs(v);
            }
            last[c]=old;
        };
        dfs(0);

        for(int i=1;i<n;i++) t[p[i]].push_back(i);

        function<void(int)> calc = [&](int u) {
            for(int v:t[u]) {
                calc(v);
                ans[u]+=ans[v];
            }
        };
        calc(0);
        return ans;
    }
};