class Solution {
public:
    
  
    int findTargetSumWays(vector<int>& nums, int target) {
   
     sort(nums.rbegin(),nums.rend());
     int zero_cnt =0;
     while(nums.size() && nums.back() == 0) {nums.pop_back(); zero_cnt++;}
     int n = nums.size();
     
     int ans = 0;
     for(int i=0;i<(1<<n);i++){
       int sum = 0;
       for(int j=0;j<n;j++){
        if(i&(1<<j))
          sum += nums[j];
        else 
          sum -=nums[j]; 
       }

        if(sum==target) ans++;
     }

       return ans*(1<<zero_cnt); 
    }
};
