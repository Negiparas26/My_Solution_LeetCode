class Solution {
private:
    bool safe(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& isterminal) {
        if (vis[node] != 0) { 
            return isterminal[node] == 1;
        }

        vis[node] = -1; 
        for (auto it : graph[node]) {
            if (!safe(it, graph, vis, isterminal)) {
                return false; 
            }
        }

        vis[node] = 1;       
        isterminal[node] = 1;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v, 0);          
        vector<int> isterminal(v, 0);  
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                safe(i, graph, vis, isterminal);
            }
        }
        vector<int> ans;
        for (int i = 0; i < v; i++) {
            if (isterminal[i] == 1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};




// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         unordered_set<int> se;
//         for(int i=0;i<graph.size();i++){
//             if(graph[i].size()==0) se.insert(i);
//         }
//         while(true){
//             int x = se.size();
//             for(int i=0;i<graph.size();i++){
//                 bool ins = true;
//                 for(auto el:graph[i]){
//                     if(se.find(el)==se.end()){
//                         ins = false;
//                         break;
//                     }
//                 }
//                 if(ins) se.insert(i);
//             }
//             if(se.size()==x) break;
//         }

//         vector<int> ans(se.begin(), se.end());
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };