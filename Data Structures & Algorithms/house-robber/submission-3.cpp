class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);

        dp[0] = nums[0];
        if(n==1) return nums[0];

        dp[1] = max(nums[1], dp[0]);
        

        for(int i=2;i<n;i++){
            dp[i] = dp[i-1];
            dp[i] = max(dp[i], dp[i-2]+nums[i]);
        }

        return max(dp[n-1],dp[n-2]);
        
    }
};
