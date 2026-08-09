class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> adj;
    bool ok = true;
    bool dfs(int node, int par){
        vis[node] = 1;

        for(auto child : adj[node]){
            if(!vis[child])
               dfs(child, node);
            else if(vis[child] && child != par){
                ok = false;
                return false;
            }
        }
      return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        adj.resize(n+1);
        vis.resize(n+1,0);

        for(auto v : edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        dfs(0,-1);

        for(int i=0;i<n;i++)
          if(!vis[i]) return 0;

        return ok;

    }
};
