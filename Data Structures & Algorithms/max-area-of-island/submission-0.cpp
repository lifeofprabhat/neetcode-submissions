class Solution {
public:

   int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    vector< vector<bool>> vis;
    int n,m;
   
    void dfs(vector<vector<int>>& grid, int x, int y, int& cnt){
        vis[x][y] = 1;

        for(int i =0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny] == 1){
                cnt++;
               dfs(grid, nx, ny,cnt);
            }
        
        }
    }
  
    int maxAreaOfIsland(vector<vector<int>>& grid) {

          n = grid.size();
         m = grid[0].size();

        vis.resize(n, vector<bool>(m,0));

      
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {     int cnt = 1;
                if(grid[i][j] == 1 && !vis[i][j]){
                  dfs(grid, i,j,cnt);
                  ans = max(ans, cnt);
                }
            }
        }

        return ans;
        
    }
};
