class Solution {
public:
    
    vector<vector<int>>dp;
    int solve(string& s, string& t, int x, int y){
      if(x==s.size() && y==t.size())
       return 0;
      if(x==s.size() || y==t.size() ){
        return max(s.size()-x, t.size()-y);
      }

      if(dp[x][y] != -1)
         return dp[x][y];
      int yy=1e5;
      if(s[x]==t[y]){
         yy = solve(s,t,x+1,y+1);
      }

      int xx = 1 + solve(s,t,x+1,y); //delete
      int xy = 1 + solve(s,t,x,y+1); //insert
      int xz = 1 + solve(s,t,x+1,y+1); //replace

      return dp[x][y]=min({xx,xy,xz,yy});

    }
    int minDistance(string s, string t) {
        dp.resize(101, vector<int>(101,-1));
        return solve(s,t,0,0);
    }
};
