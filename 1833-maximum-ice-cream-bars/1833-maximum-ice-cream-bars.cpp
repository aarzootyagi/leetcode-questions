class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = *max_element(costs.begin(), costs.end());
        vector<int> cnt(mx + 1);

        for (int c : costs)
            cnt[c]++;
        int ans = 0;
        for (int cost = 1; cost <= mx; cost++) {
            if (!cnt[cost])
                continue;
            int take = min(cnt[cost], coins / cost);
            ans += take;
            coins -= take * cost;

            if (coins < cost)
                break;
        }
        return ans;
    }
};