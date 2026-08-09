class Solution {
public:
    vector< vector<int> > adj;
    vector<bool> vis;

    void dfs(int node){
        vis[node] = 1;

        for(auto child : adj[node]){
            if(!vis[child]) dfs(child);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n+1);
        vis.resize(n+1,0);

        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
         
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }

        return ans;

 }
};
