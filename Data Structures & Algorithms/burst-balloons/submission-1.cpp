class Solution {
public:

   vector<vector<int>> dp;

   int solve(vector<int>& nums, int l, int r){
     if(l>r) return 0;
     if(dp[l][r] != -1) return dp[l][r];
     int mx  = 0;
     for(int i=l;i<=r;i++){
      int x = nums[l-1]*nums[i]*nums[r+1];
      x += solve(nums,l,i-1) + solve(nums,i+1,r);
      mx = max(mx,x);
     }

     return dp[l][r] = mx;

   }
   
    int maxCoins(vector<int>& nums) {
      int n = nums.size();
      vector<int> ar;
      ar.push_back(1);
      for(int x : nums) ar.push_back(x);
      ar.push_back(1);

      dp.resize(n+2,vector<int>(n+2,-1));

      return solve(ar, 1 , n);

        
    }
};
