class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
      vector<int> dp(amt+1, INT_MAX);
      dp[0] = 0;
      for(int i=1;i<=amt;i++){
         for(auto c : coins)
           if(i-c>=0 && dp[i-c] != INT_MAX){
              dp[i] = min(dp[i], dp[i-c]+1);
           }
      }

      if(dp[amt] == INT_MAX) return -1;
      return dp[amt];
        
    }
};
