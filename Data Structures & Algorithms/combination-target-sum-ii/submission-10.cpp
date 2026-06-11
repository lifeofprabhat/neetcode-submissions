class Solution {
public:
    set<vector<int>> ans;
    void solve(int idx, int rem, vector<int>& tmp, vector<int>& nums){
        if(rem==0){ ans.insert(tmp); return;}
        else if(rem <0 || idx >= nums.size()){return;}
       
        tmp.push_back(nums[idx]);
        solve(idx+1,rem-nums[idx],tmp,nums);
        tmp.pop_back();
        while(idx+1<nums.size() && nums[idx]==nums[idx+1]) idx++;
        solve(idx+1,rem,tmp,nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        map<int, int> mp;
        vector<int> curr2;
        for(auto x : nums)
        {
            //if(curr2.size() && curr2.back() == x) continue;
            mp[x]++;
            if(mp[x]*x > target) continue;
            curr2.push_back(x);
        }
        nums = curr2;
        
        vector<int>tmp;
        solve(0,target,tmp,nums);
        vector<vector<int>> vv(ans.begin(),ans.end());

        return vv;        
    }
};
