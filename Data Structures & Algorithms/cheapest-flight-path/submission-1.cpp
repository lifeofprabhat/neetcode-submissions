class Solution {
public:
     vector< pair<int,int> > adj[101];
     int ans = INT_MAX ;
     bool vis[100] = {0};
     int DST,K;

     void dfs(int node, int fl, int cost){
        if(fl > K+1 || cost>= ans) return ;
        if(node == DST) {ans = min(ans,cost); return; }
        vis[node] = 1;

        for(auto [next, d] : adj[node]){
            if(!vis[next]){
                dfs(next, fl+1, cost+d);
            }
        }

        vis[node] = 0;

     }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      DST = dst;
      K=k;
      for(auto& f : flights){
        adj[f[0]].push_back({f[1],f[2]});
      }

     dfs(src,0,0);

     if(ans!= INT_MAX) return ans;
     return -1;
        
    }
};
