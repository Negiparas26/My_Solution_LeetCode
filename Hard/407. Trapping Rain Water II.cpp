
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            minHeap;

        // Add boundary cells to the minHeap
        for (int i = 0; i < m; ++i) {
            for (int j : {0, n - 1}) {
                minHeap.emplace(heightMap[i][j], i, j);
                visited[i][j] = true;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i : {0, m - 1}) {
                if (!visited[i][j]) {
                    minHeap.emplace(heightMap[i][j], i, j);
                    visited[i][j] = true;
                }
            }
        }

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int waterTrapped = 0;

        //  Process cells using the minHeap
        while (!minHeap.empty()) {
            auto [height, x, y] = minHeap.top();
            minHeap.pop();

            for (auto& dir : directions) {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    !visited[nx][ny]) {
                    //  Calculate water trapped
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    minHeap.emplace(max(height, heightMap[nx][ny]), nx, ny);
                    visited[nx][ny] = true;
                }
            }
        }

        return waterTrapped; //  Final result
    }
};

// class Solution {
// public:
//     int trapRainWater(vector<vector<int>>& heightMap) {
//         int m = heightMap.size();
//         int n = heightMap[0].size();
        
//         // Edge case: if the grid is too small, no water can be trapped.
//         if (m <= 2 || n <= 2) return 0;
        
//         // Priority queue to store cells, sorted by height.
//         priority_queue<Cell, vector<Cell>, Compare> pq;
        
//         // Visited matrix to track processed cells.
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
        
//         // Add all boundary cells to the priority queue.
//         for (int i = 0; i < m; i++) {
//             pq.push(Cell(heightMap[i][0], i, 0));
//             pq.push(Cell(heightMap[i][n - 1], i, n - 1));
//             visited[i][0] = visited[i][n - 1] = true;
//         }
//         for (int j = 1; j < n - 1; j++) {
//             pq.push(Cell(heightMap[0][j], 0, j));
//             pq.push(Cell(heightMap[m - 1][j], m - 1, j));
//             visited[0][j] = visited[m - 1][j] = true;
//         }
        
//         // Directions for the neighbors (up, down, left, right).
//         vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
//         int totalWater = 0;
        
//         // Process cells in the priority queue.
//         while (!pq.empty()) {
//             Cell cell = pq.top();
//             pq.pop();
            
//             // Process neighbors.
//             for (const auto& dir : directions) {
//                 int nx = cell.x + dir.first;
//                 int ny = cell.y + dir.second;
                
//                 // Skip invalid or visited cells.
//                 if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
                
//                 // Calculate trapped water at this neighbor.
//                 totalWater += max(0, cell.height - heightMap[nx][ny]);
                
//                 // Update the height of the neighbor to ensure it acts as a boundary.
//                 pq.push(Cell(max(cell.height, heightMap[nx][ny]), nx, ny));
                
//                 // Mark the neighbor as visited.
//                 visited[nx][ny] = true;
//             }
//         }
        
//         return totalWater;
//     }

// private:
//     struct Cell {
//         int height, x, y;
//         Cell(int h, int i, int j) : height(h), x(i), y(j) {}
//     };
    
//     struct Compare {
//         bool operator()(const Cell& a, const Cell& b) {
//             return a.height > b.height;
//         }
//     };
// };
