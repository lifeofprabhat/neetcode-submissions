class Solution {
public:
    vector< vector<pair<int,int> > >adj;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    adj.resize(n+1);

    for(auto v : times){
        adj[v[0]].push_back({v[1],v[2]});
        //adj[v[1]].push_back({v[0],v[2]});
    }
    
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >q;

    vector<int> dist(n+1, INT_MAX);

    dist[k] = 0;
    q.push({0,k});

    while(!q.empty()){
        auto [curr_d, node] = q.top();
        q.pop();
        
        for(auto [child , d] : adj[node]){
            if(dist[child] > curr_d + d){
                dist[child] = curr_d + d;
                q.push({dist[child], child});
            }
        }
    }
   
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(dist[i]== INT_MAX) return -1;
        ans = max(ans, dist[i]);
    }
    
   return ans;
        
    }
};
