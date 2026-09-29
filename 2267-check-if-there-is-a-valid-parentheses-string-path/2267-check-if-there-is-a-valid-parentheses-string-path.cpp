class Solution {
public:
    bool hasValidPath(vector<vector<char>>& g) {
        int m=g.size(), n=g[0].size();

        if((m+n-1)%2 || g[0][0]==')' || g[m-1][n-1]=='(')
            return false;

        vector dp(m,vector(n,vector<bool>(m+n,false)));
        dp[0][0][1]=true;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                for(int b=0;b<m+n;b++) {
                    if(!dp[i][j][b]) continue;

                    if(i+1<m) {
                        int x=b+(g[i+1][j]=='('?1:-1);
                        if(x>=0) dp[i+1][j][x]=true;
                    }

                    if(j+1<n) {
                        int x=b+(g[i][j+1]=='('?1:-1);
                        if(x>=0) dp[i][j+1][x]=true;
                    }
                }
        return dp[m-1][n-1][0];
    }
};