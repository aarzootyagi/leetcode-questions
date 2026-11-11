class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long a = min(need1, need2);
        long long b = max(need1, need2);

        return min({
            1LL*need1*cost1 + 1LL*need2*cost2,
            1LL*a*costBoth + 1LL*(need1-a)*cost1 + 1LL*(need2-a)*cost2,
            1LL*b*costBoth
        });
    }
};