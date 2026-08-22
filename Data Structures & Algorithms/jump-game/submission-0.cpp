class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        int mxr = 0;
        for(int i=0;i<n;i++){
            if(mxr<i) return 0;
            mxr = max(mxr,i+nums[i]);
        }

        return 1;
        
    }
};
