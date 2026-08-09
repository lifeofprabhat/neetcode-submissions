class Solution {
public:
    void solve(vector<vector<char>>& g) {

        int n = g.size();
        int m = g[0].size();
        
        queue<pair<int,int>> q;

        for(int j = 0;j<m;j++){
            if(g[0][j] == 'O')
              q.push({0,j});
            if(g[n-1][j] == 'O')
              q.push({n-1,j});
        }

        for(int i =1;i<n-1;i++){
            if(g[i][0] == 'O')
              q.push({i,0});
            if(g[i][m-1] == 'O')
               q.push({i,m-1});   
        }

        vector<vector<bool>> vis(n,vector<bool>(m,0));

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            vis[x][y] = 1;

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && g[nx][ny]=='O')
                  q.push({nx,ny});
            }
        }

        for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
            if(g[i][j]=='O' && !vis[i][j])
                g[i][j] = 'X';


      return ;
        
    }
};
