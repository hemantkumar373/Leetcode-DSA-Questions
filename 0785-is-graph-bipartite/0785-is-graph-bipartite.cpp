class Solution {
private:
    bool dfs(int node, int col,vector<int>& color, vector<vector<int>>& graph){
        color[node] = col;
        
        for(auto x : graph[node]){
            if(color[x] == -1){
                if(dfs(x,!col,color,graph) == false) return false;
            }
            else if(color[x] == col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(dfs(i,0,color,graph) == false) return false;
            }
        }
        return true;
    }
};