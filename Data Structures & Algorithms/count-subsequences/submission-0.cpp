class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(string& s, string& t, int x, int y){
      if(y==t.size()){
        return 1;
      }
      if(s.size()==x) return 0;

      if(dp[x][y] != -1) return dp[x][y];

      int ans = 0;

      if(s[x]==t[y])
        ans += solve(s,t,x+1, y+1);

      ans += solve(s,t,x+1,y);

      return dp[x][y]=ans;

    }
    int numDistinct(string s, string t) {
     dp.resize(s.size()+1, vector<int>(t.size()+1, -1));

     return solve(s,t,0,0);
        
    }
};
