class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();

      vector<int>dp(n+1,INT_MAX);
      dp[0] = INT_MIN;
      dp[1] = nums[0];

      for(int i=1;i<n;i++){
        int idx = upper_bound(dp.begin(), dp.end(), nums[i]) -dp.begin();
        //cout<<i<<" "<<dp[idx-1]<<" "<<nums[i]<<endl;
        if(dp[idx-1]< nums[i] && dp[idx]> nums[i]){
          dp[idx] = nums[i];
        }
      }

      for(int i=n;i>0;i--)
       if(dp[i] != INT_MAX) return i;

       return 1;
        
    }
};
