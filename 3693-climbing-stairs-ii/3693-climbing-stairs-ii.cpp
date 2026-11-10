class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n+1 , LLONG_MAX);
        dp[0]=0;
        for(int i=0; i<n; i++){
            for(int j=1; j<=3; j++){
                int next = i+j;
                if(next<=n){
                    long long newCost = (long long)costs[next-1] + 1LL * j * j;
                    dp[next] = min(dp[next] , dp[i]+newCost);
                }
            }
        }
        return (int)dp[n];
    }
};