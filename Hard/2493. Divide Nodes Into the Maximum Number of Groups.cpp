class Solution {

//not by mm   eee

    bool isComponentBipartite(vector<vector<int>>& adj, vector<int>& color,
                              int start) {
        queue<int> q;
        q.push(start);
        color[start] = 1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            for (auto& child : adj[node]) {
                if (color[child] == 0) {
                    color[child] = color[node] * -1;
                    q.push(child);
                } else if (color[child] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBiPartite(vector<vector<int>>& adj, int n) {
        vector<int> color(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0 && !isComponentBipartite(adj, color, i)) {
                return false;
            }
        }
        return true;
    }
    int countLevel(vector<vector<int>>& adj, int start, int n) {
        vector<int> visited(n + 1, 0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto node = q.front();
                q.pop();
                for (auto& child : adj[node]) {
                    if (!visited[child]) {
                        visited[child] = 1;
                        q.push(child);
                    }
                }
            }
            level++;
        }
        return level;
    }
    int findMaxLevelBFS(vector<int>& levels, vector<bool>& visited,
                        vector<vector<int>>& adj, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int maxlevel = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto node = q.front();
                q.pop();
                maxlevel = max(maxlevel, levels[node]);
                for (auto& child : adj[node]) {
                    if (!visited[child]) {
                        visited[child] = true;
                        q.push(child);
                    }
                }
            }
        }
        return maxlevel;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if (!isBiPartite(adj, n)) return -1;
        vector<int> levels(n + 1);
        for (int i = 1; i <= n; i++) levels[i] = countLevel(adj, i, n);
        vector<bool> visited(n + 1, false);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) ans += findMaxLevelBFS(levels, visited, adj, i);
        }
        return ans;
    }
};