class Solution {
public:
    const int d[5]={0, 1, 0, -1, 0};
    int n, m;
    int dfs(int i, int j, vector<vector<int>>& grid){
        int fish=grid[i][j];
        grid[i][j]=0;// visited
        for (int a=0; a<4; a++){
            int r=i+d[a],  c=j+d[a+1];
            if (r<0 || r>=n || c<0 || c>=m || grid[r][c]==0)
                continue;
            fish+=dfs(r, c, grid);
        }
        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j]>0)
                    ans=max(ans, dfs(i, j, grid));
            }
        }
        return ans;
    }
};




// class Solution {
// public:
//     int findMaxFish(vector<vector<int>>& grid) {
//         int Max = 0;
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
//                 if (grid[i][j] > 0) {
//                     int C = 0;
//                     queue<pair<int, int>> T;
//                     T.push({i, j});
//                     while (!T.empty()) {
//                         auto [x, y] = T.front();
//                         T.pop();
//                         if (grid[x][y] > 0) {
//                             C += grid[x][y];
//                             grid[x][y] = 0; // Mark as visited
//                             if (x > 0 && grid[x - 1][y] > 0) T.push({x - 1, y});
//                             if (x + 1 < grid.size() && grid[x + 1][y] > 0) T.push({x + 1, y});
//                             if (y > 0 && grid[x][y - 1] > 0) T.push({x, y - 1});
//                             if (y + 1 < grid[0].size() && grid[x][y + 1] > 0) T.push({x, y + 1});
//                         }
//                     }
//                     Max = max(Max, C);
//                 }
//             }
//         }
//         return Max;
//     }
// };