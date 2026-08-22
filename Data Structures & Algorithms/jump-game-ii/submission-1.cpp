class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        int mxr = nums[0];
        int steps = 1;
        int curr = nums[0];

        for(int i=1;i<n;i++){
            mxr = max(mxr, i+ nums[i]);
            curr--;
            if(i==n-1) return steps;

            if(!curr){
                steps++;
                curr=mxr-i;
            }
        }

        return steps;
        
    }
};
