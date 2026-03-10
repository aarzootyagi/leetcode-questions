class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int directions[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};

        int pathLength = 1;

        while(!q.empty()) {
            int size = q.size();

            while(size > 0) {
                pair<int, int> temp = q.front();
                int r = temp.first;
                int c = temp.second;
                q.pop();

                if(r == n-1 && c == n-1)
                    return pathLength;

                for(int i = 0; i < 8; i++) {
                    int newR = r + directions[i][0];
                    int newC = c + directions[i][1];

                    if(newR >= 0 && newC >= 0 &&
                       newR < n && newC < n &&
                       grid[newR][newC] == 0) {
                        q.push({newR, newC});
                        grid[newR][newC] = 1;
                    }
                }
                size--;
            }
            pathLength++;
        }
        return -1;
    }
};