class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size(), ans = 0;
        vector<vector<int>> g(n);

        for (auto& v : allowedSwaps)
            g[v[0]].push_back(v[1]), g[v[1]].push_back(v[0]);

        vector<int> vis(n);
        for (int i = 0; i < n; i++)
            if (!vis[i]) {
                vector<int> comp;
                queue<int> q;

                q.push(i);
                vis[i] = 1;

                while (!q.empty()) {

                    int u = q.front();
                    q.pop();
                    comp.push_back(u);
                    for (int v : g[u])
                        if (!vis[v])
                            vis[v] = 1, q.push(v);
                }
                unordered_map<int, int> cnt;
                for (int x : comp)
                    cnt[source[x]]++;
                for (int x : comp)
                    if (cnt[target[x]]-- <= 0)
                        ans++;
            }
        return ans;
    }
};