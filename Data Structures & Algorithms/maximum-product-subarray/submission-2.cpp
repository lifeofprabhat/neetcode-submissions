class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int ans = -11;

      vector<int> dp;

      for(auto x : nums){
        ans = max(ans, x);
        if(x == 1)  continue;
        if(x == 0){
          if(dp.size()&& dp.back()==0)
             continue;
          else{
            dp.push_back(0);
            continue;
          }
        }
        if(abs(x) > 1) dp.push_back(x);
        if(x== -1){
          if(dp.size() && abs(dp.back())>1) {dp.push_back(x);  continue;}
          int n = dp.size();
          if(n>1){
            if(dp[n-2]== -1 && dp[n-1]== -1)
                dp.pop_back();
            else
               dp.push_back(-1);
          }
          else dp.push_back(-1);
        }
      }

      for(int i=0;i<dp.size();i++){
        int ans1 = 1;
        for(int j=i;j<min(i+60,(int)dp.size());j++){
          ans1 *= dp[j];
          ans = max(ans, ans1);
        }
      }

      return ans;
        
    }
};
