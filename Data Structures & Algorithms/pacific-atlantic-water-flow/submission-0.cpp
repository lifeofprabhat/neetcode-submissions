class Solution {
public:
    void bfs(vector<vector<int>>& h, vector<vector<bool>>& vis, queue<pair<int,int>>& q){
      int n = h.size();
      int m = h[0].size();  
      int dx[4] = {0,0,1,-1};
      int dy[4] = {1,-1,0,0};

      while(!q.empty()){

        auto [x,y]= q.front();
        vis[x][y] = 1;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && h[nx][ny] >= h[x][y])
                q.push({nx,ny});
        }


      }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        vector< vector<bool> >vis(n, vector<bool>(m,0));

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
            q.push({0,i});

        for(int j=0;j<n;j++)
            q.push({j,0});

        bfs(h,vis,q);

        
        vector< vector<bool> >vis1(n, vector<bool>(m,0));

        for(int i=0;i<m;i++)
            q.push({n-1,i});

        for(int j=0;j<n;j++)
            q.push({j,m-1});

        bfs(h,vis1,q);

        vector<vector<int>> ans;

        for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
             if(vis[i][j] && vis1[i][j])
                 ans.push_back({i,j});


        return ans;
        
    }
};
