class Solution {
public:
    int m,n;
    vector<vector<int>> vis;

    bool dfs(vector<vector<char>>& grid,int i,int j,int pi,int pj){
        vis[i][j]=1;
        int d[5]={1,0,-1,0,1};
        for(int k=0;k<4;k++){
            int x=i+d[k], y=j+d[k+1];
            if(x>=0&&y>=0&&x<m&&y<n&&grid[x][y]==grid[i][j]){
                if(!vis[x][y]){
                    if(dfs(grid,x,y,i,j)) return true;
                }
                else if(x!=pi || y!=pj) return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m=grid.size(), n=grid[0].size();
        vis.assign(m, vector<int>(n,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!vis[i][j] && dfs(grid,i,j,-1,-1))
                    return true;
        return false;
    }
};