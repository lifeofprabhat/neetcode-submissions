class Solution {
public:
    set<vector<int>> st;
    void solve(vector<int>& tmp, int idx, vector<int>&nums){
        if(idx == nums.size()){
            st.insert(tmp);
            return;
        }

        //take
        tmp.push_back(nums[idx]);
        solve(tmp, idx+1, nums);
        tmp.pop_back();

        //don't take
        solve(tmp, idx+1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<int> tmp;
      solve(tmp,0, nums);
     vector<vector<int>>ans(st.begin(),st.end());
     return ans;   
    }
};
