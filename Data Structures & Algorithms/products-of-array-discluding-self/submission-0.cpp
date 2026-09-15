class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCnt = 0;
        int prod = 1;
        for(int x : nums){
            if(x && zeroCnt<2) prod*=x;
            if(!x) zeroCnt++;
        }

        vector<int>ans(nums.size(),0);
        if(zeroCnt>1) return ans;

        for(int i=0;i<nums.size();i++)
                ans[i] = zeroCnt==0 ? prod/nums[i] : (nums[i] != 0 ? 0 : prod);
    
    return ans;

    }
};
