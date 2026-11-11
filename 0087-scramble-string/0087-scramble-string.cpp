class Solution {
public:
    int dp[31][31][31];

    bool solve(string &a, string &b, int i, int j, int n) {
        if(a.substr(i,n)==b.substr(j,n)) return true;

        if(dp[i][j][n]!=-1) return dp[i][j][n];

        int x[26]={}, y[26]={};
        for(int k=0;k<n;k++) {
            x[a[i+k]-'a']++;
            y[b[j+k]-'a']++;
        }
        for(int k=0;k<26;k++)
            if(x[k]!=y[k]) return dp[i][j][n]=0;

        for(int k=1;k<n;k++) {
            if((solve(a,b,i,j,k) && solve(a,b,i+k,j+k,n-k)) ||
               (solve(a,b,i,j+n-k,k) && solve(a,b,i+k,j,n-k)))
                return dp[i][j][n]=1;
        }
        return dp[i][j][n]=0;
    }
    bool isScramble(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0,s1.size());
    }
};