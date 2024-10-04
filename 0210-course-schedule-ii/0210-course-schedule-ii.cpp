class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<int> inDegree(N, 0);
        vector<int> adj[N];
        
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }
        
        queue<int> q;
        for(int i=0; i<N; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        if(ans.size() == N) return ans;
        return {};
    }
};