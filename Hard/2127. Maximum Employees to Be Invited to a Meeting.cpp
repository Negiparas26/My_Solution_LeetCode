class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        int n=fav.size();
        vector<int> indegree(n,0), depth(n,1);
        for (int i=0;i<n;i++) {
            indegree[fav[i]]++;
        }
        queue<int> q;
        for (int i=0;i<n;i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur=q.front();
            q.pop();
            int next=fav[cur];
            depth[next]=max(depth[next], depth[cur] + 1);
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
            }
        }
        int ans=0, twoCycleLen=0;
        for (int i=0;i<n;i++) {
            if (indegree[i] == 0) continue; // already visited
            int cycleLen=0, cur=i;
            while (indegree[cur] != 0) {
                indegree[cur]=0;
                cycleLen++;
                cur=fav[cur];
            }
            if (cycleLen == 2) {
                twoCycleLen += (depth[cur] + depth[fav[cur]]);
            }else {
                ans = max(ans, cycleLen);
            }
        }
        return max(ans, twoCycleLen);
    }
};


// class Solution {
// public:
//     int maximumInvitations(vector<int>& favs) {
//         int n = favs.size();
//         vector<bool> vist(n, false);
//         vector<int> degree(n, 0), chain(n, 0);

//         // Building degree
//         for(int fav: favs) degree[fav]++;

//         // saving all with 0 degree
//         queue<int> q;
//         for(int i=0; i<n; i++){
//             if(degree[i] == 0) q.push(i);
//         }

//         // Calculating chains from each node
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             vist[node] = true;

//             int next = favs[node];
//             chain[next] = chain[node]+1;
//             if(--degree[next] == 0) q.push(next);
//         }

//         int maxCycle = 0, chains = 0;
//         for( int i=0; i<n; i++){
//             if(!vist[i]){
//                 int current = i, cycleLength = 0;
//                 while(!vist[current]) {
//                     vist[current] = true;
//                     current = favs[current];
//                     cycleLength++;
//                 }

//                 if(cycleLength == 2) {
//                     chains += 2 + chain[i] + chain[favs[i]];
//                 } else {
//                     maxCycle = max(maxCycle, cycleLength);
//                 }
//             }
//         }

//         return max(maxCycle, chains);
//     }
// };