class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;

        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        parent.resize(20002);
        rank.resize(20002, 0);

        for (int i = 0; i < 20002; i++)
            parent[i] = i;

        for (auto& s : stones) {
            int row = s[0];
            int col = s[1] + 10001;
            unite(row, col);
        }
        unordered_set<int> components;

        for (auto& s : stones) {
            components.insert(find(s[0]));
        }
        return stones.size() - components.size();
    }
};