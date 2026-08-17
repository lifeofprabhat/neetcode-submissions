class Solution {
public:
    bool canPartition(vector<int>& nums) {

      int sum = 0;
      for(auto x : nums) sum += x;
      if(sum%2) return 0;

      int n = nums.size();

      vector<vector<int>>dp(n+2,vector<int>(sum/2+1,0));

      for(int i=0;i<=n;i++) dp[i][0] = 1;

      for(int j=1;j<=sum/2;j++){
        for(int i=1;i<=n;i++){
          dp[i][j] = dp[i-1][j];
          if(!dp[i][j] && j>=nums[i-1]){
            dp[i][j] = max(dp[i][j], dp[i-1][j-nums[i-1]]);
          }
        }
      }
        
      return dp[n][sum/2];
    }
};
