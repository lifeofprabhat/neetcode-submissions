class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      set<vector<int>> st;
      for(int i=0;i<(1<<n);i++){
        vector<int>tmp;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                tmp.push_back(nums[j]);
            }
        }
        st.insert(tmp);
      }

     vector<vector<int>> ans(st.begin(),st.end());
     return ans;   
    }
};
