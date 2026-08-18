class Solution {
public:

    bool vis[101][101];
    int N,M;

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int ans = 1;
    vector<vector<int>>dp;

    int dfs(vector<vector<int>>& mtx, int x, int y, int len){
      if(dp[x][y] != -1) return dp[x][y];
      int res = 1;
      //ans = max(ans,len);

      for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx<0 || nx>=N || ny<0 || ny>=M  || mtx[nx][ny]<=mtx[x][y])
         continue;

        res = max(res, 1+ dfs(mtx,nx,ny,len+1));
        
      }

      return dp[x][y] = res;
     
    }
    
    int longestIncreasingPath(vector<vector<int>>& mtx) {

      int n = mtx.size();
      int m = mtx[0].size();
      N=n,M=m;
      dp.resize(n+1,vector<int>(m+1,-1));
      
      for(int i =0;i<n;i++)
      {
        for(int j=0;j<m;j++){
          ans = max(ans,dfs(mtx, i,j,1));  
        }
      }

      return ans;
        
    }
};
