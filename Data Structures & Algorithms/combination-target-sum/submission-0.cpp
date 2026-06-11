class Solution {
public:
    vector<vector<int>> ans; 
    void solve(int idx, int rem, vector<int> tmp, vector<int>& nums){
        if(rem==0) {ans.push_back(tmp); return;}
        else if(rem<0 || idx >= nums.size()) return;
        solve(idx+1, rem, tmp, nums);
        tmp.push_back(nums[idx]);
        solve(idx, rem-nums[idx], tmp, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>tmp;
        solve(0,target,tmp,nums);
        return ans;
        
    }
};
