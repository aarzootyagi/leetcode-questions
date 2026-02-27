class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> adj;
    vector<int> disc, low;
    int timer = 0;

    void dfs(int u, int parent) {
        disc[u] = low[u] = timer++;

        for (int v : adj[u]) {
            if (v == parent)
                continue;

            if (disc[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    result.push_back({u, v});
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        adj.resize(n);
        disc.assign(n, -1);
        low.resize(n);

        for (auto& c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        dfs(0, -1);

        return result;
    }
};