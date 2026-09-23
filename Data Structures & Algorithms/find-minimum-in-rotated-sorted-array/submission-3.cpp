class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if(nums[n-1]>=nums[0]) return nums[0];

        if(n==2) return min(nums[0],nums[1]);

        int l = 0, r = n;
        // 2 3 4 1
        int ans  = 0;
        while(l+1<r){
            int mid = (l+r)/2;
            if(nums[mid]>nums[0]){
                l = mid;
            }
            else {
                if(mid && nums[mid-1]>nums[mid]) ans = nums[mid];
                r = mid;
            }
            cout<<mid<<endl;
        }

        return ans;
        
    }
};
