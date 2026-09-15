class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int T) {
        int l = 0;
        int r = nums.size()-1;

        while(l<r){
            if(nums[l]+nums[r]>T) r--;
            else if(nums[l]+nums[r]<T) l++;
            else{
                return {l+1,r+1};
            }
        }
      return {};
        
    }
};
