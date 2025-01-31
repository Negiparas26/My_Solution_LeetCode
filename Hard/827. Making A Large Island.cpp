class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int color)
    {
        int n = grid.size();
        int m = grid[0].size();

        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(grid[i][j]==0 || grid[i][j]==color) return 0;

        grid[i][j] = color;
        int count = 1;

        count += dfs(i+1,j,grid,color);
        count += dfs(i-1,j,grid,color);
        count += dfs(i,j+1,grid,color);
        count += dfs(i,j-1,grid,color);

        return count;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int mn = grid[0].size();
        unordered_map<int,int>m;
        int color = 2;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<mn;j++)
            {
                if(grid[i][j]==1)
                {
                    int count = dfs(i,j,grid,color);
                    m[color] = count;
                    color++;
                }
            }
        }

        int result = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<mn;j++)
            {
                if(grid[i][j]==0)
                {
                    set<int>s;
                    if(i-1>=0 && grid[i-1][j]!=0) s.insert(grid[i-1][j]);
                    if(j-1>=0 && grid[i][j-1]!=0) s.insert(grid[i][j-1]);
                    if(i+1<n && grid[i+1][j]!=0) s.insert(grid[i+1][j]);
                    if(j+1<mn && grid[i][j+1]!=0) s.insert(grid[i][j+1]);

                    int sum = 1;
                    for(auto it:s)
                    {
                        sum += m[it];
                    }

                    result = max(result, sum);
                }
            }
        }

        return result==0 ? (n*mn) : result;
    }
};



// 1. Identify islands and mark them with unique IDs
//    ├── Use BFS to traverse each island
//    ├── Store each island’s size in a hashmap
//    └── Track the largest island found so far

// 2. Iterate through the grid to find zeroes
//    ├── For each zero, check its adjacent cells
//    ├── Collect unique island IDs
//    ├── Sum up sizes of adjacent islands
//    ├── Add 1 to account for flipping the zero to one
//    └── Update the maximum possible island size

// 3. Return the maximum possible island size found
//     ---------------------or------------------------------
class Solution {
public:
    int bfs(vector<vector<int>>& grid, int row, int col, int n, int id, vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        grid[row][col] = id;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int cnt = 1;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    grid[nrow][ncol] = id;
                    q.push({nrow, ncol});
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxi = 0;
        int id = 2;
        unordered_map<int, int> mp;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int cnt = bfs(grid, i, j, n, id, vis);
                    mp[id] = cnt;
                    maxi = max(maxi, cnt);
                    id++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIslands;
                    for (int d = 0; d < 4; d++) {
                        int nrow = i + delrow[d];
                        int ncol = j + delcol[d];
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] > 1) {
                            uniqueIslands.insert(grid[nrow][ncol]);
                        }
                    }
                    
                    int newSize = 1;
                    for (int islandId : uniqueIslands) {
                        newSize += mp[islandId];
                    }
                    maxi = max(maxi, newSize);
                }
            }
        }
        
        return maxi;
    }
};





