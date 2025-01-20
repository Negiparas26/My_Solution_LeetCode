class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> numToPos;
        
        // Map numbers to their positions in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                numToPos[mat[i][j]] = {i, j};
            }
        }
        
        vector<int> rows_painted(m, 0);
        vector<int> cols_painted(n, 0);
        
        // Iterate through arr and paint the cells
        for (int i = 0; i < arr.size(); ++i) {
            auto [r, c] = numToPos[arr[i]];
            rows_painted[r]++;
            cols_painted[c]++;
            
            // Check if row or column is fully painted
            if (rows_painted[r] == n || cols_painted[c] == m) {
                return i;
            }
        }
        
        return -1; // This should never be reached given the constraints
    }
};
// class Solution {
// public:
//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size(), N = m * n;
//         vector<int> numToIndex(N + 1, -1);  
//         for (int i = 0; i < N; ++i) {
//             numToIndex[arr[i]] = i;
//         }
//         vector<int> rowPainted(m, 0), colPainted(n, 0);
//         vector<int> rowPos(N), colPos(N);
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 int num = mat[i][j];
//                 int indexInArr = numToIndex[num];
//                 rowPos[indexInArr] = i;
//                 colPos[indexInArr] = j;
//             }
//         }
//         for (int i = 0; i < N; ++i) {
//             int num = arr[i];
//             int rowIdx = rowPos[numToIndex[num]];
//             int colIdx = colPos[numToIndex[num]];
//             if (++rowPainted[rowIdx] == n || ++colPainted[colIdx] == m) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };