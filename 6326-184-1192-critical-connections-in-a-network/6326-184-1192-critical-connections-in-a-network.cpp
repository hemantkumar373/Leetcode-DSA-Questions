class Solution {
private:
    void dfs(int node, int parent, vector<int>& disc, vector<int>& low, vector<vector<int>>& adj, 
            vector<int>& vis, vector<vector<int>>& bridges, int time) {
        vis[node] = 1;
        disc[node] = low[node] = time;
        time++;
        
        for(auto &it : adj[node]) {
            if(it == parent) continue;
            if(vis[it] == 0) {
                dfs(it, node, disc, low, adj, vis, bridges, time);
                low[node] = min(low[it], low[node]);

                if(low[it] > disc[node]) {
                    bridges.push_back({node, it});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int time = 1;
        vector<int> vis(n, 0), disc(n, 0), low(n, 0);
        vector<vector<int>> bridges;
        dfs(0, -1, disc, low, adj, vis, bridges, time);
        return bridges;
    }
};